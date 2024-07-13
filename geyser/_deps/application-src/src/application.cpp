// C/C++
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// POSIX C extensions
#include <sys/stat.h>  // mkdir()
#include <unistd.h>    // chdir()

// application
#include "application.hpp"
#include "exceptions.hpp"
#include "globals.hpp"
#include "monitor.hpp"
#include "command_line.hpp"
#include "signal.hpp"

#ifdef MPI_PARALLEL
#include <mpi.h>
#endif

namespace Globals {
clock_t tstart;
int mpi_tag_ub;
}  // namespace Globals
   
std::string stripnonprint(const std::string& s) {
  std::string ss = "";
  for (size_t i = 0; i < s.size(); i++) {
    if (isprint(s[i])) {
      ss += s[i];
    }
  }
  return ss;
}

//! Mutex for creating singletons within the application object
static std::mutex dir_mutex;
static std::mutex app_mutex;

Application::Logger::Logger(std::string name) {
  auto app = Application::GetInstance();

  if (!app->HasMonitor(name)) {
    app->InstallMonitor(name, "stdout", "stderr");
  }

  cur_monitor_ = app->GetMonitor(name);
  cur_monitor_->Enter();
}

Application::Logger::~Logger() { cur_monitor_->Leave(); }

Application::Application() {
  // install a default log_writer that writes to standard
  // output / standard error
  setDefaultDirectories();
}

Application* Application::GetInstance() {
  // RAII
  std::unique_lock<std::mutex> lock(app_mutex);

  if (myapp_ == nullptr) {
    myapp_ = new Application();
  }

  return myapp_;
}

void Application::ChangeRunDir(const char *pdir) {
  std::stringstream msg;

  if (pdir == nullptr || *pdir == '\0') return;

  mkdir(pdir, 0775);
  if (chdir(pdir)) {
    char buf[1024];
    snprintf(buf, 1024, "Cannot cd to directory %s", pdir);
    throw RuntimeError("ChangeRunDir", buf);
  }

  return;
}

void Application::Start(int argc, char** argv) {
  auto cli = CommandLine::ParseArguments(argc, argv);
  auto sig = Signal::GetInstance();

  Globals::tstart = clock();

  if (Globals::my_rank == 0 && cli->wtlim > 0)
    sig->SetWallTimeAlarm(cli->wtlim);

#ifdef MPI_PARALLEL
  if (MPI_SUCCESS != MPI_Init(&argc, &argv)) {
    throw RuntimeError("Start", "MPI initialization failed");
  }

  // Get process id (rank) in MPI_COMM_WORLD
  if (MPI_SUCCESS != MPI_Comm_rank(MPI_COMM_WORLD, &(Globals::my_rank))) {
    throw RuntimeError("Start", "MPI_Comm_rank failed");
  }

  // Get total number of MPI processes (ranks)
  if (MPI_SUCCESS != MPI_Comm_size(MPI_COMM_WORLD, &Globals::nranks)) {
    throw RuntimeError("Start", "MPI_Comm_size failed");
  }

  // Get maximum value of MPI tag
  MPI_Aint *tag_ub_ptr;
  int att_flag;
  MPI_Comm_get_attr(MPI_COMM_WORLD, MPI_TAG_UB, &tag_ub_ptr, &att_flag);
  Globals::mpi_tag_ub = *tag_ub_ptr;

#else  // no MPI
  Globals::my_rank = 0;
  Globals::nranks = 1;
  Globals::mpi_tag_ub = 0;
#endif

  if (Globals::my_rank == 0) {
    std::cout << Globals::banner << std::endl;
  }

  Monitor::Start(); 
}

void Application::Destroy() {
  std::unique_lock<std::mutex> lock(app_mutex);

  auto sig = Signal::GetInstance();
  auto cli = CommandLine::GetInstance();

  if (Globals::my_rank == 0) {
    if (sig->GetSignalFlag(SIGTERM) != 0) {
      std::cout << std::endl << "Terminating on Terminate signal" << std::endl;
    } else if (sig->GetSignalFlag(SIGINT) != 0) {
      std::cout << std::endl << "Terminating on Interrupt signal" << std::endl;
    } else if (sig->GetSignalFlag(SIGALRM) != 0) {
      std::cout << std::endl << "Terminating on wall-time limit" << std::endl;
    } else {
      std::cout << std::endl << "Terminating on success" << std::endl;
    }

    clock_t tstop = clock();
    double cpu_time =
        (tstop > Globals::tstart ? static_cast<double>(tstop - Globals::tstart)
                                 : 1.0) /
        static_cast<double>(CLOCKS_PER_SEC);
    std::cout << "cpu time used  = " << cpu_time << " (s)" << std::endl;
  }


  if (Globals::my_rank == 0 && cli->wtlim > 0)
    sig->CancelWallTimeAlarm();

  if (Application::myapp_ != nullptr) {
    delete Application::myapp_;
    Application::myapp_ = nullptr;
  }

  CommandLine::Destroy();
  Signal::Destroy();
}

bool Application::InstallMonitor(std::string const& mod,
                                 std::string const& log_name,
                                 std::string const& err_name) {
  if (mymonitor_.count(mod)) {
    mymonitor_[mod]->SetLogOutput(log_name);
    mymonitor_[mod]->SetErrOutput(err_name);
  } else {
    auto monitor = std::make_unique<Monitor>(mod);
    monitor->SetLogOutput(log_name);
    monitor->SetErrOutput(err_name);
    mymonitor_.insert({mod, std::move(monitor)});
  }

  mymonitor_[mod]->Log("Installing monitor " + mod);

  return true;
}

void Application::setDefaultDirectories() {
  // always look in the local directory first
  input_dirs_.push_back(".");

#ifdef WINDOWS
  std::string pathsep = ";";
#else
  std::string pathsep = ":";
#endif

  std::string s = std::string(Globals::search_paths);
  size_t start = 0;
  size_t end = s.find(pathsep);
  while (end != std::string::npos) {
    input_dirs_.push_back(s.substr(start, end - start));
    start = end + 1;
    end = s.find(pathsep, start);
  }
  input_dirs_.push_back(s.substr(start, end));
}

void Application::AddResourceDirectory(const std::string& dir) {
  std::unique_lock<std::mutex> dirLock(dir_mutex);
  if (input_dirs_.empty()) {
    setDefaultDirectories();
  }
  std::string d = stripnonprint(dir);

  // Expand "~/" to user's home directory, if possible
  if (d.find("~/") == 0 || d.find("~\\") == 0) {
    char* home = getenv("HOME");  // POSIX systems
    if (!home) {
      home = getenv("USERPROFILE");  // Windows systems
    }
    if (home) {
      d = home + d.substr(1, std::string::npos);
    }
  }

  // Remove any existing entry for this directory
  auto iter = std::find(input_dirs_.begin(), input_dirs_.end(), d);
  if (iter != input_dirs_.end()) {
    input_dirs_.erase(iter);
  }

  // Insert this directory at the beginning of the search path
  input_dirs_.insert(input_dirs_.begin(), d);
}

std::string Application::FindResource(const std::string& name) {
  std::unique_lock<std::mutex> dirLock(dir_mutex);
  std::string::size_type islash = name.find('/');
  std::string::size_type ibslash = name.find('\\');
  std::string::size_type icolon = name.find(':');
  std::vector<std::string>& dirs = input_dirs_;

  // Expand "~/" to user's home directory, if possible
  if (name.find("~/") == 0 || name.find("~\\") == 0) {
    char* home = getenv("HOME");  // POSIX systems
    if (!home) {
      home = getenv("USERPROFILE");  // Windows systems
    }
    if (home) {
      std::string full_name = home + name.substr(1, std::string::npos);
      std::ifstream fin(full_name);
      if (fin) {
        return full_name;
      } else {
        throw NotFoundError("FindResource", "Resource " + name);
      }
    }
  }

  // If this is an absolute path, just look for the file there
  if (islash == 0 || ibslash == 0 ||
      (icolon == 1 && (ibslash == 2 || islash == 2))) {
    std::ifstream fin(name);
    if (fin) {
      return name;
    } else {
      throw NotFoundError("FindResource", "Resource " + name);
    }
  }

  // Search the data directories for the input file, and return
  // the full path if a match is found
  size_t nd_ = dirs.size();
  for (size_t i = 0; i < nd_; i++) {
    std::string full_name = dirs[i] + "/" + name;
    std::ifstream fin(full_name);
    if (fin) {
      return full_name;
    }
  }
  std::string msg = "\nResource " + name + " not found in director";
  msg += (nd_ == 1 ? "y " : "ies ");
  for (size_t i = 0; i < nd_; i++) {
    msg += "\n'" + dirs[i] + "'";
    if (i + 1 < nd_) {
      msg += ", ";
    }
  }
  msg += "\n\n";
  msg += "To fix this problem, either:\n";
  msg += "    a) move the missing files into the local directory;\n";
  msg += "    b) define -DMYPATH= during build\n";
  throw NotFoundError(msg);
}

std::string Application::GetResourceDirectories(const std::string& sep) {
  std::stringstream ss;
  for (size_t i = 0; i < input_dirs_.size(); ++i) {
    if (i != 0) {
      ss << sep;
    }
    ss << input_dirs_[i];
  }
  return ss.str();
}

// void Application::SearchPythonVersions(const string& versions) {
//     ba::split(m_pythonSearchVersions, versions, ba::is_any_of(","));
// }

Application* Application::myapp_ = nullptr;
// MonitorMap Application::mymonitor_ = {};

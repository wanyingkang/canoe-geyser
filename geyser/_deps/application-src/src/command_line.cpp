// C/C++
#include <cstring>
#include <iostream>
#include <memory>
#include <mutex>

// application
#include "exceptions.hpp"
#include "globals.hpp"
#include "command_line.hpp"

#ifdef MPI_PARALLEL
#include <mpi.h>
#endif

static std::mutex cli_mutex;
extern int Globals::my_rank;
extern int Globals::nranks;

CommandLine::CommandLine(int argc, char** argv):
  input_filename(nullptr),
  restart_filename(nullptr),
  prundir(nullptr),
  res_flag(0),
  narg_flag(0),
  iarg_flag(0),
  mesh_flag(0),
  wtlim(0),
  argc(0),
  argv(nullptr)
{}

void CommandLine::Destroy() {
  if (CommandLine::mycli_ != nullptr) {
    delete CommandLine::mycli_;
    CommandLine::mycli_ = nullptr;
  } 
}

CommandLine* CommandLine::GetInstance() {
  if (CommandLine::mycli_ == nullptr) {
    throw RuntimeError("CommandLine", 
        "GetInstance() called before ParseArguments()");
  }

  return mycli_;
}

CommandLine* CommandLine::ParseArguments(int argc, char** argv) {
  // RAII
  std::unique_lock<std::mutex> lock(cli_mutex);

  mycli_ = new CommandLine(argc, argv);

  mycli_->argc = argc;
  mycli_->argv = argv;

  for (int i = 1; i < argc; i++) {
    // If argv[i] is a 2 character string of the form "-?" then:
    if (*argv[i] == '-' && *(argv[i] + 1) != '\0' && *(argv[i] + 2) == '\0') {
      // check validity of command line options + arguments:
      char opt_letter = *(argv[i] + 1);
      switch (opt_letter) {
        // options that do not take arguments:
        case 'n':
        case 'c':
        case 'h':
          break;
          // options that require arguments:
        default:
          if ((i + 1 >= argc)  // flag is at the end of the command line options
              || (*argv[i + 1] == '-')) {  // flag is followed by another flag
            if (Globals::my_rank == 0) {
              throw RuntimeError("CommandLine", std::to_string(opt_letter) + 
                  " must be followed by a valid argument");
            }
          }
      }
      switch (*(argv[i] + 1)) {
        case 'i':  // -i <input_filename>
          mycli_->input_filename = argv[++i];
          mycli_->iarg_flag = 1;
          break;
        case 'r':  // -r <restart_file>
          mycli_->res_flag = 1;
          mycli_->restart_filename = argv[++i];
          break;
        case 'd':  // -d <run_directory>
          mycli_->prundir = argv[++i];
          break;
        case 'n':
          mycli_->narg_flag = 1;
          break;
        case 'm':  // -m <nproc>
          mycli_->mesh_flag = static_cast<int>(std::strtol(argv[++i], nullptr, 10));
          break;
        case 't':  // -t <hh:mm:ss>
          int wth, wtm, wts;
          std::sscanf(argv[++i], "%d:%d:%d", &wth, &wtm, &wts);
          mycli_->wtlim = wth * 3600 + wtm * 60 + wts;
          break;
        case 'c':
          // if (Globals::my_rank == 0) ShowConfig();
#ifdef MPI_PARALLEL
          MPI_Finalize();
#endif
          return mycli_;
          break;
        case 'h':
        default:
          if (Globals::my_rank == 0) {
            std::cout << "Usage: " << argv[0]
                      << " [options] [block/par=value ...]\n";
            std::cout << "Options:" << std::endl;
            std::cout << "  -i <file>       specify input file\n";
            std::cout << "  -r <file>       restart with this file\n";
            std::cout << "  -d <directory>  specify run dir [current dir]\n";
            std::cout << "  -c              show configuration and quit\n";
            std::cout << "  -t hh:mm:ss     wall time limit for final output\n";
            std::cout << "  -h              this help\n";
            // ShowConfig();
          }
#ifdef MPI_PARALLEL
          MPI_Finalize();
#endif
          return mycli_;
          break;
      }
    }  // else if argv[i] not of form "-?" ignore it here (tested in
       // ModifyFromCmdline)
  }

  return mycli_;
}

CommandLine* CommandLine::mycli_ = nullptr;

#ifndef SRC_APPLICATION_HPP_
#define SRC_APPLICATION_HPP_

// C/C++
#include <memory>
#include <string>
#include <vector>
#include <cstdint>

// application
#include "monitor.hpp"

//! Strip non-printing characters wherever they are
/*!
 * @param s        Input string
 * @returns a copy of the string, stripped of all non- printing characters.
 */
std::string stripnonprint(const std::string& s);

class Application {
 protected:
  //! Constructor for class sets up the initial conditions
  //! Protected ctor access thru static member function Instance
  Application();

 public:
  class Logger {
   public:
    explicit Logger(std::string name);
    ~Logger();

    //! Provide a pointer dereferencing overloaded operator
    /*!
     * @returns a pointer to Monitor
     */
    Monitor* operator->() { return cur_monitor_; }

   protected:
    Monitor* cur_monitor_;
  };

  //! Return a pointer to the one and only instance of class Application
  /*!
   * If the Application object has not yet been created, it is created
   */
  static Application* GetInstance();

  size_t CountMonitors() { return mymonitor_.size(); }

  bool HasMonitor(std::string const& name) {
    return mymonitor_.count(name) > 0;
  }

  Monitor* GetMonitor(std::string const& name) {
    return mymonitor_[name].get();
  }

  bool InstallMonitor(std::string const& name, std::string const& log_name,
                      std::string const& err_name);

  //! Destructor for class deletes global data
  virtual ~Application() {}

  //! Static function that starts section counter
  static void Start(int argc, char** argv);

  //! Static function that destroys the application class's data
  static void Destroy();

  //!  Add a directory to the data file search path.
  /*!
   * @ingroup resource
   *
   * @param dir  String name for the directory to be added to the search path
   */
  void AddResourceDirectory(const std::string& dir);

  //! Find a resource file.
  /*!
   * This routine will search for a file in the default locations specified
   * for the application. See the routine setDefaultDirectories() listed
   * above. The first directory searched is usually the current working
   * directory.
   *
   * The default set of directories will not be searched if an absolute path
   * (for example, one starting with `/` or `C:\`) or a path relative to the
   * user's home directory (for example, starting with `~/`) is specified.
   *
   * The presence of the file is determined by whether the file can be
   * opened for reading by the current user.
   *
   * @param name Name of the input file to be searched for
   * @return  The absolute path name of the first matching file
   *
   * If the file is not found an exception is thrown.
   *
   * @ingroup resource
   */
  std::string FindResource(const std::string& name);

  //! Get the data directories
  /*!
   * This routine returns a string including the names of all the
   * directories searched for data files.
   *
   * @param sep Separator to use between directories in the string
   * @return A string of directories separated by the input sep
   *
   * @ingroup resource
   */
  std::string GetResourceDirectories(const std::string& sep);

  //! Set the versions of Python to try when loading user-defined extensions,
  //! in order of preference. Separate multiple versions with commas, for
  //! example
  //! `"3.11,3.10"`.
  void SearchPythonVersions(const std::string& versions);

  //! Print a warning indicating that *method* is deprecated. Additional
  //! information (removal version, alternatives) can be specified in
  //! *extra*. Deprecation warnings are printed once per method per
  //! invocation of the application.
  void WarnDeprecated(std::string_view method, const std::string& extra = "");

  //! Globally disable printing of deprecation warnings. Used primarily to
  //! prevent certain tests from failing.
  void SuppressDeprecationWarnings() {
    suppress_deprecation_warnings_ = true;
    fatal_deprecation_warnings_ = false;
  }

  //! Turns deprecation warnings into exceptions. Activated within the test
  //! suite to make sure that no deprecated methods are being used.
  void MakeDeprecationWarningsFatal() { fatal_deprecation_warnings_ = true; }

  //! Globally disable printing of (user) warnings. Used primarily to
  //! prevent certain tests from failing.
  void SuppressWarnings() {
    suppress_warnings_ = true;
    fatal_warnings_ = false;
  }

  //! Returns `true` if warnings should be suppressed.
  bool IsWarningsSuppressed() { return suppress_warnings_; }

  //! Turns warnings into exceptions. Activated within the test
  //! suite to make sure that your warning message are being raised.
  void MakeWarningsFatal() { fatal_warnings_ = true; }

  bool HasDevice(std::string const& name) { return mydevice_.count(name) > 0; }

  DevicePtr GetDevice(std::string const& name) { return mydevice_[name]; }

  void InstallDevice(std::string const& name, DevicePtr device) {
    mydevice_.insert({name, device});
  }

  static void ChangeRunDir(const char *pdir);

 protected:
  //! Set the default directories for input files.
  /*!
   * Searches for input files along a path that includes platform-
   * specific default locations, and possibly user-specified locations.
   * This function installs the platform-specific directories on the search
   * path. It is invoked at startup by appinit(), and never should need to
   * be called by user programs.
   *
   * The current directory (".") is always searched first.
   *
   * Additional directories may be added by calling function AddDirectory.
   */
  void setDefaultDirectories();

  //! Current vector of input directories to search for input files
  std::vector<std::string> input_dirs_;

  //! Versions of Python to consider when attempting to load user extensions
  std::vector<std::string> python_versions_ = {"3.11", "3.10", "3.9", "3.8"};

  bool suppress_deprecation_warnings_ = false;
  bool fatal_deprecation_warnings_ = false;
  bool suppress_warnings_ = false;
  bool fatal_warnings_ = false;

  MonitorMap mymonitor_;
  DeviceMap mydevice_;

 private:
  //! Pointer to the single Application instance
  static Application* myapp_;
};

#endif  // SRC_APPLICATION_HPP_

#ifndef SRC_MONITOR_HPP_
#define SRC_MONITOR_HPP_

// C/C++
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class Monitor {
 protected:
  //! Protected ctor access thru static member function Instance

 public:
  explicit Monitor(std::string name) : name_(name) {}

  //! Destructor - empty
  virtual ~Monitor() {}

  //! Write a log message to the log device
  /*!
   * End-of-line character is appended to the message.
   *
   * @param msg      String message to be written to cout
   */
  virtual void Log(std::string const& msg);

  template <typename T>
  void Log(std::string const& msg, T const& a);

  template <typename T>
  void Log(std::string const& msg, T* a, int n);

  template <typename T>
  void Log(std::string const& msg, std::vector<T> const& a);

  //! Write an error message to the error device
  /*!
   * End-of-line character is not appended to the message.
   *
   * @param msg      String message to be written to cout
   */
  virtual void Error(std::string const& msg, int code = 0);

  //! Write a warning message to the log device
  /*!
   * End-of-line character is appended to the message.
   *
   * @param msg     String message to be written to cout
   */
  virtual void Warn(std::string const& msg, int code = 0);

  template <typename T>
  void Check(T const& val, double vmin, double max);

  void Enter();

  void Leave();

  bool SetLogOutput(std::string const& fname);

  bool SetErrOutput(std::string const& fname);

  static void Start();

 protected:
  virtual std::string getTimeStamp() const;

  virtual std::string getSectionID() const;

  static void advance();

  std::shared_ptr<std::ostream> log_device_;
  std::shared_ptr<std::ostream> err_device_;

  std::string name_;

  static std::vector<uint32_t> sections_;
};

using MonitorPtr = std::unique_ptr<Monitor>;

using MonitorMap = std::map<std::string, MonitorPtr>;

using DevicePtr = std::shared_ptr<std::ostream>;

using DeviceMap = std::map<std::string, DevicePtr>;

template <typename T>
void Monitor::Log(std::string const& msg, T const& a) {
  advance();
  char buf[880];
  snprintf(buf, sizeof(buf), "Log, %s, %12s, %s, ", getTimeStamp().c_str(),
           name_.c_str(), getSectionID().c_str());
  (*log_device_) << buf << "\"" << msg << " = " << a << "\"\n";
}

template <typename T>
void Monitor::Log(std::string const& msg, T* a, int n) {
  advance();
  char buf[880];
  snprintf(buf, sizeof(buf), "Log, %s, %12s, %s, ", getTimeStamp().c_str(),
           name_.c_str(), getSectionID().c_str());
  (*log_device_) << buf << "\"" << msg << " = ";
  for (int i = 0; i < n; ++i) (*log_device_) << a[i] << " ";
  (*log_device_) << "\"\n";
}

template <typename T>
void Monitor::Log(std::string const& msg, std::vector<T> const& a) {
  advance();
  char buf[880];
  snprintf(buf, sizeof(buf), "Log, %s, %12s, %s, ", getTimeStamp().c_str(),
           name_.c_str(), getSectionID().c_str());
  (*log_device_) << buf << "\"" << msg << " = ";
  for (size_t i = 0; i < a.size(); ++i) (*log_device_) << a[i] << " ";
  (*log_device_) << "\"\n";
}

#endif  // SRC_MONITOR_HPP_

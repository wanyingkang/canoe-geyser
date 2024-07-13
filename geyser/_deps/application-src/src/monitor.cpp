// C/C++
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>

// application
#include "application.hpp"
#include "monitor.hpp"

struct NullDeleter {
  void operator()(void const*) const {}
};

static std::mutex section_mutex;

void Monitor::Log(std::string const& msg) {
  advance();
  char buf[880];
  snprintf(buf, sizeof(buf), "Log, %s, %12s, %s, \"%s\"\n",
           getTimeStamp().c_str(), name_.c_str(), getSectionID().c_str(),
           msg.c_str());
  (*log_device_) << buf;
}

void Monitor::Error(std::string const& msg, int code) {
  advance();
  char buf[880];
  snprintf(buf, sizeof(buf), "Error, %s, %12s, %s, \"%s\", %d\n",
           getTimeStamp().c_str(), name_.c_str(), getSectionID().c_str(),
           msg.c_str(), code);
  (*err_device_) << buf;
}

void Monitor::Warn(std::string const& msg, int code) {
  advance();
  char buf[880];
  snprintf(buf, sizeof(buf), "Warn, %s, %12s, %s, \"%s\", %d\n",
           getTimeStamp().c_str(), name_.c_str(), getSectionID().c_str(),
           msg.c_str(), code);
  (*log_device_) << buf;
}

void Monitor::Enter() {
  std::unique_lock<std::mutex> lock(section_mutex);

  sections_.push_back(0);
}

void Monitor::Leave() {
  std::unique_lock<std::mutex> lock(section_mutex);

  sections_.pop_back();
  if (sections_.size() > 0) sections_.back() += 1;
}

bool Monitor::SetLogOutput(std::string const& fname) {
  auto app = Application::GetInstance();

  if (app->HasDevice(fname)) {
    log_device_ = app->GetDevice(fname);
  } else {
    if (fname == "stdout") {
      log_device_ = std::shared_ptr<std::ostream>(&std::cout, NullDeleter());
    } else {
      log_device_ = std::make_shared<std::ofstream>(fname, std::ios::out);
    }
    app->InstallDevice(fname, log_device_);
  }

  return true;
}

bool Monitor::SetErrOutput(std::string const& fname) {
  auto app = Application::GetInstance();

  if (app->HasDevice(fname)) {
    err_device_ = app->GetDevice(fname);
  } else {
    if (fname == "stderr") {
      err_device_ = std::shared_ptr<std::ostream>(&std::cerr, NullDeleter());
    } else {
      err_device_ = std::make_shared<std::ofstream>(fname, std::ios::out);
    }
    app->InstallDevice(fname, err_device_);
  }

  return true;
}

std::string Monitor::getTimeStamp() const {
  std::time_t current_time = std::time(nullptr);
  char time_stamp[880];
  std::strftime(time_stamp, sizeof(time_stamp), "\"%Y-%m-%d %H:%M:%S\"",
                std::localtime(&current_time));
  return time_stamp;
}

std::string Monitor::getSectionID() const {
  if (sections_.size() == 0) {
    return "0.";
  } else {
    std::string str;
    for (auto i : sections_) {
      str += std::to_string(i) + '.';
    }
    return str;
  }
}

void Monitor::Start() {
  std::unique_lock<std::mutex> lock(section_mutex);

  sections_.clear();
  sections_.push_back(1);
}

void Monitor::advance() {
  std::unique_lock<std::mutex> lock(section_mutex);

  if (sections_.size() != 0) {
    sections_.back() += 1;
  } else {
    sections_.push_back(1);
  }
}

std::vector<uint32_t> Monitor::sections_ = {};

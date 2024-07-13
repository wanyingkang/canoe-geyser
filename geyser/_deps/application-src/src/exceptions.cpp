// C/C++
#include <string>

// application
#include "exceptions.hpp"

static const char* stars =
    ("*****************************************"
     "**************************************\n");

ExceptionBase::ExceptionBase(const std::string& procedure)
    : procedure_(procedure) {}

const char* ExceptionBase::what() const throw() {
  try {
    formatted_message_ = "\n";
    formatted_message_ += stars;
    formatted_message_ += GetClass();
    if (procedure_.size()) {
      formatted_message_ += " thrown by " + procedure_;
    }
    formatted_message_ += ":\n" + GetMessage();
    if (formatted_message_.compare(formatted_message_.size() - 1, 1, "\n")) {
      formatted_message_.append("\n");
    }
    formatted_message_ += stars;
  } catch (...) {
    // Not able to format the message
  }
  return formatted_message_.c_str();
}

std::string ExceptionBase::GetMessage() const { return msg_; }

std::string ExceptionBase::GetMethod() const { return procedure_; }

std::string ArraySizeError::GetMessage() const {
  char buf[80];
  snprintf(buf, sizeof(buf),
           "Array size (%lu) too small. Must be at least %lu.", sz_, reqd_);
  return buf;
}

std::string IndexError::GetMessage() const {
  char buf[80];
  snprintf(buf, sizeof(buf),
           "IndexError: %s[%lu] outside valid range of 0 to %lu.",
           arrayName_.c_str(), m_, mmax_);
  return buf;
}

std::string ValueError::GetMessage() const {
  char buf[160];
  snprintf(buf, sizeof(buf),
           "RuntimeError: Expect %f but get %f for variable %s.",
           expect_, val_, var_.c_str());
  return buf;
}

#ifndef SRC_EXCEPTIONS_HPP_
#define SRC_EXCEPTIONS_HPP_

// C/C++
#include <exception>
#include <string>

//! Base class for exceptions
/*!
 * This class is the base class for exceptions. It inherits
 * from std::exception so that normal error handling operations from
 * applications may automatically handle the errors in their own way.
 *
 * @ingroup errorhandling
 */
class ExceptionBase : public std::exception {
 public:
  //! Normal Constructor for the ExceptionBase class
  ExceptionBase(const std::string& procedure, const std::string& msg)
      : procedure_(procedure), msg_(msg) {}

  //! Destructor for base class does nothing
  virtual ~ExceptionBase() throw() {}

  //! Get a description of the error
  const char* what() const throw();

  //! Method overridden by derived classes to format the error message
  virtual std::string GetMessage() const;

  //! Get the name of the method that threw the exception
  virtual std::string GetMethod() const;

  //! Method overridden by derived classes to indicate their type
  virtual std::string GetClass() const { return "Exception!"; }

 protected:
  //! Protected default constructor discourages throwing errors containing no
  //! information.
  ExceptionBase() {}

  //! Constructor used by derived classes that override GetMessage()
  explicit ExceptionBase(const std::string& procedure);

  //! The name of the procedure where the exception occurred
  std::string procedure_;
  mutable std::string
      formatted_message_;  //!< Formatted message returned by what()

 private:
  std::string msg_;  //!< Message associated with the exception
};

//! Array size error.
/*!
 * This error is thrown if a supplied length to a vector is
 * too small.
 *
 * @ingroup errorhandling
 */
class ArraySizeError : public ExceptionBase {
 public:
  //! Constructor
  /*!
   * The length needed is supplied by the argument, reqd, and the
   * length supplied is given by the argument sz.
   *
   * @param procedure String name for the function within which the error was
   *             generated.
   * @param sz   This is the length supplied
   * @param reqd This is the required length needed
   */
  ArraySizeError(const std::string& procedure, size_t sz, size_t reqd)
      : ExceptionBase(procedure), sz_(sz), reqd_(reqd) {}

  virtual std::string GetMessage() const;
  virtual std::string GetClass() const { return "ArraySizeError"; }

 private:
  size_t sz_, reqd_;
};

//! An array index is out of range.
/*!
 *  @ingroup errorhandling
 */
class IndexError : public ExceptionBase {
 public:
  //! Constructor
  /*!
   * This class indicates an out-of-bounds array index.
   *
   * @param func String name for the function within which the error was
   *             generated.
   * @param arrayName name of the corresponding array
   * @param m   This is the value of the out-of-bounds index.
   * @param mmax This is the maximum allowed value of the index. The
   *             minimum allowed value is assumed to be 0.
   */
  IndexError(const std::string& func, const std::string& arrayName, size_t m,
             size_t mmax)
      : ExceptionBase(func), arrayName_(arrayName), m_(m), mmax_(mmax) {}

  virtual ~IndexError() throw() {}
  virtual std::string GetMessage() const;
  virtual std::string GetClass() const { return "IndexError"; }

 private:
  std::string arrayName_;
  size_t m_, mmax_;
};

//! An error indicating that an unimplemented function has been called
class NotImplementedError : public ExceptionBase {
 public:
  //! @param func Name of the unimplemented function, such as
  //!     `ClassName::functionName`
  explicit NotImplementedError(const std::string& func)
      : ExceptionBase(func, "Not Implemented.") {}

  virtual std::string GetClass() const { return "NotImplementedError"; }
};

//! An error indicating that a value was not found
class NotFoundError : public ExceptionBase {
 public:
  //! @param func Name of the unimplemented function, such as
  //!     `ClassName::functionName`
  explicit NotFoundError(const std::string& some)
      : ExceptionBase(some, "Not Found.") {}

  NotFoundError(const std::string& func, std::string const& some)
      : ExceptionBase(func, some + " not found.") {}

  virtual std::string GetClass() const { return "NotFoundError"; }
};

//! An error indicating that a value was wrong
class ValueError : public ExceptionBase {
 public:
  ValueError(const std::string& func, std::string const& var,
      double expect, double val)
      : ExceptionBase(func), var_(var), expect_(expect), val_(val) {}

  virtual std::string GetMessage() const;
  virtual std::string GetClass() const { return "ValueError"; }
 protected:
  std::string var_;
  double expect_;
  double val_;
};

//! An general runtime error
class RuntimeError : public ExceptionBase {
 public:
  RuntimeError(const std::string& func, std::string const& msg)
      : ExceptionBase(func, msg) {}

  virtual std::string GetClass() const { return "RuntimeError"; }
};

#endif  // SRC_EXCEPTIONS_HPP_

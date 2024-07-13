#ifndef SRC_SIGNAL_HPP_
#define SRC_SIGNAL_HPP_

// C/C++
#include <csignal>   // sigset_t POSIX C extension
#include <cstdint>   // std::int64_t

class Signal {
protected:
  Signal();

public:
  enum {
    ITERM = 0,
    IINT = 1,
    IALRM = 2,
    NSIGNAL = 3,
  };

  static Signal* GetInstance();
  static void Destroy();
  static void SetSignalFlag(int s);

  int CheckSignalFlags();
  int GetSignalFlag(int s);
  void SetWallTimeAlarm(int t);
  void CancelWallTimeAlarm();

protected:
  static int signalflag_[NSIGNAL];
  sigset_t mask_;

private:
  //! Pointer to the single SingnalHandler instance
  static Signal* mysig_;
};

#endif // SRC_SIGNAL_HPP_

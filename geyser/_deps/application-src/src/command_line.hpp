#ifndef SRC_COMMAND_LINE_HPP_
#define SRC_COMMAND_LINE_HPP_

class CommandLine {
protected:
  CommandLine(int argc, char **argv);

public:
  char *input_filename;
  char *restart_filename;
  char *prundir;
  int res_flag;
  int narg_flag;
  int iarg_flag;
  int mesh_flag;
  int wtlim;
  int argc;
  char **argv;

  static CommandLine *ParseArguments(int argc, char **argv);
  static CommandLine *GetInstance();
  static void Destroy();
  ~CommandLine() {}

private:
  static CommandLine *mycli_;
};

#endif  // SRC_COMMAND_LINE_HPP_

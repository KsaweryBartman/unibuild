#include "cmd.h"

const char *CMD_DISCARD_OUTPUT = " >/dev/null 2>/dev/null";

const char *detect_cmd(const char *cmdlist[], size_t cmdlist_len) {
  for (size_t i = 0; i < cmdlist_len; i++) {
    char cmd[255] = {};
    strcpy(cmd, cmdlist[i]);
    strcat(cmd, " -v");
    strcat(cmd, CMD_DISCARD_OUTPUT);
    int result = system(cmd);
    if (result == 0) {
      return cmdlist[i];
    }
  }
  return NULL;
}

int main(int arg_count, char **arg_array) {
  // Parse all arguments
  struct cmd_arg *args = parse_args(arg_count, arg_array);

  char *c_compiler = get_arg(arg_count, args, "CC");
  char *cpp_compiler = get_arg(arg_count, args, "CXX");
  printf(
      "\n[unibuild]\n\tDetected C Compiler: %s\n\tDetected C++ Compiler: %s\n",
      c_compiler, cpp_compiler);
  if (c_compiler == NULL) {
    const char *c_compilers[] = {
        "cl",
        "clang",
        "gcc",
    };
    const size_t c_compilers_size = sizeof(c_compilers) / sizeof(const char *);
    c_compiler = detect_cmd(c_compilers, c_compilers_size);
    if (c_compiler == NULL) {
      printf("[unibuild error]\nCouldn't automatically detect a C "
             "compiler.\nPlease "
             "define it by hand.\n\tunibuild CC=\"/path/to/c_compiler\"\n");
      return 1;
    }
  }
  if (cpp_compiler == NULL) {
    const char *cpp_compilers[] = {
        "cl",
        // "clang++",
        // "g++",
    };
    const size_t cpp_compilers_size =
        sizeof(cpp_compilers) / sizeof(const char *);
    cpp_compiler = detect_cmd(cpp_compilers, cpp_compilers_size);
    if (cpp_compiler == NULL) {
      printf("[unibuild error]\nCouldn't automatically detect a C++ "
             "compiler.\nPlease "
             "define it by hand.\n\tunibuild CXX=/path/to/cpp_compiler\n");
      return 2;
    }
  }

  printf(
      "\n[unibuild]\n\tDetected C Compiler: %s\n\tDetected C++ Compiler: %s\n",
      c_compiler, cpp_compiler);

  return 0;
}
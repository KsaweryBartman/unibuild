#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_MIN_MAX_FOR_TYPE(t)                                                \
  t t##_max(t a, t b) {                                                        \
    if (a > b)                                                                 \
      return a;                                                                \
    return b;                                                                  \
  }                                                                            \
  t t##_min(t a, t b) {                                                        \
    if (a < b)                                                                 \
      return a;                                                                \
    return b;                                                                  \
  }

DEF_MIN_MAX_FOR_TYPE(size_t);

int main(int argc, char **argv) {
  printf("[unibuild] Hello, Man!\n");

  // Compiler detection
  const char *c_compiler = "gcc";
  const char *cpp_compiler = "g++";
  const char *source_files = "src/main.c";
  const char *output_files = "build/unibuild";

  char *command;

  size_t command_size = size_t_max(strlen(c_compiler), strlen(cpp_compiler)) +
                        strlen(source_files) + strlen(output_files) +
                        strlen("  -o ") + 1;
  command = malloc(command_size);
  memset(command, 0, command_size);
  strcpy(command, c_compiler);
  strcpy(command + strlen(command), " ");
  strcpy(command + strlen(command), source_files);
  strcpy(command + strlen(command), " -o ");
  strcpy(command + strlen(command), output_files);
  // printf("%s\n", command);
  system(command);

  return 0;
}
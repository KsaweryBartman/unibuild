#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cmd_arg {
  char name[255];
  char value[255];
};

struct cmd_arg parse_arg(const char *arg) {
  struct cmd_arg parsed = {{}, {}};

  bool parsing_name = true;

  for (const char *c = arg; *c != '\0'; c++) {
    if (*c == '=') {
      parsing_name = false;
      continue;
    }

    char tmpstr[2] = {*c, 0};

    if (parsing_name) {
      strcat(parsed.name, tmpstr);
    } else {
      strcat(parsed.value, tmpstr);
    }
  }

  return parsed;
}

struct cmd_arg *parse_args(int arg_count, char **arg_array) {
  struct cmd_arg *args =
      (struct cmd_arg *)malloc(sizeof(struct cmd_arg) * arg_count);
  for (int i = 0; i < arg_count; i++) {
    args[i] = parse_arg(arg_array[i]);
  }
  return args;
}

char *get_arg(int arg_count, struct cmd_arg *args, const char *arg_name) {
  for (int i = 0; i < arg_count; i++) {
    if (strcmp(args[i].name, arg_name)) {
      return args[i].value;
    }
  }
  return NULL;
}

#include <stdio.h>

int main(int argc, char **argv) {
  printf("This is a simple C application example.\nIt's been given %i "
         "arguments:\n",
         argc);
  for (int i = 0; i < argc; i++) {
    printf("\targv[%i] = \"%s\"\n", i, argv[i]);
  }
  printf("That'd be all!\n");
  return 0;
}
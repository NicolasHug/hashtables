#include <stdio.h>

#include "common.h"

void print_error(char * func_name, char * msg) {
  fprintf(stderr, "error in %s: %s\n", func_name, msg);
}

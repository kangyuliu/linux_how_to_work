#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int* p = NULL;
  puts("before invalid access");
  *p = 10;
  puts("after invalid access");
  exit(EXIT_FAILURE);
  // return 0;
}
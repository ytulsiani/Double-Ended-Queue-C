#include <stdlib.h>
#include <stdio.h>

int foo(int x) {
  int i = 9;
  x = 7;
  
  return i;
}

int bar(char* str) {
  int k;
  
  k = foo(12);
  str = NULL;
  
  return k;
}

int main(int argc, char* argv[]) {
  bar("Hello gdb!");
  
  return EXIT_SUCCESS;
}

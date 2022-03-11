#include <stdio.h>
#include <stdlib.h>

int int_pow(int, int);

int main(int argc, const char* argv[]) {
  int base, exp, result;
  if (argc < 3)
    return 1;

  base = atoi(argv[1]);
  exp = atoi(argv[2]);

  result = int_pow(base, exp);
  printf("%d to the %d is %d\n", base, exp, result);

  return 0;
}

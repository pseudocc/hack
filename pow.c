int int_pow(int base, int exp) {
  int result = 1;
  while (exp--)
    result *= base;
  return result;
}


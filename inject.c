#include <stdio.h>
#include <stdlib.h>

long htol(const char* hex_str) {
  long val;
  sscanf(hex_str, "%lx", &val);
  return val;
}

int main(int argc, const char* argv[]) {
  FILE* prog;
  FILE* rplc;
  long pos;
  char c;

  if (argc < 4)
    return 1;

  pos = htol(argv[3]);
  prog = fopen(argv[1], "r+");
  rplc = fopen(argv[2], "r");
  if (prog == NULL || rplc == NULL)
    return 1;

  fseek(prog, pos, SEEK_SET);
  while ((c = fgetc(rplc)) != EOF)
    fputc(c, prog);

  fclose(prog);
  fclose(rplc);
  return 0;
}

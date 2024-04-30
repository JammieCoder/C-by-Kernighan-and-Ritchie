
#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
  int state;
  int c;
  int nl;
  int nw;
  int nc;

  state = OUT;
  nw = 0;
  nc = 0;
  nl = 0;
  while (IN) {
    c = getchar();
    if (c == -1)
      break;
    nc = nc + 1;
    if (c == 10) {
      nl = nl + 1;
    }
    if (((c == 0x20) || (c == 10)) || (c == 9)) {
      state = OUT;
    } else if (!state) {
      state = IN;
      nw = nw + 1;
    }
  }
  printf("Lines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
  return 0;
}

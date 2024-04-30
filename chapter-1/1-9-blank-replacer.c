#include <stdio.h>
int main() {
  int c2, nBlanks = 0;
  while ((c2 = getchar()) != EOF) {
    if (c2 == ' ') {
      nBlanks++;
    } else {
      if (nBlanks > 0) {
        putchar(' ');
        nBlanks = 0;
      } else {
        putchar(c2);
      }
    }
  }
}
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
int main() {
  // stored on heap
  char *sp = "\xDD\xDD\xDD\xDD";
  // stored on stack
  char s[] = {'\xDD', '\xDD', '\xDD', '\xDD'};

  int fheit = 0;
  int cgrade = 0xffffffAA;
  // Variables are loaded onto the stack in the order that they are referenced
  // (i think)
  int lower = 0;
  int higher = 300;

  printf("%s\n", s);
  while (fheit <= higher) {
    printf("%d %d\n", fheit, cgrade);
    fheit += 10;
    cgrade = 5 / 9 * (fheit - 32);
  }
}
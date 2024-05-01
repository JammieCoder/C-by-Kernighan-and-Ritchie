#include <stdio.h>
int main() {
  int c2;
  while ((c2 = getchar()) != EOF) {
    switch (c2) {
    case '\t':
      printf("%s", "\\t");
      break;
    case '\b':
      printf("%s", "\\b");
      break;
    case '\\':
      printf("%s", "\\");
      break;
    default:
      putchar(c2);
      break;
    }
  }
  return 0;
}
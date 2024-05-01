#include <stdio.h>
int main() {
  int c, nNewLine = 0, nBlanks = 0, nTabs = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      nNewLine++;
    }
    if (c == ' ') {
      nBlanks++;
    }
    if (c == '\t') {
      nTabs++;
    }
  }
  printf("%d New Lines\n", nNewLine);
  printf("%d Blanks\n", nBlanks);
  printf("%d Tabs\n", nTabs);
  return 0;
}
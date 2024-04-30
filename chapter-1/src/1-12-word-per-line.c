#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

int main() {
  int c, state;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      state = OUT;
    } else {
      if (state == OUT) {
        state = IN;
        putchar('\n'); // new line because a new word has started
      }
      putchar(c);
    }
  }
  putchar('\n');
}
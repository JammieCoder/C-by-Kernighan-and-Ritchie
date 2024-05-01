#include <stdio.h>

#define IN 1         // inside a word
#define OUT 0        // outside a word
#define HISTWIDTH 20 // create a macro for any integer used > once

void init(int *nwordLen) {
  for (int i = 0; i < HISTWIDTH; i++) {
    nwordLen[i] = 0;
  }
}

void reader(int *nwordLen) {
  int state, c, ncinword;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      state = OUT;
    } else {
      if (state == OUT) {
        state = IN;
        ++nwordLen[ncinword];
        ncinword = 0;
      }
      ncinword++;
    }
  }
}

void print(int *nwordLen) {
  printf("Word Lengths Histogram: \n");
  for (int i = 0; i < HISTWIDTH; i++) {
    printf("%d |", i);
    for (int j = 0; j < nwordLen[i]; j++) {
      putchar('-');
    }
    putchar('\n');
  }
}

int main() {
  int nwordLen[HISTWIDTH];

  // arrays are already pointers to their first element
  // (can send it as is)
  init(nwordLen);
  reader(nwordLen);
  print(nwordLen);
}
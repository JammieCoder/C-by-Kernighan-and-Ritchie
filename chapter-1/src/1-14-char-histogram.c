#include <stdio.h>

#define ALPHLENGTH 26

void init(int *ncharlen) {
  for (int i = 0; i < ALPHLENGTH; i++) {
    ncharlen[i] = 0;
  }
}

void reader(int *ncharlen) {
  int c;
  while ((c = getchar()) != EOF) {
    if ((c <= 'z' && c >= 'a') || (c >= 'A' && c <= 'Z')) { // A = 65, z = 122
      if (c >= 'a') {
        c = c - ALPHLENGTH - 6; // Convert to uppercase
        // (there are 6 symbols between upcase and lowercase alphabets)
      }
      // add to index of ncharlen where the 0th position is for 'A'
      ++ncharlen[c - 'A'];
    }
  }
}

void print(int *ncharlen) {
  printf("Character Histogram: \n");
  for (int i = 0; i < ALPHLENGTH; i++) {
    printf("%c |", 'A' + i);
    for (int j = 0; j < ncharlen[i]; j++) {
      putchar('-');
    }
    putchar('\n');
  }
}

int main() {
  int ncharlen[ALPHLENGTH];

  // arrays are already pointers to their first element
  // (can send it as is)
  init(ncharlen);
  reader(ncharlen);
  print(ncharlen);

  return 0;
}
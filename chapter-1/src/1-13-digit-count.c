#include <stdio.h>
void init(int *nwhite, int *nother, int *ndigit) {
  *nwhite = *nother = 0; // need to be dereferenced to change
  for (int i = 0; i < 10; i++) {
    ndigit[i] = 0;
  }
}

void reader(int *nwhite, int *nother, int *ndigit) {
  int c;
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ndigit[c - '0']++; //(characters are integers)
    } else if (c == ' ' || c == '\n' || c == '\t') {
      (*nwhite)++;
    } else {
      (*nother)++;
    }
  }
}

void print(int *nwhite, int *nother, int *ndigit) {
  printf("digits = ");
  for (int i = 0; i < 10; i++) {
    printf(" %d\n", ndigit[i]);
  }
  printf(", white space = %d, other = %d\n", *nwhite, *nother);
}

int main() {
  int nwhite, nother, ndigit[10];

  // arrays are already pointers to their first element
  // (can send it as is)
  init(&nwhite, &nother, ndigit);
  reader(&nwhite, &nother, ndigit);
  print(&nwhite, &nother, ndigit);
}
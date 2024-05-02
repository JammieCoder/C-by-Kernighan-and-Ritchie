#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int getlinec(char line[], int maxline);
void saveline(char to[], char from[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getlinec(line, MAXLINE)) > 0) {
    if (len > MINLINE) {
      printf("%s", line);
    }
  }
  putchar('\n');
  return 0;
}

int getlinec(char line[], int maxline) {
  int c, i;

  // stops when maxline-1 is reached (array is full)
  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  // if the for loop exited because of a new line, finish up line array
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0'; // null-terminate

  while ((c = getchar()) != EOF && c != '\n') {
    ++i;
  }
  return i;
}

void saveline(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
#include <stdio.h>
#define MAXLINE 1000

int getlinec(char line[], int maxline);
void saveline(char to[], char from[]);

int main() {
  int len, max;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;
  while ((len = getlinec(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      saveline(longest, line);
    }
  }

  if (max > 0) {
    printf("%s\n", longest);
  }
  if (max >= MAXLINE - 1) {
    printf("This line was %d characters long so the whole line couldn't be "
           "displayed",
           max);
  }
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
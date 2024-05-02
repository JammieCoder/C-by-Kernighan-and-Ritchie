#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 1

int getlinec(char line[], int maxline);
void stripline(char to[], char from[], int len);

int main() {
  int len;
  char line[MAXLINE], stripped[MAXLINE];

  while ((len = getlinec(line, MAXLINE)) > 0) {
    if (len < MAXLINE) {
      stripline(stripped, line, len);
      printf("%s", stripped);
    } else {
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

  if (i == maxline - 1) {
    while ((c = getchar()) != EOF && c != '\n') {
      ++i;
    }
  }

  return i;
}

void stripline(char to[], char from[], int len) {
  // iterate backwards over the from array until we
  // reach a character that isn't a tab or a blank
  while (len >= MINLINE && (from[len] == '\t' || from[len] == ' ' ||
                            from[len] == '\n' || from[len] == '\0')) {
    --len;
  }
  int j = 0;
  // if it's not completely blank
  if (len >= MINLINE) {
    // copy the line across with the new length we have given it
    while (j <= len) {
      to[j] = from[j];
      j++;
    }
    to[j] = '\n';
    j++;
  }
  to[j] = '\0';
}
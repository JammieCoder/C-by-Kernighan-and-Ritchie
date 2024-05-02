#include <stdio.h>

#define MAXLINE 1000

// functions cannot return arrays
void reverse(char result[], char s[], int len) {
  len--; // account for '\n' on the end
  int i;
  for (i = 0; i < len; i++) {
    result[len - i - 1] = s[i];
  }
  result[len] = '\n';
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

int main() {
  int len;
  char line[MAXLINE], reversed[MAXLINE];

  while ((len = getlinec(line, MAXLINE)) > 0) {
    if (len < MAXLINE) {
      reverse(reversed, line, len);
      printf("%s", reversed);
    } else {
      printf("%s", line);
    }
  }
  putchar('\n');
  return 0;
}

// text stream = sequence of chars div'd -> lines (chars followed by \n)
#include <stdio.h>
#include <sys/types.h>
#include <uchar.h>

int main() {
  printf("Enter a character: ");

  // what if we use a char32?
  char32_t c = getchar();

  printf("You entered: ");
  putchar(c);
  printf("\n");

  printf("char size: %lu bytes\n", (ulong)sizeof(char32_t));
  //-> char32 are the same size as an int (32bytes)

  // clean input buffer
  printf("Rest of buffer: ");
  // char32 have enough space for int but is casted for semantics
  while ((c = getchar()) != '\n' && (int)c != EOF) {
    putchar(c);
  }
  printf("\n");
}

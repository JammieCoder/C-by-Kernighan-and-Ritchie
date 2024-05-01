// text stream = sequence of chars div'd -> lines (chars followed by \n)
#include <stdio.h>
#include <sys/types.h>
void clearbuffer() {
  printf("char size: %lu byte\n", (ulong)sizeof(char));
  //-> chars are 1 byte long
  printf("int size: %lu bytes\n", (ulong)sizeof(int));
  // but int are 4 bytes long

  // clean input buffer
  printf("Rest of buffer: ");
  // must use int so enough storage for EOF int (-1 = 0xffffffff)
  int c2;
  // extra brackets required because != has higher precedence than =
  // i.e. c = getchar() != EOF -> c = (getchar())
  while ((c2 = getchar()) != '\n' && c2 != EOF) {
    putchar(c2);
  }
  printf("\n");
}

int main() {
  printf("Enter a character: ");
  // waiting state --> only gets on character so possibility
  // of overflow --> deletes from input buffer
  char c1 = getchar();

  printf("You entered: ");
  putchar(c1);
  printf("\n");

  clearbuffer();
  return 0;
}

#include <stdio.h>
int main() {
  printf("HelloWorld\b");        // backspace
  printf("HelloWorld\e");        // remove next char
  printf("HelloWorld\f");        // split next chars to next line
  printf("HelloWorld\n");        // new line
  printf("HelloWorld\rhellom*"); // carriage return - moves cursor to beginning
                                 // of line
  printf("HelloWorld\t");        // tab
  printf("HelloWorld\v");        // same as f
  printf("HelloWorld\x35");      // hex
  printf("HelloWorld%o", 0357);  // octal
  printf("\n\n");
}
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
int main() {
  float fheit = 0;
  float cgrade = 0; // in reverse because little-endian
  // Variables are loaded onto the stack in the order that they are referenced
  // (i think)
  float lower = -20;
  float upper = 150;
  float step = 10;

  cgrade = lower;
  printf("\nC  | F");
  printf("\n_______\n");
  while (cgrade <= upper) {
    // integer division truncates the decimal, float division doesn't
    // automatic tmp conversion -> float if other operand is float
    fheit = (cgrade / (5.0 / 9.0)) + 32.0;
    // no before decimal = min char's wide
    // no. after decimal = min char's after decimal
    printf("%3.0f|%3.0f\n", cgrade, fheit);
    cgrade += step;
  }
}
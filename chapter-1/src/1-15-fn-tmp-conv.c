#include <stdio.h>
#include <sys/types.h>

float converttofheit(float *cgrade) { return (*cgrade / (5.0 / 9.0)) + 32.0; }

int main() {
  float fheit;
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
    fheit = converttofheit(&cgrade);
    printf("%3.0f|%3.0f\n", cgrade, fheit);
    cgrade += step;
  }

  return 0;
}
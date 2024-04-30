#include <stdio.h>

// "magic numbers" Replaced at compile-time, aren't in declarations
// UPPERCASE , no ; requred

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  int fheit;
  // condition checked --> true: code --> step
  //                       false: exits
  for (fheit = UPPER; fheit >= LOWER; fheit -= STEP) {
    printf("%3d %6.1f\n", fheit, (5.0 / 9.0) * (fheit - 32));
  }
}
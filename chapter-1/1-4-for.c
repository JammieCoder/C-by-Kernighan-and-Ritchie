#include <stdio.h>
int main() {
  int fheit;
  // condition checked --> true: code --> step
  //                       false: exits
  for (fheit = 300; fheit >= 0; fheit -= 20) {
    printf("%3d %6.1f\n", fheit, (5.0 / 9.0) * (fheit - 32));
  }
}
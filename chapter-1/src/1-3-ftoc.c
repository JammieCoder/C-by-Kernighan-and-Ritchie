#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
int main() {
  // stored on heap
  char *sp = "\xDD\xDD\xDD\xDD";
  // stored on stack
  char s[] = {'\xDD', '\xDD', '\xDD', '\xDD'};

  float fheit = 0;
  float cgrade = 0xffffffAA; // in reverse because little-endian
  // Variables are loaded onto the stack in the order that they are referenced
  // (i think)
  float lower = 0;
  float upper = 300;
  float step = 20;
  int8_t maxSignedInt8 = INT8_MAX;    // 01111111 or 7F
  int8_t minSignedInt8 = INT8_MIN;    // 10000000 o 80
  int16_t maxSignedInt16 = INT16_MAX; // 0111... or FF7F
  int16_t minSignedInt16 = INT16_MIN; // 1000..... or 0080
  int maxSignedInt = INT32_MAX;       // 0111... or FFFFFF7F
  int minSignedInt = INT32_MIN;       // 1000..... or 00000080
  long maxSignedInt64 = INT64_MAX;    // 0111... or FFFFFFFFFFFFFF7F
  long minSignedInt64 = INT64_MIN;    // 1000..... or 0000000000000080

  printf("%x:%s:%u\n", 0xDDDDDDDD, s, 0xDDDDDDDD); // unsigned
  printf("max int8 (signed):%d\n", maxSignedInt8);
  printf("min int8 (signed):%d\n", minSignedInt8);
  printf("max int16 (signed):%d\n", maxSignedInt16);
  printf("min int16 (signed):%d\n", minSignedInt16);
  printf("max int32 (signed):%d\n", maxSignedInt);
  printf("min int32 (signed):%d\n", minSignedInt);
  printf("max int64 (signed):%ld\n", maxSignedInt64); // long int
  printf("min int64 (signed):%ld\n", minSignedInt64); // long int

  fheit = lower;
  printf("\nF  |   C");
  printf("\n__________\n");
  while (fheit <= upper) {
    // integer division truncates the decimal, float division doesn't
    // automatic tmp conversion -> float if other operand is float
    cgrade = 5.0 / 9.0 * (fheit - 32);
    // no before decimal = min char's wide
    // no. after decimal = min char's after decimal
    printf("%3.0f|%6.2f\n", fheit, cgrade);
    fheit += step;
  }
  return 0;
}
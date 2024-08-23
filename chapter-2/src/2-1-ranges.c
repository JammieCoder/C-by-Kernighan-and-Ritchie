#include <float.h>
#include <limits.h>
#include <stdio.h>

#define UNSIGNED_MIN 0

int printrange(char* name, int bits, long double min, long double max);
int printfloatrange(char* name, int bits, int precisionbits, int exponentbits,long double min, long double max);

int main(int argc, char *argv[])
{
    printrange("char", CHAR_BIT, CHAR_MIN, CHAR_MAX);
    printrange("short", sizeof(short)*8, SHRT_MIN, SHRT_MAX);
    printrange("int", sizeof(int)*8, INT_MIN, INT_MAX);
    printrange("long", sizeof(long)*8, LONG_MIN, LONG_MAX);
    printrange("unsigned char", CHAR_BIT, UNSIGNED_MIN, UCHAR_MAX);
    printrange("unsigned short", sizeof(short)*8, UNSIGNED_MIN, USHRT_MAX);
    printrange("unsigned int", sizeof(int)*8, UNSIGNED_MIN, UINT_MAX);
    printrange("unsigned long", sizeof(long)*8, UNSIGNED_MIN, ULONG_MAX);
    
    printf("\n");
    printfloatrange("float", sizeof(float)*8, FLT_MANT_DIG, sizeof(float)*8-FLT_MANT_DIG, FLT_MIN, FLT_MAX);
    printfloatrange("double", sizeof(double)*8, DBL_MANT_DIG, sizeof(double)*8-DBL_MANT_DIG, DBL_MIN, DBL_MAX);
    printfloatrange("long double", sizeof(long double)*8, LDBL_MANT_DIG,sizeof(long double)*8-LDBL_MANT_DIG, LDBL_MIN, LDBL_MAX);
    
    return 0;
}


int printrange(char* name, int bits, long double min, long double max){
    printf("%20s | %3d | %20.0Lf | %Lg\n", name, bits, min, max);
    return 0;
}

int printfloatrange(char* name, int bits, int precisionbits, int exponentbits,long double min, long double max){
    printf("%20s | %3d | %3d | %3d | %Lg | %Lg\n", name, bits, precisionbits, exponentbits, min, max);
    return 0;
}

// g = scientific notation
// Lf = long double
// ul = unsigned long

// 0.. = octal = '\...'
// 0x... = hex = '\x..'
// 0x...UL = unsigned long hex

// '..' = char
// char is an integer
// '0' = 48

// '\a' = bell
// '\b' = backspace
// '\f' = formfeed
// '\v' = vertical tab
// '\\' = backslash
// '\?' = ?
// '\'' = '
// '\"' = "

// enums exist as well
// e.g) enum months { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
// Useful for automatic constant generation (FEB = 2, MAR = 3 etc)
// Useful for compile-time operations


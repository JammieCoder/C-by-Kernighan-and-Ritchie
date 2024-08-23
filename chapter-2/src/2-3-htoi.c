#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int htoi(char *s);

int main(int argc, char *argv[])
{ 
    printf("%s: %d\n", "0xbf5",htoi("0xbf5"));
    return 0;
}

int htoi(char *s)
{
    char c = '0';
    int result = 0;
    for (int i = strlen(s)-1; ((c >= 'A' && c <= 'F') || isdigit(c)) && i>=0 ; i--) {
        c = toupper(s[i]);
        if(c >= 'A' && c <= 'F')
            result += (10 + c - 'A')*pow(16, strlen(s)-1-i);
        else if(isdigit(c))
            result += (c - '0')*pow(16, strlen(s)-1-i);
    }
    return result;
}

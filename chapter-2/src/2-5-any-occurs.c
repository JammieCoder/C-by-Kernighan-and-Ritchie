// if  n = 5:
// x = ++n -> x = 6
// x = n++ -> x = 5
// Order of the increment/decrement operator only matters if the value is used

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <strings.h>

int any(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    int result = 0;
    char s1[] = "acdc";
    char s2[] = "c";
    printf("String: %s\nString of chars to compare against: %s\n", s1, s2);

    result = any(s1, s2); 

    assert(result == 1); // 'c' is at index 2
     
    printf("The character at position 2 (\'c\') is the first banned character");

    return 0;
}

int any(char s1[], char s2[])
{
    int result = -1; // Default to no characters occuring in s1
    for(int i = 0; i < strlen(s1); i++)
    {
        // returns NULL if the character is allowed (doesn't exist in s2)
        // otherwise: returns a pointer to the character in s2
        if (strchr(s2, s1[i])!=NULL) 
        {
            result = i;
            break;
        }
    } 
    return result;
}

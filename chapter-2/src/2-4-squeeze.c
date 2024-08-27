// if  n = 5:
// x = ++n -> x = 6
// x = n++ -> x = 5
// Order of the increment/decrement operator only matters if the value is used

#include <stdio.h>
#include <string.h>
#include <assert.h>

int squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    char s1[] = "abcd";
    char s2[] = "cdef";
    printf("String: %s\nString of banned characters: %s\n", s1, s2);

    squeeze(s1, s2);
     
    assert(strncmp(s1, "ab", 4) == 0);
    printf("The new string is correctly: %s\n",s1);
    return 0;
}

int squeeze(char s1[], char s2[])
{
    int i,j;
    for(i=j = 0; i < strlen(s1); i++)
    {
        // returns NULL if the character is allowed (doesn't exist in s2)
        // otherwise: returns a pointer to the character in s2
        if (strchr(s2, s1[i])==NULL) 
            s1[j++] = s1[i];        
    } 
    s1[j]='\0'; // null-terminate
    return 0;
}

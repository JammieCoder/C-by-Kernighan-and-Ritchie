// Expressions connected by && or || are evaluated left to right
// e.g) for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//          s[i] = c;
//      // if "i<lim-1" fails, no more characters are read (no room to store it in "s")
//      // "c!=EOF" must occur after a new character is read so that the EOF can be reached
// Precedence: (relational and equality operators) > (&& > ||)

#include <stdio.h>
int readline(char line[], int lim);

int main(int argc, char *argv[])
{
    int lim = 12;
    char line[lim];
    if (readline(line, lim) == 1)
       printf("Your line was truncated to fit in the buffer\n"); 
    printf("%s\n", line);
    return 0;
}

int readline(char line[], int lim)
{
    char c = 0;
    int i = 0;
    while (c != EOF) {
        if (i == lim - 1)
            break;
        if ((c=getchar()) == '\n') 
            break;
        line[i] = c;
        i++;
    }
    line[i]='\0';

    if (i == lim-1) {
        return 1; // The line is too long to be read
    }

    return 0;
}

#include <stdio.h>
#define MAXLINE 1000

int getlinec();
void saveline();

int  max;
char line[MAXLINE], longest[MAXLINE];

int main() {
    int len; 
    extern char line[], longest[];

    max = 0;
    while ((len = getlinec()) > 0) {
        if (len > max) {
            max = len;
            saveline();
        }
    }

    if (max > 0) {
        printf("%s\n", longest);
    }
    if (max >= MAXLINE - 1) {
        printf("This line was %d characters long so the whole line couldn't be "
                "displayed",
                max);
    }
    return 0;
}

int getlinec() {
    int c, i;
    extern char line[];

    // stops when maxline-1 is reached (array is full)
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    // if the for loop exited because of a new line, finish up line array
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0'; // null-terminate

    while ((c = getchar()) != EOF && c != '\n') {
        ++i;
    }
    return i;
}

void saveline(){
    int i = 0;
    extern char longest[], line[];

    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}

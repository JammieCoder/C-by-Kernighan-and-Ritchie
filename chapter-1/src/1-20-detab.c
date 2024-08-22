#include <stdio.h>
#define MAXLINE 1000
#define TABSTOPCOLS 8

int getlinec();
void detab();

int  max;
char line[MAXLINE], newline[MAXLINE];

int main() {
    int len; 
    extern char line[], newline[];

    max = 0;
    while ((len = getlinec()) > 0) {
        detab();
        printf("%s",line);
        printf("%s\n\n", newline);
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

void detab(){
    int i = 0,j = 0;
    extern char newline[], line[];

    while (line[i] != '\0') {
        if (line[i] == '\t'){
            while (j % TABSTOPCOLS > 0){
                newline[j++] = ' ';
            }
        }
        else{
            newline[j++] = line[i];
        }
        ++i;
    }
    newline[j]='\0';
}

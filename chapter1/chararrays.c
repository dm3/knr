#include <stdio.h>

#define MAXLINE 100 /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len; // length of the current line
    int max = 0; // maximum seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

/**
 * @param @out s line from input
 * @param lim maximum length of the line
 * @return length of the line
 */
int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

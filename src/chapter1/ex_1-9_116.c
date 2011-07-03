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
        printf("%d, %s\n", max, longest);
    }
    return 0;
}

/**
 * @param @out s line from input
 * @param lim maximum length of the line
 * @return length of the line
 */
int getline(char s[], int lim) {
    int c, i, last;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }
    // we may have exited the for loop on a newline character or on an EOF.
    // Newlines should be included into the line buffer if it's not yet full
    // and into the return value (length).
    if (i >= lim - 1) {
        if (c == '\n') {
            i++;
        }
        s[lim - 1] = '\0';
    } else {
        if (c == '\n') {
            s[i] = c;
            i++;
        }
        s[i] = '\0';
    }
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

#include <stdio.h>

#define MAXLINE 100

#define THRESHOLD 80 /* minimum size of lines to print */

int getline(char line[], int maxline);

int main() {
    char line[MAXLINE];
    int len;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len >= THRESHOLD) {
            printf("%s\n", line);
        }
    }
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

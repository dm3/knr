#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int maxline);
int remove_trailing_blanks(char line[], int length);
int is_blank(int c);

/**
 * Trims the input lines of trailing blanks and newlines and prints lines along
 * with their lengths.
 */
int main() {
    char line[MAXLINE];
    int len;
    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%d, %s\n", len, line);
    }
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
    int len = remove_trailing_blanks(s, i);
    return len;
}

/**
 * Trims the spaces, tabs and newlines off of the input line.
 *
 * @param @out s array of characters terminated by \0
 * @param len length of the array
 * @return length of the trimmed line
 */
int remove_trailing_blanks(char s[], int len) {
    if (len == 0) {
        return 0;
    }
    // s[len] is a null terminator
    while (is_blank(s[--len])) {
        if (len < 0) {
            break;
        }
    }
    s[++len] = '\0';
    return len;
}

int is_blank(int c) {
    return c == ' ' || c == '\t' || c == '\n';
}


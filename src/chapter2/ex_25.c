#include <stdio.h>
#define MAX 100

/**
 * Finds the first index of a character from string `find` in string `s`.
 *
 * @param s input string
 * @param s string containing characters to search for in `s`
 * @returns -1 if no characters from `find` were found in `s`, index of the
 * first location of any character from `find` in `s`
 */
int any(char s[], char find[]);

/**
 * Checks whether string `s` contains the character `c`.
 *
 * @returns 0 (false) if `s` doesn't contain `c`, 1 (true) otherwise
 */
int contains(char s[], char c);

int main() {
    int c, i = 0;
    char s[MAX];

    while (i < MAX - 1 && (c = getchar()) != '\n' && c != '\r' && c != EOF) {
        s[i++] = c;
    }
    s[i] = '\0';

    // constant characters to be deleted
    char find[] = "a1z";
    int result = any(s, find);
    printf("%d\n", result);
}

int any(char s[], char find[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (contains(find, s[i])) {
            return i;
        }
    }
    return -1;
}

int contains(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return 1;
        }
    }
    return 0;
}

#include <stdio.h>
#include <math.h>

#define MAX 100

/**
 * Converts a string of hexadecimal digits to an integer.
 *
 * @param s array of digits. Allowable digits: {a-f, A-F, 0-9}
 * @returns -1 if conversion failed, positive result of the conversion if
 * conversion succeeded.
 */
long htoi(char s[]);

/**
 * Converts a hexadecimal char to a decimal.
 * @returns -1 if conversion failed,
 */
int h_char_to_d(char h);

/**
 * HTOI
 */
int main() {
    char s[MAX];
    int c, i = 0;

    for (i = 0; i < MAX-1 && (c = getchar()) != EOF && c != '\r' && c != '\n'; i++) {
        s[i] = c;
    }

    long result = htoi(s);
    if (result >= 0) {
        printf("%ld\n", result);
        return 0;
    }
    return 1;
}

long htoi(char s[]) {
    long result = 0;
    int dec;
    for (int i = 0; (dec = h_char_to_d(s[i])) >= 0 && dec <= 15; i++) {
        result = result * 16 + dec;
    }
    return result;
}

int h_char_to_d(char h) {
    if (h >= '0' && h <= '9') {
        return h - '0';
    }
    if (h >= 'a' && h <= 'f') {
        return h - 'a' + 10;
    }
    if (h >= 'A' && h <= 'F') {
        return h - 'A' + 10;
    }
    return -1;
}

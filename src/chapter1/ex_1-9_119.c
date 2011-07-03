#include <stdio.h>

#define MAX_LENGTH 1000

/**
 * Reverses a null-terminated string.
 *
 * @param str string ending with a null-terminator
 * @param len length of the str including the null-terminator
 */
void reverse(char str[], int len);

int main() {
    int c, i = 0;
    char str[MAX_LENGTH + 1];
    for (i = 0; i < MAX_LENGTH && (c = getchar()) != EOF; i++) {
        str[i] = c;
    }
    if (i == MAX_LENGTH) {
        printf("Input string is too long. Exceeding %d characters!\n", MAX_LENGTH);
        return -1;
    } else {
        str[i] = '\0';
        printf("Original: %s\n", str);
        reverse(str, i);
        printf("Reversed: %s\n", str);
    }
    return 0;
}

void reverse(char str[], int len) {
    char tmp;
    /*
     * We have two cases to consider:
     * 1. length is an even number
     *      in this case we obviously need to consider len/2 swaps as there are
     *      len/2 pairs of characters in the string
     * 2. length is an odd number
     *      in this case we also need to consider len/2 swaps as the middle
     *      character without a pair doesn't need to be reversed
     */
    len--;
    for (int i = 0; i <= len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i];
        str[len - i] = tmp;
    }
}

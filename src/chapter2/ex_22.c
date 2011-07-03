#include <stdio.h>

#define MAX 10

/**
 * Loop equivalent to
 *
 * for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 *
 * without && or || operators.
 */
int main() {
    int i = 0, c;
    char s[MAX];

    /*
     * Invariants:
     * 1. Loop finishes with i = amount of characters including the newline or EOF.
     * 2. Last character in the `s` array is the last character read from input
     *    before the newline or EOF is encountered.
     * 3. Loop goes up until `lim - 1`
     */
    while (i < MAX - 1 && ((c = getchar()) != '\n' && c != EOF)) {
        s[i++] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);
}

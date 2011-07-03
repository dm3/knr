#include <stdio.h>

/**
 * Loop equivalent to
 *
 * for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 *
 * without && or || operators.
 */
int main() {
    int lim = 10, i = 0;
    int s[lim], c;

    /*
     * Invariants:
     * 1. Loop finishes with i = amount of characters including the newline or EOF.
     * 2. Last character in the `s` array is the last character read from input
     *    before the newline or EOF is encountered.
     * 3. Loop goes up until `lim - 1`
     */
    while (i < lim - 1) {
        c = getchar();
        if (c != '\n' && c != EOF) {
            s[i] = c;
        }
        i++;
    }
}

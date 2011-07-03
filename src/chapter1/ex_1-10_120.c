#include <stdio.h>

/* That's how we roll! */
#define TAB_WIDTH 4

/**
 * Prints `spaces` space characters to stdout.
 *
 * @param spaces
 *          number of spaces to substitute for a tab
 */
void print_spaces(int spaces);

/**
 * Replaces tabs in the input stream with spaces according to the hardcoded
 * TAB_WIDTH. If there are mixed tabs and spaces, spaces are accounted for when
 * calculating the amount of spaces tabs have to be converted to. E.g.
 *
 * Example:
 *     TAB_WIDTH = 4
 *
 * Input:
 *     ___\t (3 spaces and a tab)
 *
 * Output:
 *     ____ (tab converted to (TAB_WIDTH - 3) spaces)
 *
 * Input:
 *     \t
 *
 * Output:
 *     ____
 */
int main() {
    int c;
    // number of continuous spaces
    int cont_spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            // every TAB_WIDTH spaces we reset the counter
            cont_spaces = (cont_spaces + 1) % TAB_WIDTH;
            putchar(c);
        } else if (c == '\t') {
            if (cont_spaces > 0) {
                // we have some spaces occupying the column,
                // only need to fill the rest
                print_spaces(TAB_WIDTH - cont_spaces);
            } else {
                print_spaces(TAB_WIDTH);
            }
            cont_spaces = 0;
        } else {
            cont_spaces = 0;
            putchar(c);
        }
    }
    return 0;
}

void print_spaces(int num_of_spaces) {
    for (int i = 0; i < num_of_spaces; i++) {
        putchar(' ');
    }
}

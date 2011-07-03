#include <stdio.h>

#define TAB_WIDTH 4

/**
 * Replaces spaces in the input stream with tabs according to the hardcoded
 * TAB_WIDTH.
 *
 * Example:
 *     TAB_WIDTH = 4
 *
 * Input:
 *     ___\t (3 spaces and a tab)
 *
 * Output:
 *     ___\t (unchanged as there are not enough spaces for the width)
 *
 * Input:
 *     ____
 *
 * Output:
 *     \t
 *
 * Input:
 *     _____
 *
 * Output:
 *     \t_
 */
int main() {
    int c;
    int cont_spaces = 0;
    while ((c = getchar()) != EOF) {
        if (cont_spaces == TAB_WIDTH) {
            putchar('\t');
            cont_spaces = 0;
        }
        if (c == ' ') {
            cont_spaces++;
        } else {
            for (int i = 0; i < cont_spaces; i++) {
                putchar(' ');
            }
            cont_spaces = 0;
            putchar(c);
        }
    }
}

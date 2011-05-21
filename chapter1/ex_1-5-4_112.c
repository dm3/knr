#include <stdio.h>

#define PUT_NEWLINE 1
#define NO_NEWLINE 0

main() {
    int c, action;

    /*
     * If a character is newline/blank or tab - do nothing unless it's the
     * first blank character after the word. In that case put a newline.
     */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (action == PUT_NEWLINE) {
                putchar('\n');
                action = NO_NEWLINE;
            }
        } else {
            putchar(c);
            action = PUT_NEWLINE;
        }
    }
}

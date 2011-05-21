#include <stdio.h>

#define TRUE 1
#define FALSE 0

main() {
    int c, last_char_blank = FALSE;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && last_char_blank == TRUE) {
            continue;
        } else if (c == ' ') {
            last_char_blank = TRUE;
        } else {
            last_char_blank = FALSE;
        }

        putchar(c);
    }
}

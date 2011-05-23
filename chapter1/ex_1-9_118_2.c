/**
 * This solution will be different to the first attempt at the 1.18 exercise in
 * that it will not limit the length of the lines, but will process the whole
 * input.
 *
 * To do this we will require a state machine which will track the state of the
 * input, i.e. whether we are:
 *
 * - in the part of a line which is blank
 * - in the part of a line which is not blank
 * - looking at the newline character
 */
#include <stdio.h>

/* Maximum number of blanks before the program gives up to determine whether
 * the line ends in whitespace or there are non-blank characters afterwards */
#define MAX_BUFFER 1000

/* State of the input we are currently observing */
#define NON_BLANKS 0
#define BLANKS 1

int main() {
    int c;

    int state = NON_BLANKS;
    int chars_in_line = 0;
    int buf_cursor = 0;
    char buf[MAX_BUFFER];
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            // skip completely blank lines
            if (chars_in_line > buf_cursor) {
                putchar(c);
            }
            chars_in_line = 0;
            buf_cursor = 0;
            state = NON_BLANKS;
        } else if (c == '\t' || c == ' ') {
            if (state == NON_BLANKS) {
                state = BLANKS;
            }
            buf[buf_cursor++] = c;
            chars_in_line++;
        } else {
            // if we have any blank characters - print them out
            if (state == BLANKS && buf_cursor > 0) {
                buf[buf_cursor] = '\0';
                printf("%s", buf);
                buf_cursor = 0;
            }
            putchar(c);
            chars_in_line++;
        }
    }
    return 0;
}

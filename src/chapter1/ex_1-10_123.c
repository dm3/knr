#include <stdio.h>

#define TRUE 1
#define FALSE 0

/**
 * A program which removes all of the comments of the form
 * a) Multiline - /+ +/ (subst + for *)
 * b) Single line - //
 * from its input.
 *
 * If a line ends with a single line comment, the newline will be discarded (as
 * it complicates parsing way too much :) ).
 *
 */
int main() {
    int c;

    int line_c_slash = FALSE, line_c_started = FALSE,
        mline_c_star = FALSE, mline_c_started = FALSE;
    while ((c = getchar()) != EOF) {
        // invariants :
        // 1. we cannot be both in a comment (line_c_started/mline_c_started == TRUE)
        //    and have `line_c_slash` == TRUE.
        if (line_c_slash == TRUE && (line_c_started == TRUE || mline_c_started == TRUE)) {
            printf("Error: both `line_c_slash` and `line_c_started || mline_c_started` are true!");
            return -1;
        }
        // 2. we cannot have both line and multiline comments started at the same time.
        if (line_c_started == TRUE && mline_c_started == TRUE) {
            printf("Error: both `line_c_started` and `mline_c_started` are true!");
            return -1;
        }

        if (line_c_slash == FALSE && c == '/' && line_c_started == FALSE && mline_c_started == FALSE) {
            // first slash found
            line_c_slash = TRUE;
            continue;
        } else if (line_c_slash == TRUE && c == '/') {
            // line comment begins
            line_c_slash = FALSE;
            line_c_started = TRUE;
            continue;
        } else if (line_c_slash == TRUE && c == '*') {
            // start of a multiline comment
            line_c_slash = FALSE;
            mline_c_started = TRUE;
            continue;
        } else if (line_c_slash == TRUE) {
            // slash not followed by anything
            putchar('/');
            line_c_slash = FALSE;
        } else if (line_c_started == TRUE && c == '\n') {
            // newline ends line comment
            line_c_started = FALSE;
            continue;
        } else if (mline_c_started == TRUE && mline_c_star == FALSE && c == '*') {
            // might be the start of the ending multiline comment delimiter
            mline_c_star = TRUE;
            continue;
        } else if (mline_c_started == TRUE && mline_c_star == TRUE && c == '/') {
            // end of multiline comment
            mline_c_star = FALSE;
            mline_c_started = FALSE;
            continue;
        } else if (mline_c_started == TRUE && mline_c_star == TRUE) {
            // not the ending multiline comment delimiter
            mline_c_star = FALSE;
            continue;
        } else if (line_c_started == TRUE || mline_c_started == TRUE) {
            // just skip characters
            continue;
        }
        putchar(c);
    }
}

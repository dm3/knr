#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// our favourite line length
#define LINE_LENGTH 4

int is_blank(int c);
void nl();
void p(int c);
int proc_buf(char buf[], int len, int max);
int next_line_break(char buf[], int len, int max);
int print_and_shift(char buf[], int len, int buf_sz);
int can_split(char buf[], int len, int c);

/**
 * Splits the lines longer than `LINE_LENGTH` characters into separate lines
 * after the last non-blank character. If there are no non-blank characters in
 * line - splits the line with a hyphen (-) as the `line[LINE_LENGTH]` character.
 *
 * Example:
 *     LINE_LENGTH = 4
 *
 * Input:
 *     abcde
 *
 * Output:
 *     abcd
 *     e
 *
 * Input:
 *     ab_cde
 *
 * Output:
 *     ab
 *     _cde
 *
 * Input:
 *     ab_c_de
 *
 * Output:
 *     ab_c
 *     _de
 *
 * Input:
 *     a_b_cde
 *
 * Output:
 *     a_b
 *     _cde
 *
 * Input:
 *     a____b
 *
 * Output:
 *     a
 *     ____
 *     b
 *
 * Input:
 *     _____
 *
 * Output:
 *     ____
 *     _
 */
int main() {
    int c, cnt = 0;
    char buf[LINE_LENGTH * 2];

    while ((c = getchar()) != EOF) {
        if (c == 10) {
            // input comes from a file with an ending LF
            // we don't need to process this character
            break;
        }
        buf[cnt++] = c;
        // Having a buffer of 2xMAX length lets us definitely end one line of
        // the output.
        if (cnt == LINE_LENGTH * 2) {
            cnt = proc_buf(buf, cnt, LINE_LENGTH);
        }
    }
    int rem = proc_buf(buf, cnt, LINE_LENGTH);
    while (rem > 0) {
        rem = proc_buf(buf, rem, LINE_LENGTH);
    }
    putchar(10);
}

/**
 * Prints out part of the buffer (<= max) from the beginning and shifts the
 * rest of the buffer left. Prints a newline if there number of characters in
 * the buffer is greater than max.
 *
 * @param buf - buffer with characters
 * @param len - length of the buffer
 * @param max - length of the line
 * @returns the remaining size of the buffer
 */
int proc_buf(char buf[], int len, int max) {
    if (len == 0) {
        return 0;
    }

    int line_break_idx = next_line_break(buf, len, max);
    int rem_buf_sz = 0;
    if (line_break_idx > 0) {
        rem_buf_sz = print_and_shift(buf, line_break_idx, len);
        if (len > max) {
            nl();
        }
    }

    return rem_buf_sz;
}

/**
 * @param buf - buffer with characters
 * @param len - length of the buffer
 * @param max - length of the line
 * @returns the index inside of the buf where the next line break should be
 *          inserted
 */
int next_line_break(char buf[], int len, int max) {
    if (len <= max) {
        return len;
    }

    int last_blank = -1, last_char = -1, last_word_end = -1, i = 0;
    for (int i = 0; i < max; i++) {
        if (is_blank(buf[i])) {
            last_blank = i;
            if (i > 0 && can_split(buf, i, buf[i])) {
                last_word_end = i;
            }
        } else {
            last_char = i;
        }
    }

    if (last_word_end > 0 && can_split(buf, max, buf[max]) == FALSE) {
        return last_word_end;
    }
    return max;
}

int can_split(char buf[], int len, int c) {
    return len > 0 && is_blank(buf[len - 1]) == FALSE && is_blank(c) == TRUE;
}

void nl() {
    p('\n');
}

void p(int c) {
    putchar(c);
}

int is_blank(int c) {
    return c == ' ' || c == '\t';
}

int print_and_shift(char buf[], int len, int buf_sz) {
    if (len > buf_sz) {
        len = buf_sz;
    }

    for (int i = 0; i < len; i++) {
        putchar(buf[i]);
    }
    int remainder = buf_sz - len;
    memcpy(buf, buf + len, remainder);

    return remainder;
}

#include <stdio.h>
#include "io.h"

int read_str_to_eof(char buf[], int max) {
    int read = read_to_eof(buf, max);
    buf[read] = '\0';
    return read;
}

int read_to_eof(char buf[], int max) {
    int c, i = 0;
    while (i < max && (c = getchar()) != EOF && c != '\r') {
        buf[i++] = c;
    }
    return i;
}

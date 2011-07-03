#include <stdio.h>
#include "io.h"

void read_str_to_eof(char buf[], int max) {
    int c, i = 0;
    while (i < max && (c = getchar()) != EOF && c != '\r') {
        buf[i++] = c;
    }
    buf[i] = '\0';
}

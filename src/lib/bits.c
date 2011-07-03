#include <stdio.h>
#include <stdlib.h> // atoi
#include "bits.h"

#define MAX 100

unsigned int bits_to_i(char s[]) {
    unsigned int result = 0;
    for (int i = 0; s[i] == '0' || s[i] == '1'; i++) {
        result = (result << 1) | (s[i] - '0');
    }
    return result;
}

void to_bits(char buf[], unsigned c) {
    unsigned int mask = 1;
    int size = sizeof(c) * 8;
    for (int i = 0; i < size; i++) {
        int masked = (c >> i) & mask;
        buf[size - 1 - i] = masked + '0';
    }
}

void print_bits(unsigned int x, unsigned int n) {
    unsigned int size = sizeof(x) * 8 + 1;
    char buf[size];
    to_bits(buf, x);
    buf[size - 1] = '\0';

    if (n < size) {
        printf("%s\n", buf + (size - 1 - n));
    } else {
        printf("%s\n", buf);
    }
}

unsigned int read_i() {
    char buf[MAX];
    int c, i = 0;
    while (i < MAX - 1 && (c = getchar()) >= '0' && c <= '9') {
        buf[i++] = c;
    }
    buf[i] = '\0';
    return atoi(buf);
}

unsigned int read_bits_i() {
    char buf[MAX], c;
    int i = 0;
    while (i < MAX - 1 && ((c = getchar()) == '0' || c == '1')) {
        buf[i++] = c;
    }
    buf[i] = '\0';
    return bits_to_i(buf);
}

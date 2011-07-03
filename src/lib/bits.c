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

void c_to_bits(char buf[], unsigned char c) {
    unsigned char mask = 1;
    for (int i = 0; i < 8; i++) {
        int masked = (c >> i) & mask;
        buf[7 - i] = masked + '0';
    }
}

void print_bits(unsigned char x) {
    char buf[9];
    c_to_bits(buf, x);
    buf[8] = '\0';
    printf("%s\n", buf);
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

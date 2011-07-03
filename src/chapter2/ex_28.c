#include <stdio.h>
#include "../lib/bits.h"

#define MAX 100

/**
 * Rotates `x` to right by `n` positions.
 */
unsigned rightrot(unsigned x, int n);

int main() {
    unsigned int x = read_bits_i();
    int num = read_i();

    unsigned result = rightrot(x, num);
    print_bits(result, 32);
}

unsigned int rightrot(unsigned int x, int n) {
    unsigned int bits = sizeof(x) * 8 - 1;
    unsigned int result = x;
    // [10...0]
    unsigned int last_bit_mask = 1 << bits;
    for (int i = 0; i < n; i++) {
        unsigned int last_bit = (x & 1) << bits;
        result = (last_bit & last_bit_mask) | (x >> 1);
    }
    return result;
}

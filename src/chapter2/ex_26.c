#include <stdio.h>
#include "../lib/bits.h"

#define MAX 100

/**
 * Updates `n` bits at position `p` in `x` with `n` rightmost bits of `y`.
 * `p` must be greater or equal to `n`.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    unsigned int x = read_bits_i();
    int pos = read_i();
    int num = read_i();
    unsigned int other = read_bits_i();

    // set the 3 bits at position 4 to 101, e.g.
    // setbits([00000000], 4, 3, [00000101]) = [00001010]
    unsigned result = setbits(x, pos, num, other);
    print_bits(result);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // p = 4, n = 3

    // [00000000] -> [11111111] -> [11111000] -> [00000111]
    unsigned mask = ~(~0 << n);
    // bits from `y` which will have to be set in `x`:
    // [10101101] -> [00000101]
    unsigned y_bits = y & mask;
    // move the `y_bits` so that it would align with the
    // position we have to overwrite in `x`:
    // [00000101] -> [00001010]
    unsigned y_mask = y_bits << (p - n);
    // create a mask for `x`
    // [00000111] -> [11111000] -> [11110001]
    unsigned x_mask = ~mask << (p - n);
    for (int i = 0; i < (p - n); i++) {
        x_mask = x_mask | (1 << i);
    }
    // clear `n` bits at position `p` in `x`
    // [11111111] -> [11110001]
    unsigned x_masked = x & x_mask;

    return x_masked | y_mask;
}

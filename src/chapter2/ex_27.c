#include <stdio.h>
#include "../lib/bits.h"

#define MAX 100

/**
 * Inverts `n` bits of `x` at position `p`.
 */
unsigned invert(unsigned x, int p, int n);

int main() {
    unsigned int x = read_bits_i();
    int pos = read_i();
    int num = read_i();

    unsigned result = invert(x, pos, num);
    print_bits(result);
}

unsigned invert(unsigned x, int p, int n) {
    // p = 4, n = 3, x = [11100101]
    // [11100101] -> [11101111]

    // [00001110]
    unsigned inv_mask = ~(~0 << n) << (p - n);
    // [11100101] -> [00001010]
    unsigned inv_x_part = ~x & inv_mask;
    // [11100101] -> [11100001]
    unsigned x_part = x & ~inv_mask;

    return inv_x_part | x_part;
}

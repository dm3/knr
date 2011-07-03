#include <stdio.h>
#include "../lib/bits.h"

int bitcount(unsigned int x);

/**
 * In a two's complemenbt number system, `x &= (x - 1)` deletes the rightmost 1-bit in `x`.
 * This happens because `x` and `x-1` can never have their rightmost bits equal
 * to `1` at the same time.
 */
int main() {
    unsigned int x = read_bits_i();

    printf("%d\n", bitcount(x));
}

int bitcount(unsigned int x) {
    int b;
    /*
        Code from the book:

        for (b = 0; x != 0; x >>= 1) {
            if (x & 1) {
                b++;
            }
        }
        return b;
    */
    // each `x&=(x-1)` 'eats up' ones from the right side of `x`, one by one
    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }
    return b;
}

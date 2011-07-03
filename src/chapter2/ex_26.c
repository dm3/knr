#include <stdio.h>
#include <stdlib.h> // atoi

#define MAX 100

/**
 * Updates `n` bits at position `p` in `x` with `n` rightmost bits of `y`.
 * `p` must be greater or equal to `n`.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y);

/**
 * Converts the array of 1/0 characters into an integer.
 */
unsigned int bits_to_i(char s[]);

/**
 * Prints out bit representation of a character followed by a newline.
 */
void print_bits(unsigned char x);

/**
 * Converts a given char `c` to a bit array representation.
 *
 * @param buf array of characters, must be at least 8 characters long
 */
void c_to_bits(char buf[], unsigned char c);

/**
 * Reads an integer from input string of decimals
 */
unsigned int read_i();

/**
 * Reads an integer from input string of bits
 */
unsigned int read_bits_i();

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

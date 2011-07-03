#ifndef BITS_H
#define BITS_H

/**
 * Converts the array of 1/0 characters into an integer.
 */
unsigned int bits_to_i(char s[]);

/**
 * Prints out bit representation of a variable followed by a newline.
 * @param x variable to print out
 * @param n number of bits from the right side to print
 */
void print_bits(unsigned int x, unsigned int n);

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

#endif

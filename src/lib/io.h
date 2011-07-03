#ifndef IO_H
#define IO_H

/**
 * Reads up to `max - 1` characters from input into the provided array `buf`
 * and appends the null-terminator (\0) as the last character. Stops when EOF
 * or carriage return (\r) is encountered.
 *
 * @returns number of characters read from the input stream (excluding the null-terminator (\0))
 */
int read_str_to_eof(char buf[], int max);

/**
 * Reads up to `max` characters from input into the provided array `buf`. Stops
 * when EOF or carriage return (\r) is encountered.
 *
 * @returns number of characters read from the input stream
 */
int read_to_eof(char buf[], int max);

#endif

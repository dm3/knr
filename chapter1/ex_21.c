#include <stdio.h>
#include <limits.h>
#include <float.h>

unsigned char calc_max_uchar() {
    return 0 - 1;
}

unsigned short calc_max_ushort() {
    return 0 - 1;
}

unsigned int calc_max_uint() {
    return 0 - 1;
}

unsigned long calc_max_ulong() {
    return 0 - 1;
}

signed char calc_min_char() {
    signed char x = 0, y = 1;
    while (x < y) {
        x--; y--;
    }
    return y;
}

signed char calc_max_char() {
    signed char x = 0, y = 1;
    while (x < y) {
        x--; y--;
    }
    return x;
}

signed short calc_min_short() {
    signed short x = 0, y = 1;
    while (x < y) {
        x--; y--;
    }
    return y;
}

signed short calc_max_short() {
    signed short x = 0, y = 1;
    while (x < y) {
        x--; y--;
    }
    return x;
}

signed int calc_min_int() {
    signed int x = -1;
    while (x < 0) x -= 1000;
    while (x > 0) x++;
    return x;
}

signed int calc_max_int() {
    signed int x = 1;
    while (x > 0) x += 1000;
    while (x < 0) x--;
    return x;
}

/*
 * Some braindead optimization.
 */
signed long calc_min_long() {
    signed long x = -1;
    while (x < 0) x -= 1000000000000;
    while (x > 0) x += 100000;
    while (x < 0) x -= 100;
    while (x > 0) x++;
    return x;
}

signed long calc_max_long() {
    signed long x = 1;
    while (x > 0) x += 1000000000000;
    while (x < 0) x -= 100000;
    while (x > 0) x += 100;
    while (x < 0) x--;
    return x;
}

/*
 * A program which determines the ranges of variables of different types
 * supported by C language, both signed and unsigned.
 */
int main() {
    printf("Ranges by printing the constants from header files:\n");
    printf("Range of unsigned char: [%d; %d]\n", 0, UCHAR_MAX);
    printf("Range of unsigned short: [%d; %hu]\n", 0, USHRT_MAX);
    printf("Range of unsigned int: [%d; %u]\n", 0, UINT_MAX);
    printf("Range of unsigned long: [%d; %lu]\n", 0, ULONG_MAX);
    printf("Range of signed char: [%d; %d]\n", CHAR_MIN, CHAR_MAX);
    printf("Range of signed short: [%hd; %hd]\n", SHRT_MIN, SHRT_MAX);
    printf("Range of signed int: [%d; %d]\n", INT_MIN, INT_MAX);
    printf("Range of signed long: [%ld; %ld]\n", LONG_MIN, LONG_MAX);

    putchar('\n');
    printf("Ranges by calculating the sizes of variables:\n");
    printf("Range of unsigned char: [%d; %d]\n", 0, calc_max_uchar());
    printf("Range of unsigned short: [%d; %hu]\n", 0, calc_max_ushort());
    printf("Range of unsigned int: [%d; %u]\n", 0, calc_max_uint());
    printf("Range of unsigned long: [%d; %d]\n", 0, calc_max_ulong());
    printf("Range of signed char: [%d; %d]\n", calc_min_char(), calc_max_char());
    printf("Range of signed short: [%hd; %hd]\n", calc_min_short(), calc_max_short());
    printf("Range of signed int: [%d; %d]\n", calc_min_int(), calc_max_int());
    printf("Range of signed long: [%ld; %ld]\n", calc_min_long(), calc_max_long());
}

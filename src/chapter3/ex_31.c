#include <stdio.h>
#include "../lib/io.h"

#define MAX 1000

void as_ints(int ints[], char chars[], int chars_sz);
int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

/**
 * I'm running into crazy problems with this exercise...
 */
int main() {
    int ints[MAX];

    for (int i = 0; i < MAX; i++) {
        ints[i] = i;
    }
    /* char buf[MAX]; */
    /* int sz = read_to_eof(buf, MAX); */

    /* as_ints(ints, buf, sz);         */
    /* printf("%d\n", binsearch(5, ints, sz)); */
    printf("%d\n", binsearch(950, ints, MAX));
}

/* void as_ints(int ints[], char chars[], int chars_sz) { */
/*     int i = 0;                                         */
/*     while (i < chars_sz) {                             */
/*         ints[i] = chars[i];                            */
/*     }                                                  */
/* }                                                      */

int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        }
    }
    return -1;
}

/**
 * Having 2 conditions instead of 3 will increase the number of iterations,
 * unless we move the third check into the `while` condition (which should be
 * pointless from the perspective of performance).
 */
int binsearch2(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;

    while (low <= high && v[mid] != x) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        }
    }
    if (x == v[mid]) {
        return mid;
    }
    return -1;
}

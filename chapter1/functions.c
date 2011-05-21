#include <stdio.h>

int power(int m, int n);

int main() {
    for (int i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
    int p = 1;
    for (int i = 1; i <=n; i++) {
        p = p * base;
    }
    return p;
}

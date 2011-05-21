#include <stdio.h>

#define LOWER  0   /* lower limit of the table */
#define UPPER 300 /* upper limit of the table */
#define STEP   20  /* step size */

float fahr_to_celsius(int fahrenheits);

int main() {
    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d %6.1f\n", fahr, fahr_to_celsius(fahr));
    }
    return 0;
}

float fahr_to_celsius(int fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}

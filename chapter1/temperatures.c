#include <stdio.h>

/**
 * The copy of K&R I have actually contains an error in the table - it lists
 * the first Fahrenheit temperature entry in the table as 1 instead of 0.
 */
main() {
    int fahr, celsius;
    // limits of the temperature scale and step size
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t\%6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

#include <stdio.h>

/**
 * The copy of K&R I have actually contains an error in the table - it lists
 * the first Fahrenheit temperature entry in the table as 1 instead of 0.
 */
main() {
    float fahr, celsius;
    // limits of the temperature scale and step size
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t\%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

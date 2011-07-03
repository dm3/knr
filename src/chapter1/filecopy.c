#include <stdio.h>

main() {
    /*
     * There's a whole paragraph describing why we cannot use the `char`
     * datataype. It appears that the EOF value doesn't fit into char so we
     * need an `int`.
     */
    int c;

    // the value of an expression in C is equal to its lvalue
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

#include <stdio.h>

main() {
    /*
     * There's a whole paragraph describing why we cannot use the `char`
     * datataype. It appears that the EOF value doesn't fit into char so we
     * need an `int`.
     */
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

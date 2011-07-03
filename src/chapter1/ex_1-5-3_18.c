#include <stdio.h>

main() {
    int c, cnt = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            cnt++;
        }
    }
    printf("Tabs, blanks and newlines total: %d\n", cnt);
}

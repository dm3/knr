#include <stdio.h>
#include "../lib/io.h"

#define MAX 100

void lower(char s[]);

int main() {
    char s[MAX];
    read_str_to_eof(s, MAX);

    lower(s);
    printf("%s\n", s);
}

void lower(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        s[i] = (c >= 'A' && c <= 'Z') ? c + 32 : c;
    }
}

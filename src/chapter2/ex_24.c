#include <stdio.h>
#define MAX 100

/**
 * Deletes all occurences of char `c` from `s`.
 */
void squeeze(char s[], char del[]);
int should_delete(char x, char del[]);

int main() {
    int c, i = 0;
    char s[MAX];

    while (i < MAX - 1 && (c = getchar()) != '\n' && c != '\r' && c != EOF) {
        s[i++] = c;
    }
    s[i] = '\0';

    // constant characters to be deleted
    char del[] = "a1z";
    squeeze(s, del);
    printf("%s\n", s);
}

void squeeze(char s[], char del[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (!should_delete(s[i], del)) {
            s[j++] = s[i];
        }
    }
    if (i > 0) {
        s[j] = '\0';
    }
}

int should_delete(char x, char del[]) {
    for (int i = 0; del[i] != '\0'; i++) {
        if (x == del[i]) {
            return 1;
        }
    }
    return 0;
}

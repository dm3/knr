/**
 * Copied from the 1.6 - 1.13 exercise as we shouldn't know about reuse yet.
 */
#include <stdio.h>

// Number of ASCII characters (we weren't told to only count printable ones)
#define MAX_CHARACTERS 255

// Maximum number of symbols in the histogram row (column)
#define MAX_ROW_LENGTH 20

int max(int arr[], int b, int e) {
    int max = 0;
    for (int i = b; i < e; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void normalize_row_lengths(int counts[], float row_lengths[], int b, int e) {
    int max_num_words = max(counts, b, e);
    float point = ((float) MAX_ROW_LENGTH) / max_num_words;

    for (int i = b, j = 0; i < e; i++) {
        row_lengths[j++] = counts[i] * point;
    }
}

void print_histogram(int counts[], int sz) {
    int b = 33, e = 126; // first and last printable characters

    // set the beginning to the index of the first non-zero count
    while (counts[b] == 0 && b < sz)
        b++;
    // set the ending to the index of the last non-zero count
    while (counts[e] == 0 && e >= 0)
        e--;

    e++; // ending points to the last zero count (so that it would be exclusive)
    int rows = e - b;

    if (rows <= 0) {
        printf("No data found!\n");
        return;
    }

    float row_lengths[rows];
    normalize_row_lengths(counts, row_lengths, b, e);

    for (int i = b, j = 0; i < e; i++) {
        printf("%2c (%4d t.) ", (char) i, counts[i]);
        for (int k = 0; k < row_lengths[j]; k++) {
            putchar('=');
        }
        putchar('\n');
        j++;
    }
}

void init_zeroes(int arr[], int len) {
    for (int i = 0; i <= len; i++) {
        arr[i] = 0;
    }
}

/**
 * Print the histogram of frequencies of characters of the input.  Bars will
 * point horizontally.
 *
 * Considering input of "a bb ccc dddd eeeee", which contains
 *
 * 1 x a
 * 2 x b
 * 3 x c
 * 4 x d
 * 5 x e
 *
 * the output should look like this:
 *
 * 1 (a) ====
 * 2 (b) ========
 * 3 (c) ============
 * 4 (d) ================
 * 5 (e) ====================
 *
 * Maximum length of the bar (100%) should be 20 symbols
 */
int main() {
    int counts[MAX_CHARACTERS], c;
    int current_len = 0;

    init_zeroes(counts, MAX_CHARACTERS);

    while ((c = getchar()) != EOF) {
        counts[(int) c]++;
    }

    print_histogram(counts, MAX_CHARACTERS);
    return 0;
}


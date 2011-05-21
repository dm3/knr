#include <stdio.h>

#define IN 1  /* inside of the word */
#define OUT 0 /* outside of the word */

#define TRUE 1
#define FALSE 0

// Maximum length of the word - according to the
// wikipedia (http://en.wikipedia.org/wiki/Longest_word_in_English) - length of
// the longest word in the major dictionary.
#define MAX_WORD_LENGTH 45

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

void normalize_row_lengths(int word_counts[], float row_lengths[], int b, int e) {
    int max_num_words = max(word_counts, b, e);
    float point = ((float) MAX_ROW_LENGTH) / max_num_words;

    for (int i = b, j = 0; i < e; i++) {
        row_lengths[j++] = word_counts[i] * point;
    }
}

void print_histogram(int word_counts[], int sz) {
    int b = 1, e = sz; // beginning and end row indexes

    // set the beginning to the index of the first non-zero count
    while (word_counts[b] == 0 && b < sz)
        b++;
    // set the ending to the index of the last non-zero count
    while (word_counts[e] == 0 && e >= 0)
        e--;

    e++; // ending points to the last zero count (so that it would be exclusive)
    int rows = e - b;

    if (rows <= 0) {
        printf("No data found!\n");
        return;
    }

    float row_lengths[rows];
    normalize_row_lengths(word_counts, row_lengths, b, e);

    for (int i = b, j = 0; i < e; i++) {
        printf("%3d (%4d w.) ", i, word_counts[i]);
        for (int k = 0; k < row_lengths[j]; k++) {
            putchar('=');
        }
        putchar('\n');
        j++;
    }
}

void update_count(int word_counts[], int len, int max) {
    if (len > max) {
        printf("Cannot register word with length: %d\n", len);
    } else {
        word_counts[len]++;
    }
}

int non_word(int c) {
    return c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == ';';
}

void init_zeroes(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = 0;
    }
}

/**
 * Print the histogram of lengths of words of the input.  Bars will point
 * horizontally (as if there were  many words, vertical bars would require a
 * very complex layout).
 *
 * Considering input of "The quick brown fox jumps over the lazy dog", which contains
 *
 * 4 x 3-char words
 * 2 x 4-char words
 * 3 x 5-char words
 *
 * the output should look like this:
 *
 * 3 (4 w.) ====================
 * 4 (2 w.) ==========
 * 5 (3 w.) ===============
 *
 * Maximum length of the bar (100%) should be 20 symbols
 */
int main() {
    // words cannot have zero length, so we'll use indexes 1..MAX+1
    int word_counts[MAX_WORD_LENGTH + 1], c;
    int current_word_len = 0, state = OUT;

    init_zeroes(word_counts, MAX_WORD_LENGTH + 1);

    while ((c = getchar()) != EOF) {
        if (non_word(c) == TRUE) {
            if (current_word_len > 0) {
                update_count(word_counts, current_word_len, MAX_WORD_LENGTH);
                current_word_len = 0;
            }
            state = OUT;
        } else {
            state = IN;
            current_word_len++;
        }
    }

    print_histogram(word_counts, MAX_WORD_LENGTH);
    return 0;
}


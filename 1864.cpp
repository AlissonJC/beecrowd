/*
 * Beecrowd 1864 — Our Days Are Never Coming Back
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Read an integer N and print the first N characters of a fixed quote
 *   by Kierkegaard. The quote is spelled out by the underlined letters
 *   scattered in the problem statement; spaces are not underlined and
 *   have to be inferred from the natural reading of the sentence. The
 *   constraint N <= 34 matches the length of the quote
 *       "LIFE IS NOT A PROBLEM TO BE SOLVED"
 *   which is exactly 34 characters including its spaces.
 *
 * Input:
 *   A single integer N (1 <= N <= 34).
 *
 * Output:
 *   The first N characters of the quote followed by a newline.
 *
 * Approach:
 *   Hard-code the quote string and emit its first N bytes.
 *
 * Complexity:
 *   O(N), with N <= 34.
 */

#include <cstdio>

int main() {
    // The full Kierkegaard quote, exactly 34 characters long. Indexes
    // 0..n-1 are emitted directly so any prefix prints in the right
    // capital-letters-and-spaces format the problem requires.
    static const char QUOTE[] = "LIFE IS NOT A PROBLEM TO BE SOLVED";

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        putchar(QUOTE[i]);
    }
    putchar('\n');

    return 0;
}

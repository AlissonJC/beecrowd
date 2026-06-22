/*
 * Beecrowd 1435 — Square Matrix I
 * Time limit: 2 s
 *
 * Problem (restated in English):
 *   For each input N, print an N x N matrix where the entry at row i and
 *   column j (0-indexed) is the distance from (i, j) to the nearest edge
 *   plus one. In closed form:
 *       M[i][j] = 1 + min(i, j, N - 1 - i, N - 1 - j)
 *   so the values form concentric "rings": the outer ring is 1, the next
 *   ring inward is 2, and so on. The input is a sequence of integers, one
 *   per line, terminated by 0; that terminating 0 must not be processed.
 *
 * Output format (strict — Beecrowd is picky):
 *   - Each value occupies a field of width 3, right-justified.
 *   - Values within a row are separated by a SINGLE space.
 *   - No trailing space at the end of any row.
 *   - A blank line follows every printed matrix, including the last.
 *
 * Constraints:
 *   0 <= N <= 100. The largest value any cell can hold is 50 (the centre
 *   of an N = 99 or N = 100 matrix), which fits in the width-3 field.
 *
 * Approach:
 *   Stream input until 0. For each N, walk every cell with two nested
 *   loops, compute the ring index (the min of the four edge-distances),
 *   and print it. Printing "%3d" for the first cell of a row and
 *   " %3d" for every subsequent cell guarantees no trailing space.
 *
 * Complexity:
 *   O(N^2) per matrix; with N <= 100 that is at most 10 000 cells and
 *   far inside the 2 s budget.
 */

#include <cstdio>

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Ring index = distance to the closest of the four edges.
                int layer = i;
                if (j < layer)         layer = j;
                if (n - 1 - i < layer) layer = n - 1 - i;
                if (n - 1 - j < layer) layer = n - 1 - j;

                // First cell of a row uses "%3d"; subsequent cells prefix
                // a single space. This ensures no trailing space at the
                // end of the row, which Beecrowd treats as a difference.
                if (j > 0) {
                    printf(" %3d", layer + 1);
                } else {
                    printf("%3d", layer + 1);
                }
            }
            printf("\n");
        }
        // Blank line after every matrix, including the last one.
        printf("\n");
    }
    return 0;
}

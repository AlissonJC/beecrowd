/*
 * Beecrowd 1188 — Inferior Area
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Read an uppercase operation character ('S' for sum, 'M' for average,
 *   "Media" in Portuguese) followed by 144 doubles laid out as a 12 x 12
 *   matrix M in row-major order. Compute either the sum or the arithmetic
 *   mean of the cells that fall inside the inferior (bottom) triangle of
 *   the matrix and print it with exactly one digit after the decimal point.
 *
 *   The two diagonals i == j and i + j == 11 cut the 12 x 12 square into
 *   four triangles. The "inferior" one is everything strictly BELOW both
 *   diagonals, i.e., cells M[i][j] with i > j AND i > 11 - j. By symmetry
 *   it contains 2 + 4 + 6 + 8 + 10 = 30 cells (rows 7..11 contribute
 *   2*(i-6) cells each; rows 0..6 contribute nothing).
 *
 * Input:
 *   Line 1: a single uppercase character, 'S' or 'M'.
 *   Then:   144 floating-point numbers separated by whitespace.
 *
 * Output:
 *   A single number with one decimal place: the sum (if 'S') or the
 *   average (if 'M') of the 30 cells in the inferior triangle.
 *
 * Approach:
 *   Read the operation, fill the 12 x 12 array, scan every cell, and
 *   accumulate values where (i > j && i > 11 - j). The triangle has a
 *   known fixed size of 30 so the average divides the sum by 30 exactly
 *   -- no need to count cells dynamically, but it costs nothing to do so.
 *
 * Complexity:
 *   O(N^2) with N = 12, i.e., 144 cell touches. Trivial for the 1 s limit.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    char op;
    cin >> op;

    double M[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> M[i][j];
        }
    }

    // Accumulate cells strictly below both diagonals of the 12 x 12 square.
    // Condition i > j  keeps cells below the main diagonal (the "\" line);
    // condition i > 11 - j  keeps cells below the anti-diagonal ("/" line).
    // Together they isolate the bottom triangle shown in green in the
    // problem figure.
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (i > j && i > 11 - j) {
                sum += M[i][j];
                count++;
            }
        }
    }

    // 'S' prints the sum; 'M' (for Media / mean) divides by the cell count.
    // The expected count is always 30, but using the running counter keeps
    // the code self-checking in case the geometry is ever revisited.
    double result = (op == 'S') ? sum : sum / count;
    printf("%.1f\n", result);

    return 0;
}

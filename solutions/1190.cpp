/*
 * Beecrowd 1190 — Right Area
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Read an uppercase operation character ('S' for sum, 'M' for average,
 *   "Media" in Portuguese) followed by 144 doubles laid out as a 12 x 12
 *   matrix M in row-major order. Compute either the sum or the arithmetic
 *   mean of the cells that fall inside the RIGHT triangle of the matrix
 *   and print it with exactly one digit after the decimal point.
 *
 *   The two diagonals i == j and i + j == 11 cut the 12 x 12 square into
 *   four triangles. The "right" one is everything strictly RIGHT of both
 *   diagonals, i.e., cells M[i][j] with j > i AND j > 11 - i. By symmetry
 *   it contains 0+1+2+3+4+5+5+4+3+2+1+0 = 30 cells.
 *
 * Input:
 *   Line 1: a single uppercase character, 'S' or 'M'.
 *   Then:   144 floating-point numbers separated by whitespace.
 *
 * Output:
 *   A single number with one decimal place: the sum (if 'S') or the
 *   average (if 'M') of the 30 cells in the right triangle.
 *
 * Approach:
 *   Read the operation, fill the 12 x 12 array, scan every cell, and
 *   accumulate values where (j > i && j > 11 - i). The cell count is the
 *   fixed value 30, but tracking it dynamically keeps the code robust if
 *   the geometry ever changes.
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

    // Accumulate cells strictly right of both diagonals of the 12 x 12 square.
    // Condition j > i  keeps cells right of the main diagonal (the "\" line);
    // condition j > 11 - i  keeps cells right of the anti-diagonal ("/" line).
    // Together they isolate the right triangle shown in green in the figure.
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (j > i && j > 11 - i) {
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

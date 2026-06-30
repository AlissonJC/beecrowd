/*
 * Beecrowd 1182 - Column in Array
 *
 * A 12x12 matrix M is given as 144 floating-point numbers in row-major order.
 * Read a column index C and an operation character, then either sum or average
 * all 12 elements of column C.
 *
 * Input : line 1 - integer C (0 <= C <= 11); line 2 - character T ('S' for Sum,
 *         'M' for average / "Media"); then 144 floating-point numbers.
 * Output: the sum (T = 'S') or the average over the 12 column elements
 *         (T = 'M'), printed with one digit after the decimal point.
 *
 * Approach: the matrix is filled row by row, so the k-th value (0-indexed)
 *           occupies row k/12 and column k%12. The whole matrix never needs to be
 *           stored: while reading, add a value to the running total only when its
 *           column k%12 equals C. A column has exactly 12 elements, so the
 *           average divides the sum by 12 (not by 144).
 *
 * Complexity: O(144) time, O(1) space.
 */
#include <cstdio>

int main() {
    int c;
    char t;
    if (scanf("%d", &c) != 1) return 0;
    if (scanf(" %c", &t) != 1) return 0;  // leading space skips the newline

    double sum = 0.0;
    for (int k = 0; k < 144; ++k) {
        double v;
        if (scanf("%lf", &v) != 1) return 0;
        // Column of the k-th value is k % 12; keep only the target column.
        if (k % 12 == c) sum += v;
    }

    // 'M' averages over the 12 elements of the column; 'S' keeps the raw sum.
    double result = (t == 'M') ? sum / 12.0 : sum;
    printf("%.1f\n", result);

    return 0;
}

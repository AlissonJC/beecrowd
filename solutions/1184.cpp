/*
 * Beecrowd 1184 - Below the Main Diagonal
 *
 * A 12x12 matrix M is given as 144 floating-point numbers in row-major order.
 * Read an operation character and either sum or average the elements that lie
 * strictly below the main diagonal (the green region in the statement).
 *
 * Input : line 1 - character O ('S' for Sum, 'M' for average / "Media"); then
 *         144 floating-point numbers.
 * Output: the sum (O = 'S') or the average (O = 'M') of the sub-diagonal
 *         elements, printed with one digit after the decimal point.
 *
 * Approach: with row-major order the k-th value (0-indexed) is at row k/12 and
 *           column k%12. An element is below the main diagonal exactly when its
 *           row index exceeds its column index (row > col). Accumulate those
 *           values while reading; the region contains 1+2+...+11 = 66 cells, so
 *           the average divides the sum by that count.
 *
 * Complexity: O(144) time, O(1) space.
 */
#include <cstdio>

int main() {
    char o;
    if (scanf(" %c", &o) != 1) return 0;  // leading space skips any whitespace

    double sum = 0.0;
    int count = 0;  // number of summed cells (ends at 66)
    for (int k = 0; k < 144; ++k) {
        double v;
        if (scanf("%lf", &v) != 1) return 0;

        int row = k / 12, col = k % 12;
        if (row > col) {          // strictly below the main diagonal
            sum += v;
            ++count;
        }
    }

    // 'M' averages over the cells actually counted (66); 'S' keeps the sum.
    double result = (o == 'M') ? sum / count : sum;
    printf("%.1f\n", result);

    return 0;
}

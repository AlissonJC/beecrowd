/*
 * Beecrowd 1185 - Above the Secondary Diagonal
 *
 * A 12x12 matrix M is given as 144 floating-point numbers in row-major order.
 * Read an operation character and either sum or average the elements that lie
 * strictly above the secondary (anti-)diagonal (the green region).
 *
 * Input : line 1 - character O ('S' for Sum, 'M' for average / "Media"); then
 *         144 floating-point numbers.
 * Output: the sum (O = 'S') or the average (O = 'M') of those elements, printed
 *         with one digit after the decimal point.
 *
 * Approach: the secondary diagonal of a 12x12 matrix consists of the cells where
 *           row + col == 11. "Above" it means row + col < 11. With row-major
 *           order the k-th value (0-indexed) sits at row k/12 and column k%12, so
 *           accumulate a value when (k/12) + (k%12) < 11. The region holds
 *           11+10+...+1 = 66 cells, hence the average divides by that count.
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
        if (row + col < 11) {     // strictly above the secondary diagonal
            sum += v;
            ++count;
        }
    }

    // 'M' averages over the cells actually counted (66); 'S' keeps the sum.
    double result = (o == 'M') ? sum / count : sum;
    printf("%.1f\n", result);

    return 0;
}

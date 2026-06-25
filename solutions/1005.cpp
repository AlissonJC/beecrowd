/*
 * Beecrowd 1005 - Average 1
 *
 * Read two double-precision grades A and B and print their weighted average,
 * where grade A has weight 3.5 and grade B has weight 7.5.
 *
 * Input : two floating-point values, each with one digit after the decimal
 *         point (each grade ranges from 0 to 10).
 * Output: the line "MEDIA = " followed by the average printed with exactly
 *         five digits after the decimal point, a single blank space on each
 *         side of the '=' sign, and a trailing newline (omitting it causes a
 *         Presentation Error on Beecrowd). MEDIA is "average" in Portuguese --
 *         keep the literal as-is.
 *
 * Approach: the weighted mean is (A * 3.5 + B * 7.5) divided by the sum of the
 *           weights. Since 3.5 + 7.5 = 11.0, divide the weighted sum by 11.0.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    double a, b;
    if (scanf("%lf %lf", &a, &b) != 2) return 0;

    // Weighted average: weights 3.5 and 7.5 sum to 11.0.
    double media = (a * 3.5 + b * 7.5) / 11.0;

    // %.5f prints exactly five decimal places, matching the required format.
    // The blank spaces surrounding '=' are mandatory.
    printf("MEDIA = %.5f\n", media);
    return 0;
}

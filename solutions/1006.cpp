/*
 * Beecrowd 1006 - Average 2
 *
 * Read three double-precision grades A, B and C and print their weighted
 * average, where grade A has weight 2, grade B has weight 3 and grade C has
 * weight 5.
 *
 * Input : three floating-point values, each with one digit after the decimal
 *         point (each grade ranges from 0 to 10).
 * Output: the line "MEDIA = " followed by the average printed with exactly one
 *         digit after the decimal point, a single blank space on each side of
 *         the '=' sign, and a trailing newline (omitting it causes a
 *         Presentation Error on Beecrowd). MEDIA is "average" in Portuguese --
 *         keep the literal as-is.
 *
 * Approach: the weighted mean is (A * 2 + B * 3 + C * 5) divided by the sum of
 *           the weights. Since 2 + 3 + 5 = 10, divide the weighted sum by 10.0.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 0;

    // Weighted average: weights 2, 3 and 5 sum to 10.0.
    double media = (a * 2.0 + b * 3.0 + c * 5.0) / 10.0;

    // %.1f prints exactly one decimal place, matching the required format.
    // The blank spaces surrounding '=' are mandatory.
    printf("MEDIA = %.1f\n", media);
    return 0;
}

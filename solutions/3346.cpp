/*
 * Beecrowd 3346 - GDP Fluctuation
 *
 * The GDP fluctuated by F1 percent in the first year and by F2 percent in the
 * second year, where a positive value means growth and a negative value means
 * decrease. Compute the single percentage fluctuation that describes the whole
 * two-year period.
 *
 * Percentage changes compound multiplicatively, not additively: after the two
 * years the GDP is scaled by (1 + F1/100) * (1 + F2/100). Subtracting 1 and
 * multiplying back by 100 turns that combined factor into a percentage. For
 * F1 = -4, F2 = 5 this gives 0.96 * 1.05 = 1.008 -> 0.800000.
 *
 * Input : two real values F1 and F2 (-100.00 <= F1, F2 <= 100.00), each given
 *         with exactly two decimal places.
 * Output: the combined fluctuation as a percentage, with exactly 6 decimals.
 *
 * Approach: One closed-form expression on the two compounded growth factors.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    double f1, f2;
    if (scanf("%lf %lf", &f1, &f2) != 2)
        return 0;  // malformed input guard; also silences the warning

    // Compound the two yearly growth factors, then convert the net factor back
    // into a percentage change over the whole period.
    double combined = ((1.0 + f1 / 100.0) * (1.0 + f2 / 100.0) - 1.0) * 100.0;

    printf("%.6f\n", combined);
    return 0;
}

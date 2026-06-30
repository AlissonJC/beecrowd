/*
 * Beecrowd 1156 - S Sequence II
 *
 * Compute and print the value of
 *     S = 1 + 3/2 + 5/4 + 7/8 + ... + 39/524288
 * The k-th term has an odd numerator 2k-1 (1, 3, 5, ..., 39) over a power of two
 * 2^(k-1) (1, 2, 4, 8, ...). The numerator reaches 39 when 2k-1 = 39, i.e. at
 * k = 20, so the sum has exactly 20 terms and the final denominator is
 * 2^19 = 524288.
 *
 * Input : none.
 * Output: the value of S with exactly two digits after the decimal point. The
 *         series tends to 6 as terms grow; 20 terms give 5.99992, which rounds
 *         to 6.00.
 *
 * Approach: accumulate the 20 terms while rolling two running values - an odd
 *           numerator advanced by +2 and a denominator doubled each step. The
 *           division is floating-point (the denominator is a double), so no term
 *           is truncated to zero.
 *
 * Complexity: O(1) - a fixed 20-term loop, constant space.
 */
#include <cstdio>

int main() {
    double s = 0.0;
    double denominator = 1.0;  // 2^(k-1): 1, 2, 4, 8, ...

    // Term k = (2k-1) / 2^(k-1) for k = 1..20.
    for (int numerator = 1; numerator <= 39; numerator += 2) {
        s += numerator / denominator;  // double division (denominator is double)
        denominator *= 2.0;            // advance to the next power of two
    }

    // Two digits after the decimal point, as required by the statement.
    printf("%.2f\n", s);

    return 0;
}

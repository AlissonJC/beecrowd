/*
 * Beecrowd 1155 - S Sequence
 *
 * Compute and print the value of the finite harmonic sum
 *     S = 1 + 1/2 + 1/3 + ... + 1/100
 * i.e. the sum of 1/i for i from 1 to 100.
 *
 * Input : none.
 * Output: the value of S printed with exactly two digits after the decimal
 *         point. H(100) = 5.18737..., so the printed result is 5.19.
 *
 * Approach: accumulate 1.0/i in a double over i = 1..100. The numerator is the
 *           literal 1.0 (not 1) so the division is floating-point; using integer
 *           1/i would yield 0 for every i >= 2 and collapse the sum to 1.
 *
 * Complexity: O(1) - a fixed 100-term loop, constant space.
 */
#include <cstdio>

int main() {
    double s = 0.0;

    // Sum the reciprocals 1/1, 1/2, ..., 1/100 in floating point.
    for (int i = 1; i <= 100; ++i) {
        s += 1.0 / i;
    }

    // Two digits after the decimal point, as required by the statement.
    printf("%.2f\n", s);

    return 0;
}

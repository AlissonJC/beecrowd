/*
 * Beecrowd 2161 - "Square Root of 10"
 *
 * The square root of 10 has the periodic continued-fraction expansion
 *     sqrt(10) = 3 + 1/(6 + 1/(6 + 1/(6 + ...)))   i.e. [3; 6, 6, 6, ...].
 * Given N, the number of repeated "6" denominators, compute the resulting
 * truncated continued fraction as an approximation of sqrt(10).
 *
 * Input : a natural number N (0 <= N <= 100): how many denominator repetitions
 *         (sixes) to include. (Read until EOF so multiple queries are handled.)
 * Output: the approximation printed with exactly 10 decimal places.
 *
 * Approach  : evaluate the fraction from the inside out. Let x be the value of
 *             the trailing part 1/(6 + 1/(6 + ...)). Starting from x = 0, each
 *             step wraps one more "6": x = 1 / (6 + x). After N steps x holds
 *             the tail built from N sixes, and the answer is 3 + x. N = 0
 *             leaves x = 0, giving exactly 3, as required.
 * Complexity: O(N) per query. double precision is far more than enough: the
 *             fraction converges geometrically, reaching machine precision long
 *             before N = 100, so 10 correct decimals are guaranteed.
 *
 * Output note: fixed format "%.10f" matches the samples (e.g. "3.0000000000").
 */

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        double x = 0.0;
        // Each iteration adds one more "6 + ..." layer to the tail fraction.
        for (int i = 0; i < n; ++i) {
            x = 1.0 / (6.0 + x);
        }
        // The whole-number part of sqrt(10) is 3; x is the fractional tail.
        printf("%.10f\n", 3.0 + x);
    }
    return 0;
}

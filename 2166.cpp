/*
 * Beecrowd 2166 — Square Root of 2
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Approximate sqrt(2) using the periodic continued fraction
 *       sqrt(2) ~ 1 + 1 / (2 + 1 / (2 + 1 / (2 + ... )))
 *   where N is the number of 2-repetitions in the denominator chain.
 *   Examples from the statement:
 *       N = 0  -> 1
 *       N = 1  -> 1 + 1/2 = 1.5
 *       N = 2  -> 1 + 1/(2 + 1/2) = 1.4
 *   Print the result with exactly 10 decimal places.
 *
 * Input:
 *   A single non-negative integer N (0 <= N <= 100).
 *
 * Output:
 *   The approximate value with 10 digits after the decimal point.
 *
 * Approach:
 *   Build the continued fraction inside-out. For N >= 1, start with the
 *   innermost denominator x = 2, then expand outward by N - 1 steps of
 *   x = 2 + 1/x. The final value is 1 + 1/x. For N = 0 there is no
 *   fraction at all and the answer is just 1.
 *
 *   The recurrence converges rapidly to sqrt(2) (each step roughly
 *   doubles the number of correct digits), so by N >= ~20 the double
 *   value is already at machine precision and stays there until N = 100.
 *
 * Complexity:
 *   O(N) arithmetic operations. Trivial for N <= 100.
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    double result;
    if (n == 0) {
        // No denominator chain at all: the expansion degenerates to 1.
        result = 1.0;
    } else {
        // Innermost denominator. Each iteration wraps another "2 + 1/..."
        // layer around the current value; doing this N - 1 times leaves
        // exactly N twos chained together. Finally combine with the
        // outer "1 +" to get the full continued fraction value.
        double x = 2.0;
        for (int i = 1; i < n; i++) {
            x = 2.0 + 1.0 / x;
        }
        result = 1.0 + 1.0 / x;
    }

    printf("%.10f\n", result);
    return 0;
}

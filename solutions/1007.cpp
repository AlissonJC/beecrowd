/*
 * Beecrowd 1007 - Difference
 *
 * Read four integer values A, B, C and D. Compute and print the difference
 * between the product of A and B and the product of C and D, that is,
 * (A * B) - (C * D).
 *
 * Input : four integer values.
 * Output: the line "DIFERENCA = " followed by (A * B) - (C * D), a single
 *         blank space on each side of the '=' sign, and a trailing newline
 *         (omitting it causes a Presentation Error on Beecrowd). DIFERENCA is
 *         "difference" in Portuguese -- keep the literal, all uppercase.
 *
 * Approach: a direct arithmetic evaluation. Use 64-bit integers so the two
 *           products cannot overflow even if the inputs are large (the
 *           statement gives no explicit bound), which is the usual silent
 *           cause of a Wrong Answer here.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    long long a, b, c, d;
    if (scanf("%lld %lld %lld %lld", &a, &b, &c, &d) != 4) return 0;

    // 64-bit products avoid overflow; negative inputs work without any
    // special handling (e.g. C = -7 simply flips the sign of C * D).
    long long diferenca = a * b - c * d;

    // The blank spaces surrounding '=' are mandatory.
    printf("DIFERENCA = %lld\n", diferenca);
    return 0;
}

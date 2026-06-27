/*
 * Beecrowd 2172 — Event
 * Time limit: 2 s
 *
 * Problem (restated in English):
 *   During a special game event, every monster's experience value is
 *   multiplied by a factor X. Given the factor X and a monster's base
 *   experience M, report the monster's new experience E during the
 *   event. The relation is simply E = X * M.
 *
 * Input:
 *   Several test cases, one per line, each with two integers:
 *     X (0 < X <= 3)            -- the experience multiplier
 *     M (10 <= M <= 2^32 - 1)   -- the monster's base experience
 *   Input ends with the line "0 0", which must NOT be processed.
 *
 * Output:
 *   For each test case, one line with E = X * M.
 *
 * Approach:
 *   Pure arithmetic. The only real trap is integer width: M can reach
 *   2^32 - 1 = 4294967295, which already overflows a signed 32-bit int,
 *   and the product X * M can reach 3 * (2^32 - 1) = 12884901885, far
 *   beyond 32 bits. Read both values into 64-bit integers so the
 *   multiplication never overflows.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <cstdio>

int main() {
    long long x, m;

    // Read pairs until the terminating "0 0" sentinel. Since valid X is
    // always > 0, x == 0 alone already marks the end, but the statement
    // guarantees both fields are zero on the final line.
    while (scanf("%lld %lld", &x, &m) == 2) {
        if (x == 0 && m == 0) break;

        // 64-bit product: with x <= 3 and m <= 2^32 - 1 the result fits
        // comfortably in long long (max ~1.29e10), no overflow possible.
        printf("%lld\n", x * m);
    }

    return 0;
}

/*
 * Beecrowd 1144 - Logical Sequence
 *
 * Read an integer N. For each i from 1 to N, print two lines:
 *     i   i^2     i^3
 *     i   i^2+1   i^3+1
 * giving 2*N lines in total. The statement warns that numbers with more than
 * six digits must be printed in full -- using integer types with %d guarantees
 * there is never any scientific notation (the trap would be using float/double).
 *
 * Input : a single integer N, with 1 < N < 1000.
 * Output: 2*N lines, three single-space separated integers each, every line
 *         ended by a newline (Beecrowd flags a missing newline as PE).
 *
 * Approach: a direct loop from 1 to N emitting the two lines per i. With
 *           N < 1000 the largest value printed is 999^3 + 1 = 997003000, which
 *           still fits in a signed 32-bit int, so no wider type is needed.
 *
 * Complexity: O(N) time, O(1) extra space.
 */

#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; ++i) {
        int sq = i * i;   // i^2
        int cb = sq * i;  // i^3 -- fits int: 999^3 = 997002999 < 2^31 - 1

        // First line of the pair: i, its square, its cube.
        printf("%d %d %d\n", i, sq, cb);
        // Second line of the pair: same i, with square and cube each plus one.
        printf("%d %d %d\n", i, sq + 1, cb + 1);
    }

    return 0;
}

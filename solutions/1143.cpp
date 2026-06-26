/*
 * Beecrowd 1143 - Squared and Cubic
 *
 * Read an integer N (1 < N < 1000). For each integer i from 1 to N, print i,
 * its square i^2, and its cube i^3 on a single line, separated by single
 * spaces.
 *
 * Input : a single integer N, with 1 < N < 1000.
 * Output: N lines; line i contains "i i^2 i^3" (single-space separated), each
 *         line ended by a newline (Beecrowd flags a missing newline as PE).
 *
 * Approach: a direct loop from 1 to N printing the three powers. With N < 1000
 *           the largest value printed is 999^3 = 997002999, which still fits in
 *           a signed 32-bit int, so no wider type is required.
 *
 * Complexity: O(N) time, O(1) extra space.
 */

#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; ++i) {
        // Print i, i squared, i cubed. The product i*i*i stays within int range
        // because the maximum, 999^3 = 997002999, is below 2^31 - 1.
        printf("%d %d %d\n", i, i * i, i * i * i);
    }

    return 0;
}

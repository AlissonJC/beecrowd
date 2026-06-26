/*
 * Beecrowd 1149 - Summing Consecutive Integers
 *
 * Read a value A and a value N, then print the sum of the N consecutive
 * integers starting at A: A + (A+1) + (A+2) + ... + (A+N-1). N must be a
 * positive count: while the N just read is negative or zero, keep reading a
 * new N (and only N -- A stays fixed) until a positive value appears. A is read
 * exactly once. All input values lie on the same line.
 *
 * Input : integers on one line -- first A, then one or more candidate values
 *         for N; the first strictly positive one is the count to use.
 * Output: a single integer, the computed sum, followed by a newline.
 *
 * Approach: read A together with the first N, then loop reading replacement N
 *           values while N <= 0. Finally accumulate the N consecutive integers
 *           from A. The sum is kept in a 64-bit integer so it cannot overflow.
 *
 * Complexity: O(N) time for the accumulation, O(1) extra space.
 */

#include <cstdio>

int main() {
    long long a, n;
    // Read A together with the first candidate for N.
    if (scanf("%lld %lld", &a, &n) != 2) return 0;

    // N must be a positive count: discard non-positive values and read again,
    // reading ONLY N (A stays fixed) until a strictly positive N is found.
    while (n <= 0) {
        if (scanf("%lld", &n) != 1) return 0;
    }

    // Sum the N consecutive integers A, A+1, ..., A+N-1. A 64-bit accumulator
    // avoids overflow when the count or the values are large.
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += a + i;
    }

    printf("%lld\n", sum);
    return 0;
}

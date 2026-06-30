/*
 * Beecrowd 1164 - Perfect Number
 *
 * A perfect number equals the sum of all its positive divisors excluding itself
 * (e.g. 6 = 1 + 2 + 3). Given several integers, report for each whether it is
 * perfect.
 *
 * Input : first line N, the number of test cases (1 <= N <= 100). Each of the
 *         next N lines holds one integer X (1 <= X <= 10^8).
 * Output: for each X print "X eh perfeito" if X is perfect, otherwise
 *         "X nao eh perfeito". The messages are Portuguese and ASCII, copied
 *         exactly from the statement (no accents).
 *
 * Approach: sum the proper divisors of X by scanning candidate divisors i only
 *           up to sqrt(X); whenever i divides X, both i and the paired divisor
 *           X/i are added (skipping the duplicate when X is a perfect square).
 *           With X <= 10^8 the inner loop runs at most ~10^4 times, so 100 cases
 *           cost about 10^6 operations - far inside the time limit.
 *
 * Edge cases: X = 1 has no proper divisor, so its sum is 0 and it is not perfect.
 *           1 must NOT be seeded into the running sum for X = 1.
 *
 * Complexity: O(N * sqrt(maxX)) time, O(1) space.
 */
#include <cstdio>

// Sum of the positive divisors of x strictly smaller than x.
long long sumProperDivisors(long long x) {
    if (x == 1) return 0;          // 1 has no proper divisor besides nothing.

    long long sum = 1;             // For x > 1, 1 is always a proper divisor.
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            sum += i;
            long long paired = x / i;
            // Add the paired divisor only when it differs from i, otherwise a
            // perfect square would count its square root twice.
            if (paired != i) sum += paired;
        }
    }
    return sum;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        long long x;
        if (scanf("%lld", &x) != 1) break;  // stop early on malformed/short input

        // Perfect exactly when the proper-divisor sum reproduces the number.
        if (sumProperDivisors(x) == x) {
            printf("%lld eh perfeito\n", x);
        } else {
            printf("%lld nao eh perfeito\n", x);
        }
    }

    return 0;
}

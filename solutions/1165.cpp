/*
 * Beecrowd 1165 - Prime Number
 *
 * A prime number is divisible only by 1 and by itself (e.g. 7). Given several
 * integers, report for each whether it is prime.
 *
 * Input : first line N, the number of test cases (1 <= N <= 100). Each of the
 *         next N lines holds one integer X (1 < X <= 10^7).
 * Output: for each X print "X eh primo" if X is prime, otherwise "X nao eh
 *         primo". The messages are Portuguese and ASCII, copied exactly from the
 *         statement (no accents).
 *
 * Approach: trial division. Reject even numbers immediately, then test only odd
 *           divisors i from 3 up to sqrt(X); if none divides X, X is prime. With
 *           X <= 10^7 the loop runs at most ~1600 odd steps, so 100 cases cost
 *           well under 10^6 operations.
 *
 * Complexity: O(N * sqrt(maxX)) time, O(1) space.
 */
#include <cstdio>

// True when x (>= 2) has no divisor other than 1 and itself.
bool isPrime(long long x) {
    if (x < 2) return false;          // not reachable given X > 1, kept for safety
    if (x == 2) return true;          // the only even prime
    if (x % 2 == 0) return false;     // every other even number is composite

    // Only odd candidates remain; test 3, 5, 7, ... up to sqrt(x).
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        long long x;
        if (scanf("%lld", &x) != 1) break;  // stop early on short/malformed input

        if (isPrime(x)) {
            printf("%lld eh primo\n", x);
        } else {
            printf("%lld nao eh primo\n", x);
        }
    }

    return 0;
}

/*
 * Beecrowd 1457 — Oracle of Alexandria
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   The K-factor of an integer N (often written as N followed by K
 *   exclamation marks) is the product
 *       N * (N - K) * (N - 2K) * (N - 3K) * ...
 *   continued as long as each factor is at least 1. So 3! is 3*2*1 = 6,
 *   4!! is 4*2 = 8, 10!!! is 10*7*4*1 = 280, and 19!!!! is
 *   19*15*11*7*3 = 65835. Given several test cases, compute and print
 *   the K-factor for each.
 *
 * Input:
 *   Line 1: T -- the number of test cases.
 *   Next T lines: each is an integer N followed immediately (no space)
 *   by K exclamation marks, where 1 <= N <= 100 and 1 <= K <= 20.
 *
 * Output (per case):
 *   One line containing the K-factor of N.
 *
 * Approach:
 *   Read N as a number with scanf, then count the consecutive '!' bytes
 *   on the rest of the line to recover K. Multiply N, N-K, N-2K, ...
 *   into an accumulator while the current factor is >= 1. The problem
 *   guarantees the answer fits in 10^18, so a signed long long (max
 *   ~9.2 * 10^18) is safe.
 *
 * Complexity:
 *   O(N/K) factors per case (at most ~100), trivial across T cases.
 */

#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        // After scanf consumes N, the '!' run sits on the same line.
        // Read characters until the terminating newline, tallying '!'.
        // EOF guard is here in case the final line lacks a trailing \n.
        int k = 0;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c == '!') k++;
        }

        // Walk factors N, N-K, N-2K, ... and keep those still >= 1.
        // Using long long because the product can reach up to 10^18.
        long long product = 1;
        for (long long f = n; f >= 1; f -= k) {
            product *= f;
        }

        printf("%lld\n", product);
    }
    return 0;
}

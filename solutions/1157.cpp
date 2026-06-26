/*
 * Beecrowd 1157 - "Divisors I"
 *
 * Read an integer N and print all of its positive divisors, one per line,
 * in increasing order.
 *
 * Input : a single integer N (N >= 1).
 * Output: each positive divisor of N on its own line.
 *         e.g. N = 6  ->  1 / 2 / 3 / 6 (one per line)
 *
 * Approach: test every candidate i from 1 up to N; i divides N exactly when
 * N % i == 0, so print those. Scanning upward yields the divisors already in
 * ascending order, matching the required output without any sorting.
 *
 * Complexity: O(N) divisibility tests, O(1) space.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // A number i is a divisor of N exactly when the remainder is zero.
    // Iterating from 1 upward prints the divisors in increasing order.
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            cout << i << "\n";
        }
    }

    return 0;
}

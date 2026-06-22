/*
 * Beecrowd 3089 — Christmas Gifts
 * Time limit: 1 s
 *
 * Multiple test cases, terminated by n = 0. Each case has n
 * (2 <= n <= 10^4) and 2n gift values (1 <= x_i <= 10^8) given in
 * descending order. Pair the gifts so that the gap between the most
 * expensive and cheapest pair-total is as small as possible, and
 * print "most_expensive cheapest".
 *
 * Why the simple pairing works:
 *   Given values sorted descending, pairing the i-th largest with the
 *   i-th smallest (i.e. x_i with x_{2n-1-i}) is the standard min-max
 *   pairing on a sorted array. Any swap between two pairs cannot
 *   shrink the gap: see the classic exchange argument used for
 *   "minimum difference between max and min pair sum".
 *
 * Complexity:
 *   O(n) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int total = 2 * n;
        vector<long long> x(total);
        for (int i = 0; i < total; i++) scanf("%lld", &x[i]);

        long long maxPair = LLONG_MIN, minPair = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long s = x[i] + x[total - 1 - i];
            if (s > maxPair) maxPair = s;
            if (s < minPair) minPair = s;
        }
        printf("%lld %lld\n", maxPair, minPair);
    }
    return 0;
}

/*
 * Beecrowd 2715 — Splitting Assignments I
 * Time limit: 1 s
 *
 * Multiple test cases (EOF-terminated). Each test case has N values
 * X_1..X_N (1 <= N <= 10^6, 1 <= X_i <= 10^5). Rangel does the first
 * k assignments and Gugu the remaining N-k (the order cannot change).
 * Print the smallest possible |sum(first k) - sum(last N-k)| across
 * all valid splits. Leave a blank line after every test case
 * (including the last).
 *
 * Approach:
 *   Let S = total sum and P_k = sum of the first k values. Then the
 *   workloads are P_k and S - P_k, with absolute difference
 *   |2*P_k - S|. Walk through k = 0..N, keep the minimum. Total sum
 *   can reach 10^6 * 10^5 = 10^11, so use 64-bit arithmetic.
 *
 * Complexity:
 *   O(N) per test case, single linear pass.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        vector<long long> X(N);
        long long total = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lld", &X[i]);
            total += X[i];
        }

        // k = 0 is allowed -- Rangel takes nothing, Gugu does everything.
        long long best = total;
        long long prefix = 0;
        for (int i = 0; i < N; i++) {
            prefix += X[i];
            long long diff = llabs(prefix - (total - prefix));
            if (diff < best) best = diff;
        }

        printf("%lld\n", best);
    }
    return 0;
}

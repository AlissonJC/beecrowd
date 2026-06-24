/*
 * Beecrowd 2823 - Earliest Deadline First
 *
 * Decide whether a set of periodic real-time tasks is schedulable on one
 * preemptive core under EDF. Each task has a computational cost C and a period P
 * (its relative deadline). Print "OK" if the set can be scheduled, else "FAIL".
 *
 * Input : N (1 <= N <= 10); then N lines "C P" with 1 <= C <= 5, C <= P <= 100.
 * Output: "OK" or "FAIL".
 *
 * Approach: EDF is optimal for periodic tasks whose deadlines equal their
 *   periods, so the set is schedulable exactly when the processor utilization
 *   U = sum(C_i / P_i) is at most 1. Because U can equal 1 exactly (or miss the
 *   bound by a vanishingly small amount), compare with exact integers instead of
 *   floating point: let L = lcm(P_i) and test  sum(C_i * (L / P_i)) <= L. The sum
 *   can reach ~1e20, so accumulate it in __int128.
 *
 * Complexity: O(N) per test case.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {                       // single case, loop kept for safety
        vector<ll> C(n), P(n);
        for (int i = 0; i < n; ++i) cin >> C[i] >> P[i];

        // L = lcm of all periods. Computed as L/gcd*P (divide first) so the
        // intermediate value never exceeds the final lcm (< 4e18, fits in 64 bits).
        ll L = 1;
        for (int i = 0; i < n; ++i) L = L / __gcd(L, P[i]) * P[i];

        // U <= 1  <=>  sum(C_i * L / P_i) <= L, done exactly in 128 bits.
        __int128 used = 0;
        for (int i = 0; i < n; ++i) used += (__int128)C[i] * (L / P[i]);

        cout << (used <= (__int128)L ? "OK" : "FAIL") << "\n";
    }
    return 0;
}

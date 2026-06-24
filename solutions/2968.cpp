/*
 * Beecrowd 2968 - Hour for a Run
 *
 * A runner does V laps on a track with N equally spaced signs, so a full workout
 * passes V*N signs. For each milestone 10%, 20%, ..., 90% of the workout, report
 * how many signs must be counted to guarantee at least that fraction is done.
 *
 * Input : a single line with V and N (1 <= V, N <= 1e4).
 * Output: nine integers (for 10%..90%) on one line, space separated.
 *
 * Approach: the whole workout is T = V*N signs. To have completed at least p% one
 *   needs the smallest count k with k >= p*T/100, i.e. k = ceil(p*T/100). Compute
 *   it with integer arithmetic as (p*T + 99) / 100. Since p*T can reach 9e9, use
 *   64-bit integers.
 *
 * Complexity: O(1) (nine fixed milestones) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long v, n;
    while (cin >> v >> n) {
        long long total = v * n;                 // signs in a full workout
        for (int p = 10; p <= 90; p += 10) {
            long long need = (p * total + 99) / 100;   // ceil(p% of total)
            cout << need << (p < 90 ? ' ' : '\n');      // single spaces, no trailing one
        }
    }
    return 0;
}

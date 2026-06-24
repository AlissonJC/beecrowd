/*
 * Beecrowd 2769 - Assembly Line
 *
 * A chassis is built by passing through N ordered steps, each available on two
 * parallel assembly lines. Entering line i costs e_i, doing step j on line i
 * costs a_i[j], and moving between lines after step j costs t1[j] (line 1 -> 2)
 * or t2[j] (line 2 -> 1); leaving line i costs x_i. Find the least total time to
 * finish one item.
 *
 * Input : multiple cases (EOF). Per case: N; then e1 e2; then N step times for
 *         line 1; N step times for line 2; N-1 switch costs line1->line2; N-1
 *         switch costs line2->line1; finally x1 x2. (1 <= N <= 1000, values up
 *         to 1e5.)
 * Output: the minimum production time, one per case.
 *
 * Approach: the standard assembly-line scheduling DP. Let f1[j], f2[j] be the
 *   least time to have step j done on line 1 or line 2. Each can either continue
 *   on the same line or switch from the other line after step j-1:
 *       f1[j] = min(f1[j-1], f2[j-1] + t2[j-1]) + a1[j]
 *       f2[j] = min(f2[j-1], f1[j-1] + t1[j-1]) + a2[j]
 *   with f*[0] = e* + a*[0]; the answer adds the exit costs. Two rolling scalars
 *   suffice, so it is O(N) per case.
 *
 * Complexity: O(N) time, O(N) space per case.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        ll e1, e2;
        cin >> e1 >> e2;
        vector<ll> a1(N), a2(N), t1(N - 1), t2(N - 1);
        for (auto &v : a1) cin >> v;        // step times, line 1
        for (auto &v : a2) cin >> v;        // step times, line 2
        for (auto &v : t1) cin >> v;        // switch line 1 -> line 2 (N-1 of them)
        for (auto &v : t2) cin >> v;        // switch line 2 -> line 1
        ll x1, x2;
        cin >> x1 >> x2;

        ll f1 = e1 + a1[0];                  // best time with step 0 on line 1
        ll f2 = e2 + a2[0];                  // ... on line 2
        for (int j = 1; j < N; ++j) {
            // Either stay on the line or pay the switch cost from the other line.
            ll nf1 = min(f1, f2 + t2[j - 1]) + a1[j];
            ll nf2 = min(f2, f1 + t1[j - 1]) + a2[j];
            f1 = nf1; f2 = nf2;
        }
        cout << min(f1 + x1, f2 + x2) << "\n";
    }
    return 0;
}

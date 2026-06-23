/*
 * Beecrowd 2963 - Buffoon
 *
 * N candidates receive votes, listed in registration order. The most voted wins;
 * ties are broken in favor of whoever registered first. Carlos registered first
 * (candidate 1), so decide whether he is elected.
 *
 * Input : N (2 <= N <= 1e4); then N vote counts, one per line, in registration
 *         order (total <= 100000). (Read until EOF to be safe.)
 * Output: "S" if Carlos wins, "N" otherwise.
 *
 * Approach: Carlos wins exactly when his vote count is the maximum. Since he
 *   registered first, any tie at the top is his, so he loses only if some other
 *   candidate has strictly more votes than he does.
 *
 * Complexity: O(N) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int carlos;
        cin >> carlos;                       // votes of candidate 1 (Carlos)
        bool win = true;
        for (int i = 1; i < n; ++i) {
            int v;
            cin >> v;
            if (v > carlos) win = false;     // a strictly more voted rival beats him
        }
        cout << (win ? "S" : "N") << "\n";
    }
    return 0;
}

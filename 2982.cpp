/*
 * Beecrowd 2982 - The Strike Stops or Continues?
 *
 * Several monetary values are cited in a meeting: each is either a government
 * grant (type 'V') or a university expense (type 'G'). Sum each kind and decide
 * whether the grants are enough to cover the expenses.
 *
 * Input : N (1 <= N <= 100000); then N lines "T C" where T is 'V' (grant) or 'G'
 *         (expense) and C (1 <= C <= 100000) is the value. (Read until EOF.)
 * Output: "A greve vai parar." if total grants >= total expenses, otherwise
 *         "NAO VAI TER CORTE, VAI TER LUTA!".
 *
 * Approach: accumulate grants and expenses separately, then compare. The totals
 *   can reach 1e5 * 1e5 = 1e10, so use 64-bit integers.
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
        long long grants = 0, expenses = 0;
        for (int i = 0; i < n; ++i) {
            char t; long long c;
            cin >> t >> c;
            if (t == 'V') grants += c;          // 'V' = government grant
            else          expenses += c;        // 'G' = university expense
        }
        // Portuguese verdicts, kept exactly as the judge expects.
        cout << (grants >= expenses ? "A greve vai parar."
                                    : "NAO VAI TER CORTE, VAI TER LUTA!") << "\n";
    }
    return 0;
}

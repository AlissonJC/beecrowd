/*
 * Beecrowd 2812 - Laercio
 *
 * For each list, keep only the odd numbers and reorder them so the first value
 * is the largest, the second the smallest, the third the second largest, the
 * fourth the second smallest, and so on, alternating from the extremes inward.
 *
 * Input : N test cases. Each starts with M (list size, 0 < M < 100) followed by
 *         M integers (0 < Mi < 1000).
 * Output: the reordered odd numbers separated by spaces, one line per test case
 *         (an empty line when the list has no odd numbers).
 *
 * Approach: collect the odd values and sort them ascending. Then walk two
 *   pointers, one at each end, taking the largest, then the smallest, then the
 *   next largest, then the next smallest, until they meet. The pointer scheme
 *   naturally handles an odd count (the middle element is taken from the high
 *   side) and an empty result (nothing to print -> blank line).
 *
 * Complexity: O(M log M) per test case for the sort.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        int m;
        cin >> m;
        vector<int> odd;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if (x % 2 == 1) odd.push_back(x);   // keep only odd numbers
        }
        sort(odd.begin(), odd.end());

        // Alternate from the ends: high, low, high, low, ...
        int lo = 0, hi = (int)odd.size() - 1;
        bool takeHigh = true;
        for (bool first = true; lo <= hi; takeHigh = !takeHigh, first = false) {
            if (!first) cout << ' ';
            cout << (takeHigh ? odd[hi--] : odd[lo++]);
        }
        cout << "\n";                            // blank line if no odd numbers
    }
    return 0;
}

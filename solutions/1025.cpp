/*
 * Beecrowd 1025 - Where is the Marble?
 * Platform: Beecrowd
 *
 * Problem restatement:
 *   Marbles carry numbers and are laid out in ascending order. For each query x,
 *   report the position (1-based) of the FIRST marble whose number equals x, or
 *   say it is not present.
 *
 * Input  : multiple test cases until a line "0 0". Each case starts with N (the
 *          number of marbles) and Q (the number of queries); then N marble
 *          numbers in arbitrary order; then Q query numbers. Values are in
 *          [0, 10000].
 * Output : for each case, first a header line "CASE# k:" (k = 1-based case
 *          number); then, per query, "x found at y" if the first marble with
 *          number x is at position y, otherwise "x not found".
 *
 * Sample:
 *   marbles 2 3 5 1 -> sorted 1 2 3 5 ; query 5 -> "5 found at 4"
 *   marbles 1 3 3 3 1 -> sorted 1 1 3 3 3 ; query 2 -> "2 not found",
 *                                            query 3 -> "3 found at 3"
 *
 * Approach:
 *   Sort the marbles once per case (O(N log N)). Each query is then answered by
 *   a binary search for the first element >= x (lower_bound): if that element
 *   exists and equals x, its index+1 is the first matching position; otherwise x
 *   is absent. lower_bound is what gives the FIRST occurrence among duplicates.
 *
 * Complexity:
 *   O(N log N + Q log N) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, caseNum = 0;
    // Stop on the terminating "0 0" case.
    while (scanf("%d %d", &n, &q) == 2 && (n || q)) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a.begin(), a.end());

        printf("CASE# %d:\n", ++caseNum);
        while (q--) {
            int x;
            scanf("%d", &x);
            // First index whose value is >= x; it matches only if value == x.
            int pos = (int)(lower_bound(a.begin(), a.end(), x) - a.begin());
            if (pos < n && a[pos] == x)
                printf("%d found at %d\n", x, pos + 1);   // positions are 1-based
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}

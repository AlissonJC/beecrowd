/*
 * Beecrowd 2785 - Pyramid
 *
 * An N x N matrix of boxes (each with a positive weight) stands against a wall.
 * Remove boxes to leave a "pyramid": line i (line 1 is the top) must hold exactly
 * i consecutive boxes, and every kept box must have the box directly below it kept
 * as well. Find the minimum possible total weight of such a pyramid.
 *
 * Input : N (1 <= N <= 100), then N lines of N integers (weights in [1, 100]).
 * Output: a single integer, the minimum total weight of a valid pyramid.
 *
 * Structure: the support rule (a box needs the one below it) forces line i's
 *   columns to be contained in line i+1's. As the segment length grows by exactly
 *   one per line, each line is the line above it stretched by one column to the
 *   left or to the right; the bottom line spans the whole row.
 *
 * DP: let dp[i][L] be the minimum weight of the top i+1 lines when line i (0-based)
 *   occupies columns [L, L+i]. Its line above sits at [L, L+i-1] or [L+1, L+i],
 *   so
 *       dp[i][L] = segSum(i, L) + min(dp[i-1][L], dp[i-1][L+1]),
 *   with dp[0][L] = w[0][L]. The answer is dp[N-1][0] (the full bottom row).
 *   Row prefix sums give each segment sum in O(1).
 *
 * Complexity: O(N^2) time and space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> w(n, vector<int>(n));
    for (auto &row : w)
        for (auto &x : row) cin >> x;

    // Per-row prefix sums: pre[i][j] = sum of w[i][0..j-1].
    vector<vector<long long>> pre(n, vector<long long>(n + 1, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) pre[i][j + 1] = pre[i][j] + w[i][j];

    const long long INF = LLONG_MAX / 4;
    vector<long long> prev(n, INF), cur(n, INF);

    // Top line: a single box may sit at any column.
    for (int L = 0; L < n; ++L) prev[L] = w[0][L];

    for (int i = 1; i < n; ++i) {
        int len = i + 1;                       // line i holds i+1 consecutive boxes
        fill(cur.begin(), cur.end(), INF);
        for (int L = 0; L + len <= n; ++L) {
            long long seg = pre[i][L + len] - pre[i][L];
            // Extend the line above (which ends at L or starts at L+1) downward.
            cur[L] = seg + min(prev[L], prev[L + 1]);
        }
        prev.swap(cur);
    }

    // The bottom line must span the entire row, i.e. start at column 0.
    cout << prev[0] << "\n";
    return 0;
}

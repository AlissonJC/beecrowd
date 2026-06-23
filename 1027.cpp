/*
 * Beecrowd 1027 - Critical Wave
 *
 * Draw a wave that oscillates about a horizontal major axis y = a, touching only
 * heights a-1 ("low") and a+1 ("high"); successive points differ by 2 in y, so
 * along the curve the heights strictly alternate high/low, and every point has a
 * distinct x. Given a set of 2D points, choose a (and a subset of the points) to
 * include as many points as possible on such a wave; report that maximum count.
 *
 * Input : several test cases until EOF. Each starts with N, then N lines "x y"
 *         (coordinates fit in a signed 16-bit integer, N <= 1000).
 * Output: per test case, the largest number of points that lie on one valid wave.
 *
 * Approach: a point of height y can only serve as a high point for axis a = y-1
 *   or a low point for a = y+1, so the only axes worth testing are {y-1, y+1}
 *   over the present y values. For a fixed a, gather the x's at height a+1 (high)
 *   and a-1 (low); each distinct x is a "column" offering H, L, or both. Sweeping
 *   columns left to right, a two-state DP keeps the best alternating run ending
 *   in a high or a low point:
 *       if column has H: dpH = max(dpH, dpL + 1)
 *       if column has L: dpL = max(dpL, dpH + 1)
 *   (using the pre-update dpH/dpL, since a column contributes at most one point).
 *   The answer is the best max(dpH, dpL) across all candidate axes.
 *
 * Complexity: each height list feeds exactly two axes, so all the DP sweeps cost
 *   O(N) total per case; grouping/sorting is O(N log N).
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        // Group x-coordinates by height y; keep each list sorted and unique so a
        // repeated point never inflates a column.
        unordered_map<int, vector<int>> byY;
        byY.reserve(n * 2 + 1);
        for (int i = 0; i < n; ++i) {
            int x, y;
            if (scanf("%d %d", &x, &y) != 2) { x = y = 0; }
            byY[y].push_back(x);
        }
        for (auto &kv : byY) {
            auto &v = kv.second;
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }

        // Candidate axes: a = y-1 (use height y as high) and a = y+1 (as low).
        set<int> cand;
        for (auto &kv : byY) { cand.insert(kv.first - 1); cand.insert(kv.first + 1); }

        int ans = 0;
        for (int a : cand) {
            const vector<int> *hp = nullptr, *lp = nullptr;
            auto ith = byY.find(a + 1); if (ith != byY.end()) hp = &ith->second;
            auto itl = byY.find(a - 1); if (itl != byY.end()) lp = &itl->second;
            int hs = hp ? (int)hp->size() : 0;
            int ls = lp ? (int)lp->size() : 0;

            // Merge the two sorted x-lists into columns and run the DP in one pass.
            int i = 0, j = 0, dpH = 0, dpL = 0;
            while (i < hs || j < ls) {
                int x;
                if (i < hs && j < ls) x = min((*hp)[i], (*lp)[j]);
                else if (i < hs)      x = (*hp)[i];
                else                  x = (*lp)[j];
                int mask = 0;                       // bit0 = high here, bit1 = low here
                if (i < hs && (*hp)[i] == x) { mask |= 1; ++i; }
                if (j < ls && (*lp)[j] == x) { mask |= 2; ++j; }
                int newH = dpH, newL = dpL;
                if (mask & 1) newH = max(dpH, dpL + 1);
                if (mask & 2) newL = max(dpL, dpH + 1);
                dpH = newH; dpL = newL;
            }
            ans = max(ans, max(dpH, dpL));
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
 * Beecrowd 1112 - Schweisen
 * Platform: Beecrowd
 *
 * Problem restatement:
 *   On an X-by-Y field, process a stream of messages. "A N X Y" reports that N
 *   schweisen were found at cell (X,Y) (a point add). "P X Y Z W" asks how much
 *   money is needed to kill every schweisen inside the axis-aligned rectangle
 *   with opposite corners (X,Y) and (Z,W): that is (total schweisen in the
 *   rectangle) * P, where P is the per-kill price. The two corners may be given
 *   in any order. At the start the field is empty.
 *
 * Input  : several test cases. Each starts with X, Y, P (field width, height,
 *          price; all <= 1000, P <= 10), then Q (<= 10000), then Q messages of
 *          the two forms above (N <= 10; 0 <= coord < the matching dimension).
 *          Ends with a line "0 0 0".
 * Output : for each "P" message, the money. A blank line after each test case.
 *
 * Approach:
 *   Adds and queries are interleaved, so a static prefix sum will not do -- use a
 *   2D Fenwick tree (BIT) for online point-add and rectangle-sum. A rectangle sum
 *   is the usual inclusion-exclusion of four prefix sums. Coordinates are 0-based
 *   and shifted to 1-based for the BIT. The query corners are normalized with
 *   min/max so either ordering works. The BIT is cleared between test cases.
 *
 * Complexity:
 *   O(Q log X log Y) per test case; with X,Y <= 1000 each op is ~10*10 steps.
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;                 // covers 1-based indices up to 1001
int bit2d[MAXN][MAXN];

static inline void update(int x, int y, int val) {
    for (int i = x; i < MAXN; i += i & (-i))
        for (int j = y; j < MAXN; j += j & (-j))
            bit2d[i][j] += val;
}
static inline long long prefix(int x, int y) {   // sum over [1..x] x [1..y]
    long long s = 0;
    for (int i = x; i > 0; i -= i & (-i))
        for (int j = y; j > 0; j -= j & (-j))
            s += bit2d[i][j];
    return s;
}
// Inclusive rectangle sum, 1-based coordinates.
static inline long long rectSum(int x1, int y1, int x2, int y2) {
    return prefix(x2, y2) - prefix(x1 - 1, y2) - prefix(x2, y1 - 1) + prefix(x1 - 1, y1 - 1);
}

int main() {
    int X, Y, P;
    while (scanf("%d %d %d", &X, &Y, &P) == 3 && (X || Y || P)) {
        memset(bit2d, 0, sizeof(bit2d));     // fresh empty field per test case
        int q;
        scanf("%d", &q);
        while (q--) {
            char type;
            scanf(" %c", &type);
            if (type == 'A') {
                int n, x, y;
                scanf("%d %d %d", &n, &x, &y);
                update(x + 1, y + 1, n);      // point add (shift to 1-based)
            } else {                          // 'P' query
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int xl = min(x1, x2), xh = max(x1, x2);   // corners in any order
                int yl = min(y1, y2), yh = max(y1, y2);
                long long cnt = rectSum(xl + 1, yl + 1, xh + 1, yh + 1);
                printf("%lld\n", cnt * (long long)P);     // money = kills * price
            }
        }
        printf("\n");                         // blank line after each test case
    }
    return 0;
}

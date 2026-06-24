/*
 * Beecrowd 1058 - Independent Attacking Zones
 *
 * P platoons stand in a circle, each Red ('R') or Black ('B'). They must be
 * grouped into P/3 triangles (every platoon in exactly one triangle) so that no
 * two triangular regions overlap and each triangle holds at most one Red
 * platoon. Count the number of valid groupings for the given circular colour
 * string.
 *
 * Input : T (< 100) test cases. Each: a line with P (2 < P < 40, P a multiple of
 *         3) and a line with a string of length P over {'R','B'} listing the
 *         platoons clockwise (an arbitrary starting point -- a fixed circular
 *         arrangement, so rotations describe the same input and same answer).
 * Output: "Case X: Y" per case, Y = number of valid groupings.
 *
 * Approach: points on a circle are in convex position, so "non-overlapping
 *   triangles" means a non-crossing chord partition of the convex polygon -- a
 *   Fuss-Catalan structure. Solve with an interval DP on contiguous arcs:
 *   dp[i][j] = valid partitions of points i..j. The leftmost point i must join a
 *   triangle {i, a, b}; its two chords cut the arc into three independent
 *   sub-arcs [i+1,a-1], [a+1,b-1], [b+1,j], each of a size divisible by 3. Sum
 *   the products over all (a,b) whose triangle has at most one Red. The whole
 *   circle is just the convex polygon 0..P-1, so the answer is dp[0][P-1].
 *
 * Complexity: O(P^4) per test with stepping that visits only valid arc splits
 *   (about (P/3)^2 pairs per interval); trivial for P < 40.
 */

#include <bits/stdc++.h>
using namespace std;

int P;
bool red[40];
long long dp[40][40];                 // dp[i][j] for the arc i..j (i <= j)
bool done[40][40];

// Valid partitions of the contiguous arc of points i..j. Empty arc (i > j) is
// one way (nothing to do); a length not divisible by 3 cannot be tiled.
long long solve(int i, int j) {
    if (i > j) return 1;
    if ((j - i + 1) % 3 != 0) return 0;
    if (done[i][j]) return dp[i][j];
    done[i][j] = true;
    long long total = 0;
    // Leftmost point i pairs with a and b. Step a, b by 3 so each leading
    // sub-arc length (a-i-1) and (b-a-1) is a multiple of 3 by construction.
    for (int a = i + 1; a <= j; a += 3)
        for (int b = a + 1; b <= j; b += 3) {
            if ((j - b) % 3 != 0) continue;             // trailing sub-arc must tile too
            if (red[i] + red[a] + red[b] > 1) continue; // at most one Red per triangle
            total += solve(i + 1, a - 1) * solve(a + 1, b - 1) * solve(b + 1, j);
        }
    return dp[i][j] = total;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        char buf[64];
        if (scanf("%d", &P) != 1) return 0;
        if (scanf("%s", buf) != 1) return 0;
        for (int i = 0; i < P; ++i) red[i] = (buf[i] == 'R');
        memset(done, 0, sizeof(done));                  // reset memo between cases
        printf("Case %d: %lld\n", tc, solve(0, P - 1));
    }
    return 0;
}

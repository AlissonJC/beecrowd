/*
 * Beecrowd 3230 - Galactic Warlords
 * Source: Nordic Collegiate Programming Contest 2012
 *
 * PROBLEM (restated in English)
 * -----------------------------
 * A set of infinite straight lines splits the 2D plane into sectors. Some of
 * those sectors are unbounded (they have infinite area). There are W warlords;
 * for there to be peace every warlord must receive a sector of the exact same
 * area, and the only area they can all share equally is the infinite one.
 * Therefore each warlord needs at least one unbounded sector. Given the N lines
 * of a suggested division, report the minimum number of extra lines that must
 * be added so that the arrangement has at least W unbounded sectors.
 *
 * INPUT
 *   - First line: two integers W and N (1 <= W, N <= 100).
 *   - Next N lines: four integers x1 y1 x2 y2 (|value| <= 10000), the line that
 *     passes through the two distinct points (x1,y1) and (x2,y2).
 * OUTPUT
 *   - A single integer: the number of lines that must be added.
 *
 * KEY OBSERVATION - counting unbounded regions of a line arrangement
 * ------------------------------------------------------------------
 * Surround the arrangement by a huge circle. Every line meets the circle at
 * exactly two points, so L distinct lines create 2L boundary points and hence
 * 2L arcs. Each arc corresponds to one unbounded region, EXCEPT for an infinite
 * "slab" (the strip between two parallel lines, open on both ends), which spans
 * two opposite arcs yet is a single region.
 *
 * A slab can only survive when every line is parallel: as soon as a second
 * direction exists, that transversal line - being infinite - crosses every
 * parallel strip and slices each slab into two ordinary wedges. Hence, for L
 * distinct lines with d distinct directions:
 *     d >= 2  ->  U = 2 * L      (no slabs; also the maximum possible for L lines)
 *     d == 1  ->  U = L + 1      (L - 1 surviving slabs, removed from 2L)
 *
 * SOLVING THE TASK
 * ----------------
 * The most unbounded sectors achievable with L distinct lines is 2L, so to
 * reach U >= W we need L >= ceil(W/2) distinct lines arranged with d >= 2.
 * Duplicate input lines do not create regions, so only DISTINCT lines count
 * (this is exactly the second sample: 3 lines, but two coincide -> 2 effective
 * lines -> U = 4 < 5 -> one line must be added).
 *
 * Let L0 be the number of distinct input lines and U0 the current unbounded
 * count. If U0 >= W no line is needed. Otherwise we must add lines; the answer
 * is max(1, ceil(W/2) - L0). The "1" handles the all-parallel case where L0 is
 * already large enough in count but every line shares one direction: adding a
 * single transversal lifts U from L0+1 straight to 2(L0+1).
 *
 * COMPLEXITY
 * ----------
 * O(N log N) to deduplicate lines and directions, trivial for N <= 100.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, N;
    cin >> W >> N;

    // A line is stored canonically as a*x + b*y = c so that identical lines map
    // to identical triples and parallel lines share the same (a,b) direction.
    set<array<long long, 3>> lines;       // distinct lines  -> L0
    set<array<long long, 2>> directions;  // distinct slopes -> d0

    for (int i = 0; i < N; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long dx = x2 - x1, dy = y2 - y1;   // direction vector of the line
        // Normal form: (a,b) is perpendicular to (dx,dy); c fixes the offset.
        long long a = dy, b = -dx;
        long long c = dy * x1 - dx * y1;        // satisfies a*x1 + b*y1 = c

        // Reduce by gcd so proportional triples coincide (dx,dy are never both 0).
        long long g = __gcd(llabs(a), llabs(b));
        a /= g; b /= g; c /= g;

        // Canonical sign: force the first non-zero of (a,b) to be positive so a
        // line and its reverse, or any rescaling, collapse to one representative.
        if (a < 0 || (a == 0 && b < 0)) { a = -a; b = -b; c = -c; }

        lines.insert({a, b, c});
        directions.insert({a, b});
    }

    long long L0 = (long long)lines.size();      // distinct lines (>= 1 since N >= 1)
    long long d0 = (long long)directions.size(); // distinct directions

    // Current number of unbounded sectors.
    long long U0 = (d0 >= 2) ? 2 * L0 : L0 + 1;

    long long answer;
    if (U0 >= W) {
        // Already enough infinite sectors for every warlord.
        answer = 0;
    } else {
        // Need ceil(W/2) distinct lines (with two directions) to expose W sectors.
        long long need = (long long)((W + 1) / 2) - L0;
        // We are here because U0 < W, so at least one line is always required;
        // need can be <= 0 only in the all-parallel case, where one line suffices.
        answer = max(1LL, need);
    }

    cout << answer << '\n';
    return 0;
}

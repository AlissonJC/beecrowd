/*
 * Beecrowd 2632 — Magic and Sword
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   For each test case, decide whether the axis-aligned rectangle of
 *   size w x h with lower-left corner at (x0, y0) intersects the disk
 *   centered at (cx, cy) with radius R, where R and the unit damage
 *   depend on a (spell, level) pair:
 *     fire  -> 200, radii {20, 30, 50}
 *     water -> 300, radii {10, 25, 40}
 *     earth -> 400, radii {25, 55, 70}
 *     air   -> 100, radii {18, 38, 60}
 *   Print the damage if the shapes intersect, else 0.
 *
 * Circle-rectangle test:
 *   The closest point of an axis-aligned rectangle to an external
 *   point (cx, cy) is found by clamping cx into [x0, x0+w] and cy into
 *   [y0, y0+h]. The shapes intersect iff the squared distance from
 *   (cx, cy) to that clamped point is <= R^2. All inputs are
 *   integers, so the comparison stays exact.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long w, h, x0, y0;
        scanf("%lld %lld %lld %lld", &w, &h, &x0, &y0);
        char spell[16];
        int level;
        long long cx, cy;
        scanf("%15s %d %lld %lld", spell, &level, &cx, &cy);

        int damage = 0;
        long long radius = 0;
        // Per-spell lookup. Levels are 1..3, kept 1-indexed via the [0]
        // sentinel in the radius arrays.
        if (strcmp(spell, "fire") == 0) {
            damage = 200;
            static const long long R[4] = {0, 20, 30, 50};
            radius = R[level];
        } else if (strcmp(spell, "water") == 0) {
            damage = 300;
            static const long long R[4] = {0, 10, 25, 40};
            radius = R[level];
        } else if (strcmp(spell, "earth") == 0) {
            damage = 400;
            static const long long R[4] = {0, 25, 55, 70};
            radius = R[level];
        } else { // "air"
            damage = 100;
            static const long long R[4] = {0, 18, 38, 60};
            radius = R[level];
        }

        // Clamp the disk center onto the rectangle to find its closest
        // point; that gives the minimum distance from disk to rect.
        long long px = max(x0, min(cx, x0 + w));
        long long py = max(y0, min(cy, y0 + h));
        long long dx = cx - px;
        long long dy = cy - py;
        long long dist2 = dx * dx + dy * dy;

        // "Any intersection" includes tangency (boundary contact), so
        // use <= rather than < when comparing to R^2.
        printf("%d\n", dist2 <= radius * radius ? damage : 0);
    }
    return 0;
}

/*
 * Beecrowd 1455 - ICPC Finals
 *
 * Choose the smallest circle that covers every given city position (a city is
 * covered if it lies inside the circle or on its border) -- the classic minimum
 * enclosing circle. Report the circle's center and radius.
 *
 * Input : several instances. Each begins with n (2 <= n <= 100), then n lines of
 *         real coordinates "x y". A line with n = 0 ends the input.
 * Output: for instance k, a line "Instancia k", then "cx cy r" each with two
 *         decimals, then a blank line after the instance.
 *
 * Approach: Welzl's randomized incremental algorithm. Shuffle the points and add
 *   them one at a time; whenever a point falls outside the current circle, that
 *   point must lie on the boundary of the answer, so rebuild the circle with it
 *   pinned (recursing at most two levels deep). A minimum enclosing circle is
 *   always determined by 2 points (their midpoint circle) or 3 points (their
 *   circumcircle), which are the only trivial cases needed. Expected O(n) per
 *   instance -- instant for n <= 100.
 *
 * Complexity: O(n) expected time, O(n) space.
 */

#include <bits/stdc++.h>
using namespace std;

struct Pt { double x, y; };
static double dist(const Pt &a, const Pt &b) { return hypot(a.x - b.x, a.y - b.y); }

struct Circ { Pt c; double r; };
static const double EPS = 1e-7;
// Treat boundary points as inside (a city on the border is covered).
static bool inside(const Circ &ci, const Pt &p) { return dist(ci.c, p) <= ci.r + EPS; }

// Smallest circle with two points on it: the circle having them as a diameter.
static Circ from2(const Pt &a, const Pt &b) {
    Pt c{(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
    return {c, dist(a, b) / 2.0};
}

// Circle through three points: their circumcircle (center is the circumcenter).
static Circ from3(const Pt &a, const Pt &b, const Pt &c) {
    double ax = a.x, ay = a.y, bx = b.x, by = b.y, cx = c.x, cy = c.y;
    double d = 2.0 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    double a2 = ax * ax + ay * ay, b2 = bx * bx + by * by, c2 = cx * cx + cy * cy;
    double ux = (a2 * (by - cy) + b2 * (cy - ay) + c2 * (ay - by)) / d;
    double uy = (a2 * (cx - bx) + b2 * (ax - cx) + c2 * (bx - ax)) / d;
    Pt cen{ux, uy};
    return {cen, dist(cen, a)};
}

static Circ mec(vector<Pt> p) {
    static mt19937 rng(12345);
    shuffle(p.begin(), p.end(), rng);          // randomize for expected O(n)
    int n = (int)p.size();
    Circ c{{0, 0}, -1};                          // -1 marks "no circle yet"
    for (int i = 0; i < n; ++i) {
        if (c.r < 0 || !inside(c, p[i])) {       // p[i] forced onto the boundary
            c = {p[i], 0};
            for (int j = 0; j < i; ++j) {
                if (!inside(c, p[j])) {           // p[i], p[j] both on the boundary
                    c = from2(p[i], p[j]);
                    for (int k = 0; k < j; ++k) {
                        if (!inside(c, p[k]))     // all three on the boundary
                            c = from3(p[i], p[j], p[k]);
                    }
                }
            }
        }
    }
    return c;
}

int main() {
    int n, inst = 0;
    while (scanf("%d", &n) == 1 && n != 0) {
        vector<Pt> pts(n);
        for (int i = 0; i < n; ++i)
            if (scanf("%lf %lf", &pts[i].x, &pts[i].y) != 2) return 0;

        Circ c = mec(pts);
        double cx = c.c.x, cy = c.c.y, r = c.r;
        // Snap values that round to zero so we never print the ugly "-0.00".
        if (fabs(cx) < 0.005) cx = 0.0;
        if (fabs(cy) < 0.005) cy = 0.0;
        if (fabs(r) < 0.005) r = 0.0;

        printf("Instancia %d\n", ++inst);
        printf("%.2f %.2f %.2f\n", cx, cy, r);
        printf("\n");                            // blank line after each instance
    }
    return 0;
}

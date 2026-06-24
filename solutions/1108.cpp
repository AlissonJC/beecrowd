/*
 * Beecrowd 1108 - Towers for Mobile Telephony
 *
 * A telephone company installs exactly two transmitter towers, both with the
 * same cover radius r; each tower covers a disk of radius r over the perfectly
 * flat city. Given the positions of N homes, place the two towers so that every
 * home falls inside at least one disk, while minimizing r. Print that smallest
 * radius. This is precisely the planar 2-center problem.
 *
 * Input : several test cases. Each begins with N (3 <= N <= 40), then N lines
 *         with integers X Y (0 <= X,Y <= 1e4); all home positions are distinct.
 *         A line containing a single 0 ends the input.
 * Output: one line per case, the minimum radius with exactly two decimals.
 *
 * Approach: the answer is  min over partitions {A,B} of the homes of
 *   max(MEC(A), MEC(B)), where MEC is the minimum-enclosing-circle radius (for a
 *   fixed assignment, the least radius covering a group is its MEC). In an
 *   optimal solution the larger, binding disk equals the MEC of the homes it
 *   serves, and any MEC is determined by 2 homes (taken as a diameter) or 3
 *   homes (their circumcircle). So enumerate every such candidate circle C: the
 *   homes inside C form one group, the homes outside form the other, and the
 *   cost is max(radius(C), MEC(outside)); keep the minimum over all C. When C is
 *   the optimum's binding disk, every home of that disk's group lies inside C
 *   and the rest is a subset of the other group, so MEC(outside) <= answer and
 *   the optimum is reproduced. Every candidate is itself a valid covering, so
 *   the minimum equals the optimum.
 *
 * Complexity: O(N^3) candidate circles, each paired with an O(N) expected
 *   minimum enclosing circle (Welzl) -> about O(N^4) per test case (N <= 40),
 *   well within the limits.
 */

#include <bits/stdc++.h>
using namespace std;

struct P { double x, y; };
struct Circle { P c; double r; };

static double dist2(const P& a, const P& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

static bool inCircle(const Circle& cir, const P& p) {
    // A negative radius is the "no circle yet" sentinel and contains nothing;
    // without this guard r*r = 1 would falsely swallow points within distance 1
    // of the origin, so Welzl would skip and fail to enclose them.
    if (cir.r < 0.0) return false;
    // Generous epsilon so a circle's own boundary points count as inside.
    return dist2(cir.c, p) <= cir.r * cir.r + 1e-7;
}

// Smallest circle having a and b as a diameter.
static Circle from2(const P& a, const P& b) {
    P c = {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
    return {c, sqrt(dist2(a, b)) / 2.0};
}

// Circumcircle of three non-collinear points (the unique circle through them).
static Circle from3(const P& a, const P& b, const P& c) {
    double ax = a.x, ay = a.y, bx = b.x, by = b.y, cx = c.x, cy = c.y;
    double d  = 2.0 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    double a2 = ax * ax + ay * ay, b2 = bx * bx + by * by, c2 = cx * cx + cy * cy;
    double ux = (a2 * (by - cy) + b2 * (cy - ay) + c2 * (ay - by)) / d;
    double uy = (a2 * (cx - bx) + b2 * (ax - cx) + c2 * (bx - ax)) / d;
    P cc = {ux, uy};
    return {cc, sqrt(dist2(cc, a))};
}

// Circle through three Welzl support points. All three must stay ON the
// boundary -- that is Welzl's invariant -- so this is their circumcircle, NOT
// the minimum circle of the three: dropping a support point to a diameter when
// the triangle is obtuse breaks the invariant and yields a wrong enclosing
// circle for some insertion orders. The only exception is exactly-collinear
// support, where no circle passes through all three; then the farthest-apart
// pair (a diameter) is the correct minimal circle.
static Circle boundary3(const P& a, const P& b, const P& c) {
    double det = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (fabs(det) < 1e-7) {                               // collinear support
        Circle ab = from2(a, b), ac = from2(a, c), bc = from2(b, c);
        Circle r = ab;
        if (ac.r > r.r) r = ac;
        if (bc.r > r.r) r = bc;
        return r;
    }
    return from3(a, b, c);
}

// Minimum enclosing circle of pts (Welzl, randomized incremental). pts should be
// pre-shuffled for the O(n) expected bound. Radius -1 marks the empty set.
static Circle welzl(const vector<P>& pts) {
    Circle c = {{0, 0}, -1};
    int n = (int)pts.size();
    for (int i = 0; i < n; ++i) if (!inCircle(c, pts[i])) {
        c = {pts[i], 0};                                  // 1st boundary point
        for (int j = 0; j < i; ++j) if (!inCircle(c, pts[j])) {
            c = from2(pts[i], pts[j]);                    // 2nd boundary point
            for (int k = 0; k < j; ++k) if (!inCircle(c, pts[k]))
                c = boundary3(pts[i], pts[j], pts[k]);    // 3rd boundary point
        }
    }
    return c;
}

int main() {
    mt19937 rng(12345);   // fixed seed -> deterministic shuffles for Welzl
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        vector<P> pts(n);
        for (auto& p : pts)
            if (scanf("%lf %lf", &p.x, &p.y) != 2) return 0;

        // One fixed shuffled visiting order: any subset we later collect for
        // Welzl comes out randomly ordered, giving its O(n) expected bound
        // without paying for a fresh shuffle on every candidate.
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        shuffle(ord.begin(), ord.end(), rng);
        vector<P> all;
        all.reserve(n);
        for (int id : ord) all.push_back(pts[id]);

        // Upper bound: a single disk covering everyone (second tower then free).
        double best = welzl(all).r;

        // Candidate "binding" disks: every pair diameter, plus the circumcircle
        // of every non-obtuse triple. An MEC fixed by 3 points always forms a
        // non-obtuse triangle (its circumcenter lies in the triangle); an obtuse
        // or collinear triple's MEC is just its longest-side diameter, already a
        // pair candidate -- so skipping those loses nothing and avoids a
        // degenerate circumcircle.
        vector<Circle> cand;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                cand.push_back(from2(pts[i], pts[j]));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                double dij = dist2(pts[i], pts[j]);
                for (int k = j + 1; k < n; ++k) {
                    double dik = dist2(pts[i], pts[k]);
                    double djk = dist2(pts[j], pts[k]);
                    double mx = max(dij, max(dik, djk));
                    // Non-obtuse iff longest side^2 <= sum of the other two^2,
                    // i.e. 2*max <= total; obtuse/collinear triples are dropped.
                    if (2.0 * mx > dij + dik + djk + 1e-7) continue;
                    cand.push_back(from3(pts[i], pts[j], pts[k]));
                }
            }

        // Try small disks first; once radius(C) alone reaches best, the cost
        // max(radius(C), MEC(outside)) can no longer improve, so stop.
        sort(cand.begin(), cand.end(),
             [](const Circle& a, const Circle& b) { return a.r < b.r; });

        for (const Circle& cir : cand) {
            if (cir.r >= best) break;
            double rr = cir.r * cir.r + 1e-6;
            vector<P> outside;
            for (int id : ord)                              // keep shuffled order
                if (dist2(cir.c, pts[id]) > rr)             // strictly outside C
                    outside.push_back(pts[id]);
            Circle other = welzl(outside);
            double rB = (other.r < 0) ? 0.0 : other.r;      // empty outside -> 0
            best = min(best, max(cir.r, rB));
        }

        printf("%.2f\n", best);
    }
    return 0;
}

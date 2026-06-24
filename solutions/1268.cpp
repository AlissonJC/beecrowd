/*
 * Beecrowd 1268 - Mission Impossible
 *
 * A spy starts at the point (2000, 2000), far outside an enemy country (a simple
 * polygon). Inside the country there are M radar disks (obstacles the spy may
 * never enter) and N informers (points). The spy may walk any curve in the plane
 * that never enters a radar disk. Among the informers reachable this way, report
 * the one with the largest "insider-coefficient" -- its minimum distance to the
 * country border -- breaking ties by lowest index. If none is reachable, print
 * "Mission impossible".
 *
 * Input : several test cases. Per case three lines:
 *           B  X1 Y1 ... XB YB           border polygon (3 <= B <= 1000)
 *           N  X1 Y1 ... XN YN           informers      (1 <= N <= 1000)
 *           M  X1 Y1 R1 ... XM YM RM     radars         (1 <= M <= 30)
 *         All coordinates integer in [0,1000], radii in [1,1000]. A line with
 *         B = N = M = 0 (three zero lines) ends the input and is not processed.
 * Output: "Contact informer K" (1-based) or "Mission impossible" per case.
 *
 * Reachability: the start is always free (no disk reaches it). An informer is
 *   reachable unless it is strictly inside a disk, or it is *enclosed* by a ring
 *   of radars. Two disks whose centres are within r_i + r_j overlap, and the
 *   segment joining their centres lies wholly inside their union; hence a cycle
 *   in this "centre-overlap" graph is a closed curve made of covered points, and
 *   a free point inside that cycle can never cross out -> it is trapped. So an
 *   informer is enclosed iff it lies in a bounded face of the arrangement of the
 *   overlap segments. A non-closing chain (tree/path) has no bounded face, so it
 *   correctly traps nobody.
 *
 * The bounded faces are obtained by building the planar arrangement of the
 *   overlap segments (splitting them at mutual intersections) and tracing faces
 *   with a half-edge rotation system; a face with positive signed area is
 *   bounded. The insider-coefficient is the minimum point-to-segment distance to
 *   the border edges. Both are tiny given M <= 30.
 *
 * Complexity: O(M^4) worst case for the arrangement (M <= 30) plus O(N*B) for
 *   the border distances per test case.
 */

#include <bits/stdc++.h>
using namespace std;

struct Pt { double x, y; };

static const double EPS = 1e-9;

static double cross(const Pt& O, const Pt& A, const Pt& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
static double dist2(const Pt& a, const Pt& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// Squared distance from point p to segment ab (used for the border distance).
static double distToSeg2(const Pt& p, const Pt& a, const Pt& b) {
    double dx = b.x - a.x, dy = b.y - a.y;
    double len2 = dx * dx + dy * dy;
    if (len2 < EPS) return dist2(p, a);                 // degenerate segment
    double t = ((p.x - a.x) * dx + (p.y - a.y) * dy) / len2;
    t = max(0.0, min(1.0, t));                          // clamp to the segment
    Pt proj = {a.x + t * dx, a.y + t * dy};
    return dist2(p, proj);
}

// ---- Planar arrangement of the radar centre-overlap segments ----------------
// Vertices are deduplicated by rounded coordinates; segments are split at every
// vertex lying on them, then faces are traced via a rotation system.

struct Arrangement {
    vector<Pt> V;                                       // vertices
    map<pair<long long, long long>, int> idOf;          // dedup key -> vertex id
    vector<array<int, 2>> seg;                          // raw overlap segments

    int addVertex(const Pt& p) {
        long long kx = llround(p.x * 1000.0), ky = llround(p.y * 1000.0);
        auto key = make_pair(kx, ky);
        auto it = idOf.find(key);
        if (it != idOf.end()) return it->second;
        idOf[key] = (int)V.size();
        V.push_back(p);
        return (int)V.size() - 1;
    }

    // Proper-or-touching intersection point of segments p1p2 and p3p4 (assumes
    // they actually meet); returns false if parallel/degenerate.
    static bool segInter(const Pt& p1, const Pt& p2, const Pt& p3, const Pt& p4, Pt& out) {
        double d = (p2.x - p1.x) * (p4.y - p3.y) - (p2.y - p1.y) * (p4.x - p3.x);
        if (fabs(d) < EPS) return false;                // parallel / collinear
        double t = ((p3.x - p1.x) * (p4.y - p3.y) - (p3.y - p1.y) * (p4.x - p3.x)) / d;
        double u = ((p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x)) / d;
        if (t < -EPS || t > 1 + EPS || u < -EPS || u > 1 + EPS) return false;
        out = {p1.x + t * (p2.x - p1.x), p1.y + t * (p2.y - p1.y)};
        return true;
    }

    // Return true if point q lies on segment ab (within EPS).
    static bool onSeg(const Pt& a, const Pt& b, const Pt& q) {
        if (fabs(cross(a, b, q)) > 1e-6) return false;
        return q.x >= min(a.x, b.x) - EPS && q.x <= max(a.x, b.x) + EPS &&
               q.y >= min(a.y, b.y) - EPS && q.y <= max(a.y, b.y) + EPS;
    }
};

// Builds the arrangement of the given segments and returns the bounded faces,
// each as a closed polygon (vertex list).
static vector<vector<Pt>> boundedFaces(const vector<pair<Pt, Pt>>& segs) {
    int S = (int)segs.size();
    if (S == 0) return {};
    Arrangement A;
    // each segment's on-segment vertex ids, collected as we go (endpoints first,
    // then every mutual intersection) -- O(S^2) total, not O(S * |V|).
    vector<vector<int>> onSegV(S);
    for (int i = 0; i < S; ++i) {
        onSegV[i].push_back(A.addVertex(segs[i].first));
        onSegV[i].push_back(A.addVertex(segs[i].second));
    }
    for (int i = 0; i < S; ++i)
        for (int j = i + 1; j < S; ++j) {
            Pt ip;
            if (Arrangement::segInter(segs[i].first, segs[i].second,
                                      segs[j].first, segs[j].second, ip)) {
                int v = A.addVertex(ip);
                onSegV[i].push_back(v);
                onSegV[j].push_back(v);
            }
        }

    // adjacency as a set of undirected edges (split each segment by the vertices on it)
    set<pair<int, int>> edgeSet;
    for (int i = 0; i < S; ++i) {
        Pt a = segs[i].first, b = segs[i].second;
        auto& on = onSegV[i];
        sort(on.begin(), on.end(), [&](int p, int q) {
            double tp = (A.V[p].x - a.x) * (b.x - a.x) + (A.V[p].y - a.y) * (b.y - a.y);
            double tq = (A.V[q].x - a.x) * (b.x - a.x) + (A.V[q].y - a.y) * (b.y - a.y);
            return tp < tq;
        });
        on.erase(unique(on.begin(), on.end()), on.end());
        for (size_t k = 0; k + 1 < on.size(); ++k) {
            int u = on[k], w = on[k + 1];
            if (u != w) edgeSet.insert({min(u, w), max(u, w)});
        }
    }

    // build sorted neighbour lists (CCW by angle) for the rotation system
    int n = (int)A.V.size();
    vector<vector<int>> adj(n);
    for (auto& e : edgeSet) { adj[e.first].push_back(e.second); adj[e.second].push_back(e.first); }
    // posOf[v] maps a neighbour id -> its index in adj[v] (avoids per-step find)
    vector<unordered_map<int, int>> posOf(n);
    for (int v = 0; v < n; ++v) {
        vector<pair<double, int>> tmp;
        for (int w : adj[v]) tmp.push_back({atan2(A.V[w].y - A.V[v].y, A.V[w].x - A.V[v].x), w});
        sort(tmp.begin(), tmp.end());
        adj[v].clear();
        posOf[v].reserve(tmp.size() * 2);
        for (auto& t : tmp) { posOf[v][t.second] = (int)adj[v].size(); adj[v].push_back(t.second); }
    }

    // index directed half-edges by the flat key u*n+v so visited is a vector<bool>
    unordered_map<long long, int> heId;
    heId.reserve(edgeSet.size() * 4);
    int H = 0;
    auto key = [&](int u, int v) { return (long long)u * n + v; };
    vector<pair<int, int>> heList;
    for (auto& e : edgeSet) {
        heId[key(e.first, e.second)] = H++; heList.push_back({e.first, e.second});
        heId[key(e.second, e.first)] = H++; heList.push_back({e.second, e.first});
    }
    vector<char> used(H, 0);

    // trace faces over directed half-edges (u->v); next is the clockwise-most
    // turn at v after the reverse edge v->u.
    vector<vector<Pt>> faces;
    for (int start = 0; start < H; ++start) {
        if (used[start]) continue;
        vector<Pt> poly;
        int u = heList[start].first, v = heList[start].second;
        int hid = start;
        while (!used[hid]) {
            used[hid] = true;
            poly.push_back(A.V[u]);
            // at v, take the neighbour just clockwise from the reverse edge v->u
            int deg = (int)adj[v].size();
            int idx = posOf[v][u];
            int nxt = adj[v][(idx - 1 + deg) % deg];
            u = v; v = nxt;
            hid = heId[key(u, v)];
        }
        double area2 = 0;                               // signed area; bounded faces are CCW (+)
        for (size_t k = 0; k < poly.size(); ++k) {
            Pt& p = poly[k]; Pt& q = poly[(k + 1) % poly.size()];
            area2 += p.x * q.y - q.x * p.y;
        }
        if (area2 > EPS) faces.push_back(poly);         // keep bounded faces only
    }
    return faces;
}

// Point-in-polygon (ray crossing), inclusive of boundary -> treated as inside.
static bool inPoly(const Pt& p, const vector<Pt>& poly) {
    int cnt = 0, m = (int)poly.size();
    for (int i = 0; i < m; ++i) {
        Pt a = poly[i], b = poly[(i + 1) % m];
        if (fabs(cross(a, b, p)) < 1e-6 &&
            p.x >= min(a.x, b.x) - EPS && p.x <= max(a.x, b.x) + EPS &&
            p.y >= min(a.y, b.y) - EPS && p.y <= max(a.y, b.y) + EPS)
            return true;                                // on an edge
        if ((a.y > p.y) != (b.y > p.y)) {
            double xint = a.x + (p.y - a.y) / (b.y - a.y) * (b.x - a.x);
            if (xint > p.x) cnt ^= 1;
        }
    }
    return cnt & 1;
}

int main() {
    int B;
    while (scanf("%d", &B) == 1) {
        vector<Pt> border(B);
        for (auto& p : border) { if (scanf("%lf %lf", &p.x, &p.y) != 2) return 0; }
        int N; if (scanf("%d", &N) != 1) return 0;
        vector<Pt> inf(N);
        for (auto& p : inf) { if (scanf("%lf %lf", &p.x, &p.y) != 2) return 0; }
        int M; if (scanf("%d", &M) != 1) return 0;
        vector<Pt> rc(M); vector<double> rr(M);
        for (int i = 0; i < M; ++i) { if (scanf("%lf %lf %lf", &rc[i].x, &rc[i].y, &rr[i]) != 3) return 0; }

        if (B == 0 && N == 0 && M == 0) break;          // terminator

        // overlap segments between centres of intersecting disks
        vector<pair<Pt, Pt>> segs;
        for (int i = 0; i < M; ++i)
            for (int j = i + 1; j < M; ++j) {
                double s = rr[i] + rr[j];
                if (dist2(rc[i], rc[j]) <= s * s + EPS) segs.push_back({rc[i], rc[j]});
            }
        vector<vector<Pt>> faces = boundedFaces(segs);
        // bounding box per face for quick rejection during informer queries
        vector<array<double, 4>> fbox(faces.size());   // minx, miny, maxx, maxy
        for (size_t f = 0; f < faces.size(); ++f) {
            double a = 1e18, b = 1e18, c = -1e18, d = -1e18;
            for (const Pt& q : faces[f]) { a = min(a, q.x); b = min(b, q.y); c = max(c, q.x); d = max(d, q.y); }
            fbox[f] = {a, b, c, d};
        }

        int best = -1; double bestCoef = -1;
        for (int k = 0; k < N; ++k) {
            const Pt& p = inf[k];
            bool trapped = false;
            for (int i = 0; i < M && !trapped; ++i)     // strictly inside a disk
                if (dist2(p, rc[i]) < rr[i] * rr[i] - EPS) trapped = true;
            for (size_t f = 0; f < faces.size() && !trapped; ++f) {
                if (p.x < fbox[f][0] - EPS || p.x > fbox[f][2] + EPS ||
                    p.y < fbox[f][1] - EPS || p.y > fbox[f][3] + EPS) continue;  // bbox reject
                if (inPoly(p, faces[f])) trapped = true; // enclosed by a radar ring
            }
            if (trapped) continue;

            double coef2 = 1e18;                          // squared min dist to border
            for (int b = 0; b < B; ++b)
                coef2 = min(coef2, distToSeg2(p, border[b], border[(b + 1) % B]));
            double coef = sqrt(coef2);
            if (coef > bestCoef + 1e-9) { bestCoef = coef; best = k; } // tie -> lower index kept
        }

        if (best < 0) printf("Mission impossible\n");
        else printf("Contact informer %d\n", best + 1);
    }
    return 0;
}

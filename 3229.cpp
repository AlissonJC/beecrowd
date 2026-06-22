/*
 * Beecrowd 3229 — Food Review
 * Time limit: 1 s
 *
 * Rural Postman variant: closed walk from airport 1 traversing every
 * required edge at least once, with optional edges available for any
 * number of traversals. Minimise total flight cost.
 *
 * Algorithm — unified bitmask DP combining parity and connectivity:
 *
 *   State: dp(count, curr)
 *     - count = bitmask of vertices that still have ODD parity (i.e.
 *       still need their parity fixed by extra path traversals).
 *     - curr  = bitmask of vertices whose required-graph component is
 *       already "reachable" from airport 1.
 *   Goal: count == 0 AND (curr & reqMask) == reqMask, i.e. all
 *   parities even and every required vertex's component reachable.
 *   Cost so far has been the sum of all path-segment costs added.
 *
 *   Two transitions, each costing dist[u][v] (Floyd-Warshall distance):
 *
 *     1. Parity pair inside curr — pick u, v both already reachable AND
 *        both currently odd; clear both bits in count. (Pairs two odd
 *        vertices via a shortest path; their endpoints' parities flip.)
 *
 *     2. Bridge to a new component — pick u in curr and v in some
 *        required component outside curr; XOR both u and v in count
 *        (their parities flip), and OR v's entire component into curr.
 *        The vertices internally odd inside that component remain in
 *        count and will be fixed by future transitions.
 *
 * Why both phases share the same DP:
 *   Separating "minimum T-join" from "Steiner connectivity" and adding
 *   them is only a lower bound — sometimes a slightly more expensive
 *   parity pairing also delivers connectivity, beating "optimal
 *   matching + separate Steiner". Folding the two moves into one DP
 *   lets every shortest path do double duty (or not) and finds the
 *   true optimum.
 *
 * Complexity:
 *   State space is bounded by 2^N * 2^N with N <= 13, but only a small
 *   reachable slice is ever visited. Each state evaluates O(N^2)
 *   transitions. Memoised, well within 1 s for the given limits.
 */

#include <bits/stdc++.h>
using namespace std;

static const long long INF = (long long)1e18;
static int N;
static long long dist_[15][15];
static int comp_[15];     // comp_[v] = bitmask of v's required-graph component
static int reqMask;        // bitmask of vertices that appear in some required edge

static unordered_map<long long, long long> memo;

static long long solve(int count, int curr) {
    if (count == 0 && (curr & reqMask) == reqMask) return 0;

    long long key = ((long long)count << 16) | curr;
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;

    long long best = INF;

    // Transition 1: pair two odd vertices already inside curr.
    int avail = count & curr;
    for (int u = 0; u < N; u++) {
        if (!((avail >> u) & 1)) continue;
        for (int v = u + 1; v < N; v++) {
            if (!((avail >> v) & 1)) continue;
            int nc = count ^ (1 << u) ^ (1 << v);
            long long sub = solve(nc, curr);
            if (sub < INF) {
                long long cand = dist_[u][v] + sub;
                if (cand < best) best = cand;
            }
        }
    }

    // Transition 2: bridge from inside curr to an outside required vertex.
    int outside = reqMask & ~curr;
    for (int u = 0; u < N; u++) {
        if (!((curr >> u) & 1)) continue;
        for (int v = 0; v < N; v++) {
            if (!((outside >> v) & 1)) continue;
            int nc = count ^ (1 << u) ^ (1 << v);
            int nCurr = curr | comp_[v];
            long long sub = solve(nc, nCurr);
            if (sub < INF) {
                long long cand = dist_[u][v] + sub;
                if (cand < best) best = cand;
            }
        }
    }

    memo[key] = best;
    return best;
}

int main() {
    int R, F;
    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) dist_[i][j] = (i == j) ? 0 : INF;
        comp_[i] = 1 << i;
    }

    long long sumReq = 0;
    int oddInit = 0;
    reqMask = 0;

    // DSU to build required-graph components.
    int par[15];
    for (int i = 0; i < N; i++) par[i] = i;
    function<int(int)> findP = [&](int x) {
        while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; }
        return x;
    };

    for (int i = 0; i < R; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        if ((long long)c < dist_[a][b]) {
            dist_[a][b] = dist_[b][a] = c;
        }
        sumReq += c;
        oddInit ^= (1 << a);
        oddInit ^= (1 << b);
        reqMask |= (1 << a) | (1 << b);
        int ra = findP(a), rb = findP(b);
        if (ra != rb) par[ra] = rb;
    }

    int rootComp[15];
    for (int i = 0; i < N; i++) rootComp[i] = 0;
    for (int v = 0; v < N; v++) rootComp[findP(v)] |= (1 << v);
    for (int v = 0; v < N; v++) comp_[v] = rootComp[findP(v)];

    scanf("%d", &F);
    for (int i = 0; i < F; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        if ((long long)c < dist_[a][b]) {
            dist_[a][b] = dist_[b][a] = c;
        }
    }

    // Floyd-Warshall on full graph (required + optional, minimum edge for parallels).
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist_[i][k] + dist_[k][j] < dist_[i][j])
                    dist_[i][j] = dist_[i][k] + dist_[k][j];

    int initCurr = comp_[0];
    long long ans = sumReq + solve(oddInit, initCurr);
    printf("%lld\n", ans);
    return 0;
}

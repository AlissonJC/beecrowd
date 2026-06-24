/*
 * Beecrowd 3181 — Dinner
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   N conference participants need to be split into two groups (the two
 *   dining halls), each holding at most floor(2N/3) people. We are told
 *   C known first-meeting years -- entries of the form "A B Y" meaning
 *   participants A and B first met in year Y (1948 <= Y < 2008). Any
 *   pair NOT in the list met for the first time "now", in year 2008.
 *   Find the smallest year Y* such that some valid 2-partition exists
 *   where every pair in part 1 first met strictly before Y* and every
 *   pair in part 2 first met in year Y* or later. Print "Impossible"
 *   if no such Y* works.
 *
 * Key reformulation:
 *   Fix Y*. Define the "old" graph H_old whose edges are the pairs (A,
 *   B) with Y_AB < Y*. Inside part 1 every pair must be in H_old, so
 *   part 1 must be a CLIQUE of H_old. Inside part 2 every pair must
 *   have Y_AB >= Y*, i.e., NO edge of H_old inside part 2, so part 2
 *   must be an INDEPENDENT SET of H_old. That is exactly the split-
 *   graph decomposition problem, with a size constraint on the clique
 *   side: ceil(N/3) <= |clique| <= floor(2N/3).
 *
 * Input:
 *   Line 1: N C  (4 <= N <= 400, 0 <= C).
 *   Next C lines: A B Y with 1 <= A < B <= N and 1948 <= Y < 2008.
 *   Each pair appears at most once.
 *
 * Output:
 *   The smallest Y* (in [1948, 2008]) for which the partition exists,
 *   or "Impossible".
 *
 * Approach:
 *   Sort the listed pairs by year and process Y* = 1948, 1949, ...,
 *   2008 in increasing order. As Y* grows, add the pairs with year
 *   equal to Y*-1 into a bitset adjacency. For each Y*, sort vertices
 *   by current degree (descending; ties by ascending index), then for
 *   every k in [ceil(N/3), floor(2N/3)] test whether the top-k
 *   vertices form a clique and the bottom (N-k) vertices form an IS
 *   in H_old. The clique check uses one N-bit AND per top vertex; the
 *   IS check uses one N-bit AND per bottom vertex. Together that is
 *   O(N^2 / 64) per (Y*, k), well inside the time budget.
 *
 * Complexity:
 *   60 (years) * (N/3) (k values) * O(N^2 / 64) (bitset checks).
 *   For N = 400 this is ~10^7 word operations.
 */

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 405;
static const int YMIN = 1948;
static const int YMAX = 2008;

static int n, C;
static bitset<MAXN> adj[MAXN];
static int deg[MAXN];

struct Pair { int a, b, y; };

int main() {
    scanf("%d %d", &n, &C);
    vector<Pair> pairs(C);
    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &pairs[i].a, &pairs[i].b, &pairs[i].y);
    }
    // Sort listed pairs by year ascending so we can stream them into
    // H_old as Y* grows.
    sort(pairs.begin(), pairs.end(),
         [](const Pair& x, const Pair& y) { return x.y < y.y; });

    // Bitset covering vertices 1..n -- used to flip a partition.
    bitset<MAXN> universe;
    for (int i = 1; i <= n; i++) universe.set(i);

    int kMin = (n + 2) / 3;     // ceil(n / 3)
    int kMax = (2 * n) / 3;     // floor(2n / 3)

    int ptr = 0;
    for (int Y_star = YMIN; Y_star <= YMAX; Y_star++) {
        // Add every pair whose year is strictly less than Y_star.
        while (ptr < C && pairs[ptr].y < Y_star) {
            int a = pairs[ptr].a, b = pairs[ptr].b;
            adj[a].set(b);
            adj[b].set(a);
            deg[a]++;
            deg[b]++;
            ptr++;
        }

        // Sort the vertices by current degree descending. Ties broken
        // by ascending index for determinism.
        vector<int> ord(n);
        for (int i = 0; i < n; i++) ord[i] = i + 1;
        sort(ord.begin(), ord.end(), [](int x, int y) {
            if (deg[x] != deg[y]) return deg[x] > deg[y];
            return x < y;
        });

        // Build the top-k bitset S incrementally so we don't have to
        // rebuild it from scratch for each k.
        bitset<MAXN> S;
        for (int i = 0; i + 1 < kMin; i++) S.set(ord[i]);

        for (int k = kMin; k <= kMax; k++) {
            // Add the k-th highest-degree vertex (1-based) to S.
            S.set(ord[k - 1]);
            bitset<MAXN> notS = universe ^ S;   // bits 1..n not in S

            bool ok = true;

            // Clique test: every v in S must have all of S\{v} as
            // neighbours in H_old.
            for (int i = 0; i < k && ok; i++) {
                int v = ord[i];
                bitset<MAXN> needed = S;
                needed.reset(v);
                if ((adj[v] & S) != needed) ok = false;
            }

            // Independent-set test: every v NOT in S must have no
            // neighbour outside S either.
            for (int i = k; i < n && ok; i++) {
                int v = ord[i];
                if ((adj[v] & notS).any()) ok = false;
            }

            if (ok) {
                printf("%d\n", Y_star);
                return 0;
            }
        }
    }

    puts("Impossible");
    return 0;
}

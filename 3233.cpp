/*
 * Beecrowd 3233 — Juice
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A generator (node 0) feeds a tree of n houses (1..n). Each house i
 *   has a parent p_i, a non-negative power demand r_i, and is connected
 *   to p_i by an extension cord with capacity c_i. The generator is an
 *   infinite source. Pick a subset S of houses such that every house in
 *   S is fully fed, with the flow on each edge (i, p_i) -- i.e., the
 *   sum of demands of houses in the subtree of i that are in S --
 *   bounded by c_i. Maximize |S|.
 *
 * Input:
 *   Line 1: n  (0 <= n <= 1000).
 *   Next n lines: p_i r_i c_i  with 0 <= p_i <= n, 0 <= r_i <= 100,
 *   1 <= c_i <= 100.
 *
 * Output:
 *   The maximum number of houses whose demand can be met.
 *
 * Approach (tree knapsack):
 *   Let dp[v][f] = max houses powered in the subtree rooted at v when
 *   the flow into v's parent cable is allowed to be up to f. To
 *   compute dp[v][*]:
 *     1. Merge each child c into a knapsack G[g] = "best children
 *        result using at most g units of flow distributed among them".
 *     2. dp[v][f] = max(G[f], 1 + G[f - r_v]) when f >= r_v,
 *        otherwise dp[v][f] = G[f]. The "1 +" path means v itself is
 *        powered, consuming r_v of f and leaving f - r_v for children.
 *   The generator has unbounded capacity, so the final answer sums
 *   dp[c][c_c] over the direct children c of node 0 (each capped by
 *   their own cable c_c).
 *
 * Complexity:
 *   O(N * Cmax^2) per node merge; with N <= 1000 and Cmax <= 100 this
 *   is bounded by ~10^7 in the worst case -- comfortable in 1 s.
 */

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1005;

static int n;
static int demand[MAXN];
static int capCable[MAXN];
static vector<int> children[MAXN];
static vector<int> dpv[MAXN];  // dpv[v][f] only defined for 1 <= v <= n

static void solve(int v) {
    // Compute every child's table first so the knapsack merge below
    // has them ready.
    for (int c : children[v]) solve(c);

    int maxF = capCable[v];           // flow into v cannot exceed this
    vector<int> G(maxF + 1, 0);       // running knapsack over processed children

    // Knapsack-merge each child: think of it as picking how many flow
    // units to commit to that child (bounded by its cable capacity).
    // Each child contributes dp_child[flow_c] houses for that choice.
    for (int c : children[v]) {
        int cc = capCable[c];
        vector<int> newG(maxF + 1, 0);
        for (int g = 0; g <= maxF; g++) {
            int top = min(cc, g);
            for (int flow_c = 0; flow_c <= top; flow_c++) {
                int val = G[g - flow_c] + dpv[c][flow_c];
                if (val > newG[g]) newG[g] = val;
            }
        }
        G.swap(newG);
    }

    // Fill dp[v][f]: choose whether v itself is powered. Powering v
    // costs r_v of the incoming budget but adds 1 to the count.
    dpv[v].assign(maxF + 1, 0);
    for (int f = 0; f <= maxF; f++) {
        int notPower = G[f];
        int power    = (f >= demand[v]) ? 1 + G[f - demand[v]] : -1;
        dpv[v][f] = max(notPower, power);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p, r, c;
        scanf("%d %d %d", &p, &r, &c);
        demand[i]   = r;
        capCable[i] = c;
        children[p].push_back(i);
    }

    // The generator's "edges" out are simply the cables to its direct
    // children. Each subtree is independent because the generator
    // supplies unlimited energy.
    int total = 0;
    for (int c : children[0]) {
        solve(c);
        total += dpv[c][capCable[c]];
    }

    printf("%d\n", total);
    return 0;
}

/*
 * Beecrowd 3253 — Car Trouble  (NCPC 2011)
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A city center is modelled as a directed graph. Each street has an
 *   integer id in (0, 1000); id 0 is reserved for the surrounding ring
 *   road. An edge u -> v means you can drive directly from u to v.
 *   For each non-zero street X report two failure modes:
 *     - TRAPPED X      -- once on X you cannot reach the ring road
 *                         (no directed path X --*--> 0).
 *     - UNREACHABLE X  -- you cannot enter X from the ring road
 *                         (no directed path 0 --*--> X).
 *   Print TRAPPED lines first, then UNREACHABLE lines, each group in
 *   the order the streets appeared in the input. If no street triggers
 *   either condition, print "NO PROBLEMS". A street can fall in both
 *   categories, in which case it appears in both lists.
 *
 * Input:
 *   Line 1: total number of streets (0 < S <= 1000), including id 0.
 *   Next S lines: id, k, then k destination ids -- one line per street.
 *
 * Output:
 *   The lines described above; either the issue lines or "NO PROBLEMS".
 *
 * Approach:
 *   Build the directed graph and its reverse. Run BFS from vertex 0 on
 *   the forward graph to find every vertex 0 can reach (their absence
 *   means UNREACHABLE). Run BFS from vertex 0 on the reversed graph to
 *   find every vertex that can reach 0 (their absence means TRAPPED).
 *   Iterate the streets in input order and assemble the two lists.
 *
 * Complexity:
 *   O(V + E) for the two traversals. With V <= 1000 and E quadratic in
 *   the worst case (~10^6), this is well within the 1 s budget.
 */

#include <bits/stdc++.h>
using namespace std;

static const int MAXID = 1000;

int main() {
    int s;
    scanf("%d", &s);

    vector<vector<int>> adj(MAXID), radj(MAXID);
    vector<int> order;  // street ids in the order they appear in the input
    order.reserve(s);

    for (int i = 0; i < s; i++) {
        int id, k;
        scanf("%d %d", &id, &k);
        order.push_back(id);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            // Edge id -> v in the forward graph; reverse edge v -> id
            // in the reversed graph used to test reachability TO 0.
            adj[id].push_back(v);
            radj[v].push_back(id);
        }
    }

    // BFS in the forward graph starting from 0 finds every street
    // reachable from the ring road. A non-zero street outside this set
    // is UNREACHABLE.
    vector<bool> reachFrom0(MAXID, false);
    {
        queue<int> q;
        q.push(0);
        reachFrom0[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!reachFrom0[v]) {
                    reachFrom0[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // BFS in the reversed graph from 0 finds every street that has a
    // directed path TO 0. A non-zero street outside this set is TRAPPED.
    vector<bool> canReach0(MAXID, false);
    {
        queue<int> q;
        q.push(0);
        canReach0[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : radj[u]) {
                if (!canReach0[v]) {
                    canReach0[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // Walk the streets in input order so the output preserves it.
    vector<int> trapped, unreachable;
    for (int id : order) {
        if (id == 0) continue;
        if (!canReach0[id])    trapped.push_back(id);
        if (!reachFrom0[id])   unreachable.push_back(id);
    }

    if (trapped.empty() && unreachable.empty()) {
        puts("NO PROBLEMS");
    } else {
        // TRAPPED block first, UNREACHABLE block second, both in
        // input order within their respective list.
        for (int id : trapped)     printf("TRAPPED %d\n", id);
        for (int id : unreachable) printf("UNREACHABLE %d\n", id);
    }

    return 0;
}

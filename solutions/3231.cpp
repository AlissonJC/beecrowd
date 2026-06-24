/*
 * Beecrowd 3231 - Horror List
 *
 * Movies (IDs 0..N-1) are linked by a symmetric "similar to" relation. Some
 * movies are on a horror list. Each movie has a Horror Index (HI): 0 if it is on
 * the horror list; otherwise 1 + the smallest HI among its directly similar
 * movies (the "worst", i.e. most horrible, neighbor); and +infinity if it cannot
 * reach any horror movie through similarities. Print the ID with the highest HI
 * (the safest pick), breaking ties by the smallest ID.
 *
 * Input : first line N H L (1 <= H < N <= 1000, 0 <= L <= 10000); second line the
 *         H horror-list IDs; then L lines "a b" meaning a and b are similar.
 * Output: the ID of the movie with the maximum Horror Index (lowest ID on ties).
 *
 * Approach: the recursive HI is exactly the shortest-path distance, in the
 *   undirected similarity graph, from a movie to the nearest horror-list movie.
 *   Run a multi-source BFS seeded with every horror movie at distance 0; an
 *   unvisited movie is unreachable and counts as +infinity. Scanning IDs in
 *   increasing order and keeping a strict maximum yields the highest HI with the
 *   smallest ID automatically.
 *
 * Complexity: O(N + L) time and space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H, L;
    // EOF loop: handles one instance, or several if the judge stacks them.
    while (cin >> N >> H >> L) {
        vector<vector<int>> adj(N);
        vector<int> dist(N, -1);          // -1 = unvisited / unreachable (HI = +inf)
        queue<int> q;

        // Seed the BFS with all horror-list movies at distance 0.
        for (int i = 0; i < H; ++i) {
            int x; cin >> x;
            if (dist[x] == -1) { dist[x] = 0; q.push(x); }
        }
        for (int i = 0; i < L; ++i) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);          // similarity is mutual
        }

        // Multi-source BFS: HI of a movie = distance to the nearest horror movie.
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u])
                if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
        }

        // Best = maximum HI; unreachable (dist == -1) is +infinity. Strict ">"
        // while scanning ascending IDs keeps the smallest ID on a tie.
        int bestId = 0;
        long long bestHI = -1;
        for (int i = 0; i < N; ++i) {
            long long hi = (dist[i] == -1) ? LLONG_MAX : dist[i];
            if (hi > bestHI) { bestHI = hi; bestId = i; }
        }
        cout << bestId << "\n";
    }
    return 0;
}

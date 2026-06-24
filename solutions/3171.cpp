/*
 * Beecrowd 3171 - String Led
 *
 * A LED string was cut into N labelled segments (1..N). Mariazinha makes L
 * connections, each joining two different segments. The string lights only if
 * every segment ends up joined into a single connected piece. Given the
 * connections, report whether the string is fully joined.
 *
 * Input : first line has N and L (1 <= N <= 100, 1 <= L <= 100). Each of the next
 *         L lines has two segment labels X and Y that are connected.
 * Output: "COMPLETO" if all N segments form one connected piece, else "INCOMPLETO".
 *
 * Approach: model segments as nodes and connections as undirected edges; the
 *   string is complete iff the graph is a single connected component. Union-Find
 *   (disjoint set union) merges the endpoints of every connection, then the
 *   segments are all joined iff they share one representative root.
 *
 * Complexity: O((N + L) * alpha(N)) ~ effectively linear.
 */

#include <bits/stdc++.h>
using namespace std;

int parent[105];

int find(int x) {                                   // path-compressed root lookup
    while (parent[x] != x) x = parent[x] = parent[parent[x]];
    return x;
}

int main() {
    int n, l;
    if (scanf("%d %d", &n, &l) != 2) return 0;
    for (int i = 1; i <= n; ++i) parent[i] = i;     // each segment starts on its own

    for (int e = 0; e < l; ++e) {
        int x, y;
        if (scanf("%d %d", &x, &y) != 2) return 0;
        parent[find(x)] = find(y);                  // join the two connected segments
    }

    // All joined iff every segment shares segment 1's component.
    bool complete = true;
    for (int i = 2; i <= n; ++i)
        if (find(i) != find(1)) { complete = false; break; }

    printf("%s\n", complete ? "COMPLETO" : "INCOMPLETO");
    return 0;
}

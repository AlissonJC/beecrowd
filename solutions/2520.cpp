/*
 * Beecrowd 2520 — The Last Analógimôn
 *
 * In an N x M grid you start at the cell marked 1 and must reach the cell marked
 * 2, moving one cell north/south/east/west per second. The target never moves
 * and the grid has no obstacles (all other cells are 0), so the minimum time
 * equals the Manhattan distance between the two cells.
 *
 * Input:
 *   Several test cases until EOF. Each starts with N and M (2 <= N, M <= 100),
 *   then N lines of M integers (one 1 = your position, one 2 = the target, the
 *   rest 0).
 *
 * Output:
 *   For each test case, the minimum time in seconds.
 *
 * Approach:
 *   Locate the cells holding 1 and 2 while reading, then print
 *   |r1 - r2| + |c1 - c2|. With no obstacles, the shortest 4-directional path
 *   is exactly the Manhattan distance.
 *
 * Complexity:
 *   O(N * M) per test case.
 */

#include <iostream>
#include <cstdlib>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v;
                std::cin >> v;
                if (v == 1) { r1 = i; c1 = j; }       // your position
                else if (v == 2) { r2 = i; c2 = j; }  // the analogimon
            }
        }

        std::cout << std::abs(r1 - r2) + std::abs(c1 - c2) << '\n';
    }

    return 0;
}

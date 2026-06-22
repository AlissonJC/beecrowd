/*
 * Beecrowd 2163 — The Force Awakens
 *
 * A lightsaber appears in an N x M grid as a cell holding 42 whose eight
 * surrounding cells are all 7. Find that cell (there is at most one) and print
 * its 1-based (row, column); print "0 0" if no such cell exists. The center
 * must be an interior cell, since it needs all eight neighbours to exist.
 *
 * Input:
 *   First line: N and M (3 <= N, M <= 1000). Then N lines with M integers each
 *   (-100 <= T_ij <= 100).
 *
 * Output:
 *   "X Y" — the 1-based row X and column Y of the lightsaber, or "0 0".
 *
 * Approach:
 *   Store the grid 1-indexed. Scan every interior cell (rows 2..N-1, columns
 *   2..M-1); a cell is the lightsaber when it equals 42 and all eight
 *   neighbours equal 7. Report the first (and only) such cell.
 *
 * Complexity:
 *   O(N * M) time, O(N * M) space.
 */

#include <iostream>

// Global so the ~4 MB grid lives off the stack; 1-indexed with a 1-cell margin.
static int g[1002][1002];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> g[i][j];

    int ansX = 0, ansY = 0;   // default: lightsaber not found

    // Only interior cells own all eight neighbours.
    for (int i = 2; i <= n - 1 && ansX == 0; ++i) {
        for (int j = 2; j <= m - 1; ++j) {
            if (g[i][j] != 42) continue;
            // The eight-neighbourhood must be uniformly 7.
            bool ok = g[i-1][j-1] == 7 && g[i-1][j] == 7 && g[i-1][j+1] == 7 &&
                      g[i  ][j-1] == 7 &&                    g[i  ][j+1] == 7 &&
                      g[i+1][j-1] == 7 && g[i+1][j] == 7 && g[i+1][j+1] == 7;
            if (ok) {
                ansX = i;
                ansY = j;
                break;
            }
        }
    }

    std::cout << ansX << ' ' << ansY << '\n';
    return 0;
}

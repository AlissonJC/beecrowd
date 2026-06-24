/*
 * Beecrowd 2552 — CheeseBreadSweeper
 *
 * A Minesweeper-style board: each cell either holds a Cheese Bread or shows how
 * many of its orthogonally adjacent cells (left, right, above, below — not
 * diagonal) hold a Cheese Bread. Given which cells hold breads (1) and which do
 * not (0), produce the board: print 9 for a bread cell, otherwise the count of
 * adjacent breads (0..4).
 *
 * Input:
 *   Several test cases until EOF. Each begins with N and M (1 <= N, M <= 100),
 *   then N lines of M integers (0 or 1).
 *
 * Output:
 *   For each test case, N lines of M digits each, with no spaces between them.
 *
 * Approach:
 *   For every cell, output 9 if it holds a bread; otherwise count the 1s among
 *   its four orthogonal neighbours (with bounds checks at the borders).
 *
 * Complexity:
 *   O(N * M) per test case.
 */

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m) {
        std::vector<std::vector<int>> g(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                std::cin >> g[i][j];

        // Orthogonal neighbour offsets: up, down, left, right.
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        std::string out;
        out.reserve(static_cast<size_t>(n) * (m + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 1) {
                    out += '9';                 // this cell holds a bread
                } else {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dr[k], nj = j + dc[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] == 1)
                            ++cnt;              // an adjacent bread
                    }
                    out += static_cast<char>('0' + cnt);   // count is 0..4
                }
            }
            out += '\n';
        }
        std::cout << out;
    }

    return 0;
}

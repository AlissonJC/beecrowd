/*
 * Beecrowd 2783 — Cup Stickers
 *
 * The album has spaces 1..N. Some stickers are already stamped (glued), and a
 * list of purchased stickers (possibly with repeats) is also given. The answer,
 * as fixed by the samples, is how many of the stamped stickers do NOT appear in
 * the purchased list.
 *
 * Input:
 *   First line: N, C, M (1 <= N <= 100, 1 <= C <= N/2, 1 <= M <= 300). Second
 *   line: C distinct stamped stickers. Third line: M purchased stickers (with
 *   possible repeats), each in 1..N.
 *
 * Output:
 *   The number of stamped stickers absent from the purchased list.
 *
 * Approach:
 *   Mark which values appear among the purchased stickers, then count the
 *   stamped ones whose value was never purchased.
 *
 * Complexity:
 *   O(C + M) per test case.
 */

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, c, m;
    while (std::cin >> n >> c >> m) {
        std::vector<int> stamped(c);
        for (int i = 0; i < c; ++i) std::cin >> stamped[i];

        std::vector<bool> purchased(n + 1, false);
        for (int i = 0; i < m; ++i) {
            int y;
            std::cin >> y;
            purchased[y] = true;          // mark each purchased value as present
        }

        // Count stamped stickers that have no purchased copy.
        int answer = 0;
        for (int i = 0; i < c; ++i)
            if (!purchased[stamped[i]])
                ++answer;

        std::cout << answer << '\n';
    }

    return 0;
}

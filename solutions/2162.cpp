/*
 * Beecrowd 2162 — Peaks and Valleys
 *
 * A landscape follows the "Nlogony" pattern when peaks and valleys strictly
 * alternate: a rising measure is never immediately followed by another rise,
 * and a falling measure is never immediately followed by another fall. A
 * measure is a peak when higher than the previous one and a valley when lower;
 * two equal consecutive measures break the pattern (such a measure is neither
 * a peak nor a valley).
 *
 * Input:
 *   Two lines. First: N (1 < N <= 100). Second: N integers H_i
 *   (-10000 <= H_i <= 10000).
 *
 * Output:
 *   1 if the landscape alternates peaks and valleys, otherwise 0.
 *
 * Approach:
 *   Walk through consecutive differences. Each difference must be non-zero
 *   (strictly up or down) and its direction must differ from the previous
 *   difference's direction. Any zero difference, or two equal directions in a
 *   row, makes the answer 0.
 *
 * Complexity:
 *   O(N) time, O(1) extra space.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int prev, cur;
    std::cin >> prev;          // first measure: no preceding direction yet

    bool valid = true;
    int prevDir = 0;           // 0 = no previous transition recorded
    for (int i = 1; i < n; ++i) {
        std::cin >> cur;
        int diff = cur - prev;
        int dir = (diff > 0) - (diff < 0);   // +1 up, -1 down, 0 flat

        // A flat step (neither peak nor valley) or a step in the same
        // direction as the previous one breaks the alternating pattern.
        if (dir == 0 || dir == prevDir)
            valid = false;

        prevDir = dir;
        prev = cur;
    }

    std::cout << (valid ? 1 : 0) << '\n';
    return 0;
}

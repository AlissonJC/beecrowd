/*
 * Beecrowd 2143 — The Return of Radar
 *
 * People sit around a rectangular table. Whoever sits at an end orders once;
 * everyone else orders twice. The seating guarantees the number of people not
 * at the ends is even, which forces exactly one person at the ends when N is
 * odd and exactly two when N is even. The task is the total number of orders.
 *
 * For N people:
 *   - N odd : 1 end seat (1 order) + (N-1) middle seats (2 orders each)
 *             => 1 + 2(N-1) = 2N - 1
 *   - N even: 2 end seats (1 order each) + (N-2) middle seats (2 orders each)
 *             => 2 + 2(N-2) = 2N - 2
 *   Combined: 2N - 2 + (N mod 2).
 *
 * Input:
 *   Repeated blocks: an integer T (1 <= T <= 100), then T integers N
 *   (3 <= N <= 10^4). Read until a block begins with T = 0.
 *
 * Output:
 *   One line per N with the total number of orders; no blank lines between
 *   blocks.
 *
 * Complexity:
 *   O(1) per query.
 */

#include <cstdio>

int main() {
    int t;
    while (scanf("%d", &t) == 1 && t != 0) {
        for (int i = 0; i < t; ++i) {
            int n;
            if (scanf("%d", &n) != 1) return 0;
            // End seats order once, middle seats twice; the parity of N fixes
            // how many people sit at the ends (1 if odd, 2 if even).
            int orders = 2 * n - 2 + (n % 2);
            printf("%d\n", orders);
        }
    }
    return 0;
}

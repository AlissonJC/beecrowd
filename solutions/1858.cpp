/*
 * Beecrowd 1858 - Theon's Answer
 *
 * Theon may accuse any of N people of being his torturer. Accusing person i
 * costs T_i hits. Determine which person he should name to be hit the fewest
 * times; if several people share the minimum cost, choose the one with the
 * smallest index.
 *
 * Input : line 1 - integer N (1 <= N <= 100). Line 2 - N integers T_1..T_N
 *         (0 <= T_i <= 20).
 * Output: the 1-based index of the person with the minimum T value (smallest
 *         index on ties).
 *
 * Approach: scan the values left to right tracking the smallest seen and its
 *           position. Updating only on a STRICTLY smaller value means that when
 *           equal costs appear, the earliest (smallest-index) one is kept, which
 *           is exactly the required tie-break.
 *
 * Complexity: O(N) time, O(1) space.
 */
#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int bestIdx = 1, bestVal = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        if (scanf("%d", &t) != 1) return 0;

        // Take the first value, then replace only on a strictly smaller cost so
        // ties keep the earlier (smaller) index.
        if (i == 1 || t < bestVal) {
            bestVal = t;
            bestIdx = i;
        }
    }

    printf("%d\n", bestIdx);
    return 0;
}

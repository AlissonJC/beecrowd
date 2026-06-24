/*
 * Beecrowd 1789 — The Race of Slugs
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Classify the fastest slug of a group into one of three speed levels:
 *       Level 1: speed < 10 cm/h
 *       Level 2: 10 <= speed < 20 cm/h
 *       Level 3: speed >= 20 cm/h
 *   For each test case, print the level of the group's fastest slug.
 *
 * Input (multi-case, EOF-terminated):
 *   Each case has two lines:
 *     L           (1 <= L <= 500)
 *     L integers  (1 <= V_i <= 50), the slug speeds.
 *
 * Output (per case):
 *   1, 2 or 3 -- the level of the group's maximum speed.
 *
 * Approach:
 *   Stream speeds in, keep the running maximum, then map it to a level
 *   with two threshold comparisons.
 *
 * Complexity:
 *   O(L) per test case.
 */

#include <cstdio>

int main() {
    int L;
    while (scanf("%d", &L) == 1) {
        int maxV = 0;
        for (int i = 0; i < L; i++) {
            int v;
            scanf("%d", &v);
            if (v > maxV) maxV = v;
        }
        // Two threshold comparisons: <10 -> 1, <20 -> 2, else 3.
        int level = (maxV < 10) ? 1 : (maxV < 20 ? 2 : 3);
        printf("%d\n", level);
    }
    return 0;
}

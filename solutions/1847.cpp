/*
 * Beecrowd 1847 — Welcome to the Winter!
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Given three temperatures A, B and C from three consecutive days,
 *   decide if the people of Westeros are happy ":)" or sad ":(" based
 *   on how the temperatures changed. Letting d1 = B - A and d2 = C - B,
 *   the eight cases reduce to:
 *       d1 < 0, d2 >= 0    -> happy   (dropped, then non-decreasing)
 *       d1 > 0, d2 <= 0    -> sad     (rose, then non-increasing)
 *       d1 > 0, d2 > 0     -> happy iff d2 >= d1 (rise must steepen)
 *       d1 < 0, d2 < 0     -> happy iff d2 >  d1 (descent must slow down,
 *                                                  i.e. |d2| < |d1|)
 *       d1 = 0, d2 > 0     -> happy
 *       d1 = 0, d2 <= 0    -> sad
 *
 * Input:
 *   One line with three integers A B C, -100 <= each <= 100.
 *
 * Output:
 *   ":)" for happy, ":(" for sad, followed by a newline.
 *
 * Approach:
 *   Compute the two consecutive deltas and branch through the cases
 *   above. The rules cleanly partition all (d1, d2) sign combinations,
 *   so a small if/else chain suffices.
 *
 * Complexity:
 *   O(1).
 */

#include <cstdio>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int d1 = b - a;
    int d2 = c - b;

    bool happy;
    if (d1 < 0 && d2 >= 0) {
        // Temperature dropped from day 1 to day 2, then rose or held.
        happy = true;
    } else if (d1 > 0 && d2 <= 0) {
        // Temperature rose from day 1 to day 2, then fell or held.
        happy = false;
    } else if (d1 > 0 && d2 > 0) {
        // Two consecutive rises: happy when the second rise is at least
        // as steep as the first.
        happy = (d2 >= d1);
    } else if (d1 < 0 && d2 < 0) {
        // Two consecutive drops: happy when the second drop is gentler
        // than the first (|d2| < |d1|, which is d2 > d1 since both
        // values are negative).
        happy = (d2 > d1);
    } else {
        // d1 == 0: temperature was steady on day 2, then either rose
        // (happy) or did not (sad).
        happy = (d2 > 0);
    }

    puts(happy ? ":)" : ":(");
    return 0;
}

/*
 * Beecrowd 2780 — Robot Basketball
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Map a launch distance D (in centimeters, 0 <= D <= 2000) to a point
 *   value based on three zones drawn from the basket:
 *       D <= 800            -> 1 point
 *       800 < D <= 1400     -> 2 points
 *       1400 < D <= 2000    -> 3 points
 *   Print the matching integer 1, 2, or 3.
 *
 * Input:
 *   A single integer D (0 <= D <= 2000).
 *
 * Output:
 *   1, 2, or 3, on a single line.
 *
 * Approach:
 *   Direct conditional. The sample D = 1400 confirms the boundary goes
 *   to the 2-point zone (the rule is "<= 1400", not "< 1400").
 *
 * Complexity:
 *   O(1).
 */

#include <cstdio>

int main() {
    int d;
    scanf("%d", &d);

    // The "<=" on the 800 and 1400 boundaries is what the problem
    // states; using "<" would shift the 1400 sample from 2 to 3 and WA.
    int pts;
    if (d <= 800)       pts = 1;
    else if (d <= 1400) pts = 2;
    else                pts = 3;

    printf("%d\n", pts);
    return 0;
}

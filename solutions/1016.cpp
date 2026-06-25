/*
 * Beecrowd 1016 - Distance
 *
 * Two cars travel in the same direction; the faster one (Y) pulls away from the
 * slower one (X) at a rate of 1 km every 2 minutes. Given a target gap in
 * kilometers, compute how many minutes car Y needs to open that gap.
 *
 * Input : one integer value, the distance in km.
 * Output: the required time, followed by a space and the literal message
 *         "minutos" (Portuguese for "minutes"), then a trailing newline
 *         (omitting it causes a Presentation Error on Beecrowd).
 *
 * Approach: since the gap grows 1 km per 2 minutes, the time to open a gap of
 *           D km is simply 2 * D minutes -- a direct closed-form calculation.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    int distance;
    if (scanf("%d", &distance) != 1) return 0;

    // 1 km gained every 2 minutes => D km needs 2 * D minutes.
    int minutes = distance * 2;

    // "minutos" is Portuguese per the statement -- keep the literal as-is.
    printf("%d minutos\n", minutes);
    return 0;
}

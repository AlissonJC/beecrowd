/*
 * Beecrowd 3084 - Old Clock
 *
 * A clock's hands move only in whole steps: the minute hand advances 6 degrees
 * per completed minute and the hour hand 30 degrees per completed hour (both at 0
 * degrees at 00:00). Given the measured angles of the hour and minute hands,
 * recover the time.
 *
 * Input : several test cases (EOF), each two integers h and m (0 <= h, m < 360),
 *         the hour-hand and minute-hand angles.
 * Output: the time as "hh:mm" with two digits each.
 *
 * Approach: since the hands land only on discrete marks, h is a multiple of 30
 *   and m a multiple of 6, so the hour is h / 30 and the minute is m / 6.
 *
 * Complexity: O(1) per test case.
 */

#include <cstdio>

int main() {
    int h, m;
    while (scanf("%d %d", &h, &m) == 2)
        printf("%02d:%02d\n", h / 30, m / 6);   // 30 deg per hour, 6 deg per minute
    return 0;
}

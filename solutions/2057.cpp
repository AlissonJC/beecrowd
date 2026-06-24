/*
 * Beecrowd 2057 — Time Zone
 *
 * Given a departure hour S, a travel duration T (in hours) and the
 * destination time-zone offset F relative to the origin, compute the local
 * arrival hour at the destination on a 24-hour clock. The raw arrival hour is
 * S + T + F; the answer is that value reduced into [0, 23] (so 24 prints as 0,
 * and a negative result wraps around from the previous day).
 *
 * Input:
 *   Three space-separated integers S, T, F:
 *     0 <= S <= 23, 1 <= T <= 12, -5 <= F <= 5.
 *
 * Output:
 *   A single integer: the destination local time, in 0..23.
 *
 * Approach:
 *   Sum the three values and take it modulo 24. Because the sum can be
 *   negative (F goes down to -5), use the ((x % 24) + 24) % 24 idiom so the
 *   result is always non-negative.
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <cstdio>

int main() {
    int s, t, f;
    if (scanf("%d %d %d", &s, &t, &f) != 3) return 0;

    // Reduce the raw arrival hour into [0, 23]. Adding 24 before the final
    // modulo guards against a negative sum (e.g. S=0, T=3, F=-4 -> -1 -> 23).
    int hour = ((s + t + f) % 24 + 24) % 24;

    printf("%d\n", hour);
    return 0;
}

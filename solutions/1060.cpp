/*
 * Beecrowd 1060 - Positive Numbers
 *
 * Read six numbers (each positive or negative) and report how many of them are
 * positive.
 *
 * Input : six numbers, which may be positive or negative and may have a
 *         fractional part (the sample includes -3.4 and 4.6).
 * Output: the line "<count> valores positivos" -- "valores positivos" is
 *         Portuguese for "positive values"; keep the literal. End with a
 *         newline (omitting it causes a Presentation Error on Beecrowd).
 *
 * Approach: read each value as a double (some inputs are fractional) and count
 *           those strictly greater than zero. Using "> 0" naturally excludes
 *           any zero ("null") value, since zero is neither positive nor
 *           negative.
 *
 * Complexity: O(6) time, O(1) space.
 */

#include <cstdio>

int main() {
    int positives = 0;

    // Read all six values; increment the counter for each strictly positive one.
    for (int i = 0; i < 6; ++i) {
        double value;
        if (scanf("%lf", &value) != 1) return 0;
        if (value > 0) ++positives;
    }

    // "valores positivos" is Portuguese per the statement -- do not translate.
    printf("%d valores positivos\n", positives);
    return 0;
}

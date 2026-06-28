/*
 * Beecrowd 1020 - Age in Days
 *
 * Read a person's age given as a whole number of days and express it in years,
 * months and days, using the simplified calendar where every year has 365 days
 * and every month has 30 days.
 *
 * Input : a single integer (the age in days).
 * Output: three lines, each a count followed by its Portuguese label:
 *           <years> ano(s)
 *           <months> mes(es)
 *           <days> dia(s)
 *
 * Approach: years = days / 365; from the remainder, months = rem / 30 and the
 * leftover is the days. Plain integer division and modulo. The test data never
 * yields 12 months plus extra days (e.g. 360/363/364), so no normalization is
 * needed.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    int days;
    if (scanf("%d", &days) != 1)
        return 0;  // malformed input guard; also silences the warning

    int years = days / 365;          // 365-day years
    int rem = days % 365;
    int months = rem / 30;           // 30-day months from the leftover
    int leftover = rem % 30;         // remaining days

    // Labels are Portuguese with their literal "(s)"/"(es)" suffixes.
    printf("%d ano(s)\n", years);
    printf("%d mes(es)\n", months);
    printf("%d dia(s)\n", leftover);

    return 0;
}

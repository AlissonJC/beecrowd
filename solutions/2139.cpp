/*
 * Beecrowd 2139 — Pedrinho's Christmas
 *
 * For dates in the leap year 2016, report how many days remain until Christmas
 * (December 25). Given a month and day, print a message depending on whether
 * the date is Christmas, Christmas Eve, already past Christmas, or an earlier
 * day (in which case state how many days are left).
 *
 * Input:
 *   Several test cases until EOF; each line has two integers: the month and
 *   the day of year 2016.
 *
 * Output (Portuguese, verbatim — no accents):
 *   "E natal!"                       if the date is Dec 25
 *   "E vespera de natal!"            if the date is Dec 24
 *   "Ja passou!"                     if the date is after Dec 25
 *   "Faltam X dias para o natal!"    otherwise, X = days left
 *
 * Approach:
 *   Convert each date to a day-of-year using cumulative month lengths for the
 *   leap year 2016 (February has 29 days). Christmas is day-of-year 360. The
 *   signed difference to 360 selects the message: 0 -> Christmas, 1 -> Eve,
 *   negative -> already passed, otherwise that many days remain.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <cstdio>

int main() {
    // daysBefore[m] = number of days in 2016 before month m begins (m = 1..12).
    // 2016 is a leap year, so February contributes 29 days.
    static const int daysBefore[13] = {
        0,   0,  31,  60,  91, 121, 152,
        182, 213, 244, 274, 305, 335
    };

    const int CHRISTMAS = 335 + 25;  // day-of-year of December 25 = 360

    int month, day;
    while (scanf("%d %d", &month, &day) == 2) {
        int doy  = daysBefore[month] + day;  // day-of-year of the given date
        int diff = CHRISTMAS - doy;          // days until Christmas (signed)

        if (diff == 0) {
            puts("E natal!");                // Dec 25
        } else if (diff == 1) {
            puts("E vespera de natal!");     // Dec 24 (exactly one day before)
        } else if (diff < 0) {
            puts("Ja passou!");              // any date after Dec 25
        } else {
            printf("Faltam %d dias para o natal!\n", diff);
        }
    }

    return 0;
}

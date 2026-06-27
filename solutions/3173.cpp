/*
 * Beecrowd 3173 - Christmas Star
 *
 * Jupiter and Saturn align ("Christmas Star") on December 21, 2020. Jupiter's
 * orbital period is 11.9 Earth years and Saturn's is 29.6 Earth years. Given N,
 * compute, for each planet, the number of days elapsed after N full orbits and
 * the calendar date reached, counting from December 21, 2020 and including the
 * extra days of leap years.
 *
 * Days elapsed: N * period_years * 365.25 (the 0.25 averages in leap days),
 * truncated to an integer. To dodge floating-point rounding at exact bounds,
 * compute it with integers: period * 10 is 119 (Jupiter) and 296 (Saturn), and
 * 365.25 * 100 is 36525, so days = N * (period*10) * 36525 / 1000.
 *
 * Calendar date: convert Dec 21, 2020 to a Julian Day Number, add the elapsed
 * days, and convert back. JDN conversion bakes in the real Gregorian leap-year
 * rule, so the resulting date is exact.
 *
 * Input : integer N (0 < N <= 50), possibly several cases until EOF.
 * Output: four lines per case -- days and date for Jupiter, then for Saturn:
 *           Dias terrestres para Jupiter = <days>
 *           Data terrestre para Jupiter: <yyyy-mm-dd>
 *           Dias terrestres para Saturno = <days>
 *           Data terrestre para Saturno: <yyyy-mm-dd>
 *
 * Complexity: O(1) per test case.
 */

#include <cstdio>

// Gregorian calendar date -> Julian Day Number (Fliegel-Van Flandern).
static long long toJDN(long long y, long long m, long long d) {
    long long a = (14 - m) / 12;
    long long yy = y + 4800 - a;
    long long mm = m + 12 * a - 3;
    return d + (153 * mm + 2) / 5 + 365 * yy + yy / 4 - yy / 100 + yy / 400 - 32045;
}

// Julian Day Number -> Gregorian calendar date.
static void fromJDN(long long jdn, long long &y, long long &m, long long &d) {
    long long a = jdn + 32044;
    long long b = (4 * a + 3) / 146097;
    long long c = a - (146097 * b) / 4;
    long long dd = (4 * c + 3) / 1461;
    long long e = c - (1461 * dd) / 4;
    long long mm = (5 * e + 2) / 153;
    d = e - (153 * mm + 2) / 5 + 1;
    m = mm + 3 - 12 * (mm / 10);
    y = 100 * b + dd - 4800 + mm / 10;
}

int main() {
    // Julian Day Number of the starting alignment, December 21, 2020.
    const long long START = toJDN(2020, 12, 21);

    long long n;
    while (scanf("%lld", &n) == 1) {
        // Integer-only day counts: period*10 (119, 296) times 36525 (=365.25*100)
        // gives period*365.25*1000; dividing by 1000 truncates as required.
        long long daysJup = n * 119 * 36525 / 1000;
        long long daysSat = n * 296 * 36525 / 1000;

        long long y, m, d;

        fromJDN(START + daysJup, y, m, d);
        printf("Dias terrestres para Jupiter = %lld\n", daysJup);
        printf("Data terrestre para Jupiter: %04lld-%02lld-%02lld\n", y, m, d);

        fromJDN(START + daysSat, y, m, d);
        printf("Dias terrestres para Saturno = %lld\n", daysSat);
        printf("Data terrestre para Saturno: %04lld-%02lld-%02lld\n", y, m, d);
    }

    return 0;
}

/*
 * Beecrowd 1959 — Regular Simple Polygons
 * Time limit: 1 s
 *
 * Problem:
 *   Read two integers N (number of sides, 3 <= N <= 1,000,000) and
 *   L (side length, 1 <= L <= 4,000). Print the perimeter N * L.
 *
 * Note:
 *   The product can reach 1,000,000 * 4,000 = 4 * 10^9, which overflows
 *   a signed 32-bit int. Use 64-bit arithmetic.
 */

#include <cstdio>

int main() {
    long long n, l;
    scanf("%lld %lld", &n, &l);
    printf("%lld\n", n * l);
    return 0;
}

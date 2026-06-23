/*
 * Beecrowd 1630 - Stakes
 *
 * Surround an X by Y rectangular site with equally spaced stakes using as few
 * stakes as possible. The stakes lie on the perimeter and consecutive stakes are
 * always the same distance apart. To enclose the rectangle the four corners must
 * carry stakes, so the spacing has to divide both side lengths X and Y. The
 * largest spacing that does so is gcd(X, Y), and a larger spacing means fewer
 * stakes, so the answer is the whole perimeter divided by that spacing:
 *     2 * (X + Y) / gcd(X, Y).
 *
 * Input : several test cases, each a line with two integers X and Y
 *         (1 <= X, Y <= 1e8). Read until end of file.
 * Output: the minimum number of stakes, one per line.
 *
 * Complexity: O(log(min(X, Y))) per test case for the gcd.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    // EOF-terminated: keep reading pairs until input runs out.
    while (scanf("%lld %lld", &x, &y) == 2) {
        long long g = __gcd(x, y);          // largest spacing landing on every corner
        // 2*(x+y) <= 4e8 fits in 32 bits, but long long keeps it obviously safe.
        printf("%lld\n", 2 * (x + y) / g);
    }
    return 0;
}

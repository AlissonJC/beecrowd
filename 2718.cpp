/*
 * Beecrowd 2718 - "Christmas Lights"
 *
 * Christmas lights are split into groups of 50 bulbs. Within a group, a burned
 * bulb is a binary 1 and a working bulb a binary 0, and the group is recorded
 * as the decimal value X of that 50-bit binary number. For each group, report
 * the length of the longest stretch of CONSECUTIVE burned bulbs - i.e. the
 * longest run of consecutive 1-bits in the binary representation of X.
 *
 * Input : line 1 -> N (1 <= N <= 10^3) number of groups.
 *         next N lines -> one integer X per group.
 * Output: N lines, the longest run of 1-bits of each X, in input order.
 *
 * Approach  : scan X bit by bit from the least significant end, keeping the
 *             current run of 1s and the best run seen so far.
 * Complexity: O(bits) per group (<= ~50), O(1) space.
 *
 * Type note: a group holds 50 bulbs, so X may reach 2^50 - 1 ~= 1.1*10^15,
 * which overflows 32-bit int. X MUST be read as a 64-bit value - here an
 * unsigned long long, which also keeps the bit shifts clean.
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        unsigned long long x;
        cin >> x;

        // Longest run of consecutive set bits = longest streak of burned bulbs.
        int best = 0, cur = 0;
        while (x) {
            if (x & 1ULL) {              // current lowest bulb is burned
                cur++;
                if (cur > best) best = cur;
            } else {                     // a working bulb breaks the streak
                cur = 0;
            }
            x >>= 1;
        }
        // x == 0 (all bulbs working) naturally yields best == 0.
        cout << best << "\n";
    }
    return 0;
}

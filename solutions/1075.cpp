/*
 * Beecrowd 1075 - Remaining 2
 *
 * Read an integer N and print every number between 1 and 10000 (inclusive) that
 * leaves remainder 2 when divided by N, one per line.
 *
 * Input : a single integer N (N < 10000).
 * Output: all x in [1, 10000] with x % N == 2, in increasing order, one per line.
 *
 * Approach: The numbers leaving remainder 2 modulo N are exactly 2, 2+N, 2+2N,
 * ... -- the arithmetic progression starting at 2 with step N. The first term,
 * 2, is already >= 1, so enumerate from 2 stepping by N while staying <= 10000.
 * A remainder of 2 is only possible when the divisor exceeds 2 (a remainder is
 * always smaller than the divisor), so for N <= 2 there is simply nothing to
 * print; guarding on N > 2 also avoids any division and degenerate stepping.
 *
 * Complexity: O(10000 / N) lines produced, O(1) space.
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // Remainder 2 requires divisor N > 2; otherwise no number qualifies.
    if (n > 2) {
        // Walk the progression 2, 2+N, 2+2N, ... each leaving remainder 2.
        for (int x = 2; x <= 10000; x += n) {
            std::cout << x << "\n";
        }
    }

    return 0;
}

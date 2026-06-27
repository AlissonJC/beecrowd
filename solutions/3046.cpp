/*
 * Beecrowd 3046 - Domino
 *
 * A double-N domino set contains every unordered pair {a, b} with values from
 * 0 to N (including doubles a = b). The number of such pieces is given by the
 * closed formula (N + 1) * (N + 2) / 2. Given N, print how many pieces a
 * double-N set has.
 *
 * Input : a single natural number N (0 <= N <= 10000).
 * Output: a single natural number, the piece count (N + 1) * (N + 2) / 2.
 *
 * Approach: Apply the given formula. The product (N + 1) * (N + 2) reaches
 * about 10^8 for the largest N, which still fits in 32 bits, but compute it in
 * 64-bit to be safe against any overflow. (N + 1)(N + 2) is a product of two
 * consecutive integers, hence always even, so the integer division by 2 is
 * exact.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    // Two consecutive factors guarantee an even product, so /2 has no remainder.
    std::cout << (n + 1) * (n + 2) / 2 << "\n";

    return 0;
}

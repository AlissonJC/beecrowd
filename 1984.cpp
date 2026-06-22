/*
 * Beecrowd 1984 — The Pronalandia Puzzle
 *
 * Problem (restated in English):
 *   Given a single non-negative integer n on input, print its digits in
 *   reverse order. The catch is that reversing a number with trailing
 *   zeros must keep those zeros at the front of the output — e.g.
 *   9876543210 reverses to "0123456789", not to 123456789.
 *
 * Input  : one integer n with 0 < n < 9_999_999_999 (up to 10 digits).
 * Output : the digits of n in reverse order, followed by a newline.
 *          A missing '\n' yields Presentation Error on Beecrowd.
 *
 * Approach:
 *   Read the input as a std::string and reverse it. Treating the value
 *   as text — rather than as an integer — solves two problems at once:
 *     1. It preserves leading zeros that appear after reversal, which
 *        any numeric type would silently drop.
 *     2. It avoids worrying about which integer width is wide enough
 *        (10-digit values exceed the 32-bit unsigned range of ~4.29e9).
 *
 * Complexity:
 *   Time  O(L), Space O(L), where L is the number of digits (L <= 10).
 *   The dominant operation is the in-place reverse of the digit string.
 */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string n;
    std::cin >> n;            // read the number as text to preserve every digit

    std::reverse(n.begin(), n.end());

    // Trailing '\n' is mandatory — Beecrowd flags its absence as Presentation Error.
    std::cout << n << '\n';
    return 0;
}

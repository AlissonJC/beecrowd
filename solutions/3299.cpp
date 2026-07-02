/*
 * Beecrowd 3299 — Small Unlucky Numbers
 *
 * A number is "unlucky" when its decimal digits contain a 1 immediately
 * followed by a 3 — i.e. the substring "13". The second sample nails the
 * interpretation: 12321 has a 1 before a 3 but not adjacent, and it is NOT
 * unlucky, while 341329 (which contains "...13...") is.
 *
 * Input:
 *   An integer N (0 <= N <= 10^17), one per run.
 *
 * Output:
 *   "N es de Mala Suerte"    if N contains the substring "13",
 *   "N NO es de Mala Suerte" otherwise,
 *   where N is echoed back exactly as read. The Spanish message is printed
 *   verbatim from the statement — do not translate.
 *
 * Approach:
 *   Read N as a string: 10^17 has 18 digits (it would still fit in a
 *   64-bit integer, but the string makes the substring test and the echo
 *   trivial and format-proof). Unlucky simply means find("13") succeeds.
 *   Reading in an EOF loop costs nothing for a single-case file and also
 *   survives judges that pack several values into one file.
 *
 * Complexity:
 *   O(len(N)) per number — at most 18 characters.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string n;
    while (std::cin >> n) {
        // Unlucky = digits contain "13" as an adjacent pair.
        bool unlucky = n.find("13") != std::string::npos;

        std::cout << n << (unlucky ? " es de Mala Suerte"
                                   : " NO es de Mala Suerte") << '\n';
    }

    return 0;
}

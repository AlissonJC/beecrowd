/*
 * Beecrowd 2762 — Input and Output 6
 *
 * Read a number written as XXXXX.YYY and print it inverted as YYY.XXXXX: the
 * fractional digits become the new integer part (so their leading zeros vanish,
 * e.g. 023 -> 23) and the original integer digits become the new fractional
 * part, kept verbatim.
 *
 * Input:
 *   Several test cases until EOF, each a real number with 3 decimal places.
 *
 * Output:
 *   For each number, its inverted form.
 *
 * Approach:
 *   Split the token at the dot. Parse the fractional part as an integer (which
 *   strips its leading zeros) for the new integer part, and keep the original
 *   integer part as the new fractional part.
 *
 * Complexity:
 *   O(length) per test case.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    while (std::cin >> s) {
        std::string::size_type dot = s.find('.');
        std::string intPart  = s.substr(0, dot);     // becomes the fractional part
        std::string fracPart = s.substr(dot + 1);    // becomes the integer part

        // Parsing drops the leading zeros of the new integer part (023 -> 23).
        long long newInt = std::stoll(fracPart);

        std::cout << newInt << '.' << intPart << '\n';
    }

    return 0;
}

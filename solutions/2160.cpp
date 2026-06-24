/*
 * Beecrowd 2160 — Name at Form
 *
 * Given one line of text L, decide whether it fits in a form field that holds
 * 80 characters: print "YES" when |L| <= 80, otherwise "NO".
 *
 * Input:
 *   A single line L with 1 <= |L| <= 500 (it may contain spaces).
 *
 * Output:
 *   "YES" if the line is at most 80 characters long, otherwise "NO".
 *
 * Approach:
 *   Read the entire line with getline (so embedded spaces are preserved) and
 *   compare its length against 80.
 *
 * Complexity:
 *   O(|L|) time and space.
 */

#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);

    // Drop a trailing carriage return from CRLF input so it does not inflate
    // the measured length by one near the 80-character boundary.
    if (!line.empty() && line.back() == '\r')
        line.pop_back();

    std::cout << (line.length() <= 80 ? "YES" : "NO") << '\n';
    return 0;
}

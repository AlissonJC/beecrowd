/*
 * Beecrowd 2165 — Twitting
 *
 * A tweet may hold at most 140 characters. Given one line of text T, print
 * "TWEET" if it fits (|T| <= 140) and "MUTE" otherwise.
 *
 * Input:
 *   A single line T with 1 <= |T| <= 500 (it may contain spaces).
 *
 * Output:
 *   "TWEET" if the line is at most 140 characters long, otherwise "MUTE".
 *
 * Approach:
 *   Read the entire line with getline (so embedded spaces are preserved) and
 *   compare its length against 140.
 *
 * Complexity:
 *   O(|T|) time and space.
 */

#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);

    // Drop a trailing carriage return from CRLF input so it does not inflate
    // the measured length near the 140-character boundary.
    if (!line.empty() && line.back() == '\r')
        line.pop_back();

    std::cout << (line.length() <= 140 ? "TWEET" : "MUTE") << '\n';
    return 0;
}

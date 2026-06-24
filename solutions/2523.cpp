/*
 * Beecrowd 2523 — Will's Message
 *
 * Twenty-six bulbs (numbered 1..26) each have a letter beneath them, given by a
 * 26-character string: position i (1-based) holds the letter for bulb i. Will
 * blinks a sequence of bulbs; the message is the letters under the blinked
 * bulbs, in order.
 *
 * Input:
 *   Several test cases until EOF. Each has a line with 26 uppercase letters
 *   (the bulb->letter mapping), a line with N (1 <= N <= 10^4), and a line with
 *   N bulb numbers l_i (1 <= l_i <= 26).
 *
 * Output:
 *   For each test case, the decoded message on its own line.
 *
 * Approach:
 *   For each blinked bulb b, append mapping[b - 1], converting the 1-based bulb
 *   number to a 0-based string index.
 *
 * Complexity:
 *   O(N) per test case.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string mapping;
    while (std::cin >> mapping) {
        int n;
        std::cin >> n;

        std::string message;
        message.reserve(n);
        for (int i = 0; i < n; ++i) {
            int bulb;
            std::cin >> bulb;
            message += mapping[bulb - 1];   // 1-based bulb -> 0-based index
        }

        std::cout << message << '\n';
    }

    return 0;
}

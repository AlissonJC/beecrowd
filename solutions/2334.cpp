/*
 * Beecrowd 2334 — Little Ducks
 *
 * In the "five little ducks" rhyme, P ducks set out and, verse by verse, one
 * fewer returns until none come back. For each P the answer is the count of
 * ducks that did not come back, which the samples define as P - 1 for P >= 1
 * and 0 for P = 0 (that is, max(0, P - 1)).
 *
 * Input:
 *   Several test cases, each an integer P (0 <= P <= 10^19); the list ends with
 *   P = -1. Since 10^19 exceeds the signed 64-bit range, P is read as text and
 *   parsed into an unsigned 64-bit integer (which holds up to ~1.8 * 10^19).
 *
 * Output:
 *   For each P, print max(0, P - 1).
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string token;
    while (std::cin >> token) {
        if (token == "-1") break;        // sentinel ends the input

        unsigned long long p = std::stoull(token);
        // P = 0 yields 0 (avoids underflow); otherwise one duck per verse fails
        // to return, leaving P - 1.
        std::cout << (p == 0 ? 0ULL : p - 1) << '\n';
    }

    return 0;
}

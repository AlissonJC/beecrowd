/*
 * Beecrowd 2510 — Batmain
 *
 * Per the story, Batman had already captured every one of his villains before
 * the chaos began, so for each queried villain the answer is always that he was
 * indeed arrested. The villain's name does not affect the result.
 *
 * Input:
 *   First line: T test cases. Each of the next T lines is a villain name
 *   (1..25 letters, [a-z, A-Z]).
 *
 * Output:
 *   "Y" for each villain (all of them were captured).
 *
 * Complexity:
 *   O(T) time, O(1) space.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::string name;
    while (t-- > 0) {
        std::cin >> name;        // read the villain name; every villain was caught
        std::cout << "Y\n";
    }

    return 0;
}

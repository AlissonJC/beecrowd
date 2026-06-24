/*
 * Beecrowd 2653 — Dijkstra
 *
 * Each jewel is described by a string of '(' and ')'. Count how many distinct
 * jewel strings appear in the input.
 *
 * Input:
 *   Several lines until EOF, each a string of '(' and ')'. The total length of
 *   all strings does not exceed 10^6.
 *
 * Output:
 *   The number of different jewel strings.
 *
 * Approach:
 *   Insert every string into a hash set and report its size; duplicate jewels
 *   collapse into a single entry automatically.
 *
 * Complexity:
 *   O(total length) on average.
 */

#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_set<std::string> kinds;
    std::string s;
    while (std::cin >> s) {
        kinds.insert(s);          // duplicate jewels collapse into one entry
    }

    std::cout << kinds.size() << '\n';
    return 0;
}

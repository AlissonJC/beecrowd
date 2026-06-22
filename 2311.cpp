/*
 * Beecrowd 2311 — Diving
 *
 * In a diving competition each dive has a degree of difficulty and is scored by
 * seven judges (0..10). The single highest and single lowest scores are
 * discarded; the remaining five are summed and multiplied by the degree of
 * difficulty to give the final score. Print each diver's final score in input
 * order.
 *
 * Input:
 *   First line: N divers (0 <= N <= 100). For each diver: a line with the name,
 *   a line with the difficulty D (1.2 <= D <= 3.8), and a line with seven
 *   scores S1..S7 (0 <= Si <= 10).
 *
 * Output:
 *   For each diver, "<name> <final score>" with two decimal places.
 *
 * Approach:
 *   Sum the seven scores, then subtract the maximum and the minimum. This
 *   discards exactly one highest and one lowest score even when values tie.
 *   Multiply the remaining sum by D.
 *
 * Complexity:
 *   O(N) time, O(1) space.
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << std::fixed << std::setprecision(2);

    std::string name;
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, name);          // name may contain spaces

        double d;
        std::cin >> d;

        double sum = 0.0, hi = -1.0, lo = 11.0;   // scores lie within [0, 10]
        for (int j = 0; j < 7; ++j) {
            double s;
            std::cin >> s;
            sum += s;
            hi = std::max(hi, s);
            lo = std::min(lo, s);
        }
        // Advance past the newline so the next getline reads the next name.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Drop one highest and one lowest, then scale by the difficulty.
        double finalScore = (sum - hi - lo) * d;

        std::cout << name << ' ' << finalScore << '\n';
    }

    return 0;
}

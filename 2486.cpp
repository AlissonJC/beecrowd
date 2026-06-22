/*
 * Beecrowd 2486 — C Mais ou Menos?
 *
 * Given how much of each vitamin-C-rich food a person eats in a day, decide how
 * far their total vitamin C is from the recommended daily range [110, 130] mg.
 * Each food contributes a fixed amount of vitamin C per unit:
 *   suco de laranja 120, morango fresco 85, mamao 85, goiaba vermelha 70,
 *   manga 56, laranja 50, brocolis 34 (mg).
 *
 * Input:
 *   Several test cases. Each starts with T (1 <= T <= 7), then T lines, each
 *   with an amount N followed by a food name (which may contain spaces). The
 *   input ends with T = 0.
 *
 * Output (per test case), with total = sum of N * (vitamin C of the food):
 *   total > 130 -> "Menos <total-130> mg"   (must consume that much less)
 *   total < 110 -> "Mais <110-total> mg"     (must consume that much more)
 *   otherwise   -> "<total> mg"
 *
 * Approach:
 *   Map each food name to its vitamin C value, accumulate N * value over the T
 *   foods, then compare the total against the [110, 130] window.
 *
 * Complexity:
 *   O(T) per test case.
 */

#include <iostream>
#include <string>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::map<std::string, long long> vitC = {
        {"suco de laranja", 120}, {"morango fresco", 85}, {"mamao", 85},
        {"goiaba vermelha", 70},  {"manga", 56},          {"laranja", 50},
        {"brocolis", 34}
    };

    int t;
    while (std::cin >> t && t != 0) {
        long long total = 0;

        for (int i = 0; i < t; ++i) {
            long long n;
            std::cin >> n;

            std::string food;
            std::getline(std::cin, food);   // rest of the line: " <food name>"

            // Trim surrounding whitespace (leading space after N, trailing \r).
            size_t a = food.find_first_not_of(" \t\r\n");
            size_t b = food.find_last_not_of(" \t\r\n");
            food = (a == std::string::npos) ? "" : food.substr(a, b - a + 1);

            total += n * vitC.at(food);     // food is guaranteed to be in table
        }

        // The recommended window is [110, 130] mg, inclusive.
        if (total > 130)
            std::cout << "Menos " << (total - 130) << " mg\n";
        else if (total < 110)
            std::cout << "Mais " << (110 - total) << " mg\n";
        else
            std::cout << total << " mg\n";
    }

    return 0;
}

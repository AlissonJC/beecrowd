/*
 * Beecrowd 2862 - Insect!
 *
 * A tracker classifies a living being by its energy level. If the level is at
 * most 8000, the being is regarded as an insect; once the level exceeds 8000,
 * the tracker announces that it is over 8000. Classify each measured level.
 *
 * Input : first line has an integer C, the number of test cases. Each of the
 *         next C lines holds an integer N (100 <= N <= 100000), an energy level.
 * Output: for each N, print "Inseto!" if N <= 8000, otherwise "Mais de 8000!".
 *
 * Approach: A direct threshold comparison per value -- no algorithm beyond
 * reading each level and testing it against 8000.
 *
 * Complexity: O(C) time, O(1) space.
 */

#include <iostream>

int main() {
    int c;
    std::cin >> c;

    while (c--) {
        int n;
        std::cin >> n;

        // Boundary: exactly 8000 still counts as an insect; only values
        // strictly greater than 8000 trigger the "over 8000" message.
        // Output strings are kept verbatim from the statement (Portuguese,
        // including the trailing '!') so they match the judge byte for byte.
        if (n <= 8000)
            std::cout << "Inseto!\n";
        else
            std::cout << "Mais de 8000!\n";
    }

    return 0;
}

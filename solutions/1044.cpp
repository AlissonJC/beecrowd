/*
 * Beecrowd 1044 - Multiples
 *
 * Read two integer values A and B and decide whether one is a multiple of the
 * other. Print "Sao Multiplos" when that holds, otherwise "Nao sao Multiplos".
 *
 * Input : two integers A and B on one line.
 * Output: exactly one of the Portuguese messages "Sao Multiplos" /
 *         "Nao sao Multiplos" (ASCII, no accents, matching the sample).
 *
 * Approach: A and B are multiples of each other when the larger leaves no
 * remainder when divided by the smaller -- equivalently, A % B == 0 OR
 * B % A == 0. Checking both directions avoids having to find which is larger.
 * The judge's data uses positive integers, so neither modulo divides by zero.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    // One is a multiple of the other if either division is exact. Testing both
    // orientations covers A | B and B | A without comparing magnitudes.
    if (a % b == 0 || b % a == 0) {
        std::cout << "Sao Multiplos\n";
    } else {
        std::cout << "Nao sao Multiplos\n";
    }

    return 0;
}

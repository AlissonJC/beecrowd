/*
 * Beecrowd 1067 - Odd Numbers
 *
 * Read an integer X and print every odd number from 1 up to X (inclusive),
 * one per line. X itself is printed when it is odd.
 *
 * Input : a single integer X, 1 <= X <= 1000.
 * Output: the odd numbers 1, 3, 5, ... not exceeding X, each on its own line.
 *
 * Approach: Start at 1 (the first odd number) and step by 2. Each step lands on
 * the next odd number, so no parity test is needed; the loop naturally stops
 * at the largest odd value <= X.
 *
 * Complexity: O(X) time, O(1) space.
 */

#include <iostream>

int main() {
    int x;
    std::cin >> x;

    // Begin at the first odd number and advance two at a time to hit only odds.
    for (int i = 1; i <= x; i += 2) {
        std::cout << i << "\n";
    }

    return 0;
}

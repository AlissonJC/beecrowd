/*
 * Beecrowd 1065 - Even Between five Numbers
 *
 * Read five integer values and count how many of them are even, then print
 * that count followed by the Portuguese phrase "valores pares".
 *
 * Input:  five integers, one per line (they may be negative).
 * Output: a single line "<count> valores pares" (all lowercase), where
 *         <count> is how many of the five values are even.
 *
 * Approach: pure ad-hoc counting. A value is even when it is divisible by 2.
 *           In C++ the sign of "n % 2" follows the dividend, so for any
 *           integer (positive, negative or zero) the test "n % 2 == 0"
 *           correctly identifies even numbers: e.g. -4 % 2 == 0 (even),
 *           -5 % 2 == -1 (odd). No need for abs().
 *
 * Complexity: O(1) time and space — a fixed five-iteration loop.
 */

#include <iostream>

int main() {
    int evenCount = 0;

    // Read exactly five integers; increment the counter on each even value.
    for (int i = 0; i < 5; ++i) {
        int value;
        std::cin >> value;
        if (value % 2 == 0) {
            ++evenCount;
        }
    }

    // Output uses the Portuguese phrase required by the statement; keep it
    // lowercase and end with a newline (Beecrowd expects a trailing '\n').
    std::cout << evenCount << " valores pares\n";

    return 0;
}

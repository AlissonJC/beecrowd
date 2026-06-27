/*
 * Beecrowd 3091 - Rest 1.0
 *
 * Given two integers A and B, print the remainder of the integer division
 * A divided by B.
 *
 * Input : two integers A and B (1 <= A, B <= 100000).
 * Output: a single integer, the remainder A mod B.
 *
 * Approach: Apply the modulo operator directly. Both values are positive, so
 * the result is the usual non-negative remainder.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    // Both operands are positive, so % yields the standard remainder in [0, B).
    std::cout << (a % b) << "\n";

    return 0;
}

/*
 * Beecrowd 2791 - Bean
 *
 * A grain of beans is hidden under one of four opaque cups. After the game,
 * the state of each cup is given: 1 if the bean is under cup i, 0 if that cup
 * is empty. Exactly one cup holds the bean. Report under which cup it is.
 *
 * Input : one line with four integers C1 C2 C3 C4 (each 0 or 1), space
 *         separated; exactly one of them equals 1.
 * Output: a single integer between 1 and 4 -- the position of the bean.
 *
 * Approach: Read the four flags and print the 1-based index of the one equal
 * to 1. A single linear scan over four values suffices.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    // Scan the four cups; the position guaranteed to hold the bean is the
    // index (1-based) whose flag is 1.
    for (int i = 1; i <= 4; ++i) {
        int c;
        std::cin >> c;
        if (c == 1) {
            std::cout << i << "\n";
            // Read out the remaining values to leave the stream clean; not
            // strictly required, but harmless. Break is enough since the
            // answer is already determined.
            break;
        }
    }

    return 0;
}

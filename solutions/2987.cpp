/*
 * Beecrowd 2987 - Balloon of Honor
 *
 * Given a single uppercase letter, report its 1-based position in the English
 * alphabet (A = 1, B = 2, ..., Z = 26).
 *
 * Input : a single character L, an uppercase letter from 'A' to 'Z'.
 * Output: a single integer, the position of that letter in the alphabet.
 *
 * Approach: Uppercase letters occupy consecutive ASCII codes, so subtracting
 * the code of 'A' gives a 0-based offset; adding 1 yields the 1-based position.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    char l;
    std::cin >> l;  // '>>' skips any leading whitespace and reads one letter

    // ASCII codes for 'A'..'Z' are contiguous; the distance from 'A' plus one
    // is the letter's position in the alphabet.
    std::cout << (l - 'A' + 1) << "\n";

    return 0;
}

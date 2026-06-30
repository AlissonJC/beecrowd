/*
 * Beecrowd 1080 - Highest and Position
 *
 * Read 100 distinct positive integers and report the largest one together with
 * the position (1-indexed) at which it appeared in the input.
 *
 * Input : 100 distinct positive integers, separated by whitespace/newlines.
 * Output: two lines - the highest value, then its input position (1-based).
 *
 * Approach: a single linear pass keeps the best value seen so far and the
 * position where it occurred. Because the numbers are guaranteed distinct there
 * is no tie to break, so a strict "greater than" comparison is enough.
 *
 * Complexity: O(N) time with N = 100, O(1) space.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int highest = 0;    // largest value read so far (inputs are positive)
    int position = 0;   // 1-based index where 'highest' was read

    // Scan all 100 numbers, updating the running maximum and its position.
    for (int i = 1; i <= 100; ++i) {
        int value;
        std::cin >> value;
        if (value > highest) {
            highest = value;
            position = i;
        }
    }

    // First line: the maximum value. Second line: its input position.
    std::cout << highest << '\n' << position << '\n';

    return 0;
}

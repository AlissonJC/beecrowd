/*
 * Beecrowd 1097 - Sequence IJ 3
 *
 * Print a fixed sequence of lines "I=<i> J=<j>". The outer counter I takes the
 * odd values 1, 3, 5, 7, 9. For each I, the inner counter J starts at I+6 and
 * counts down three values: I+6, I+5, I+4.
 *
 * Input : none.
 * Output: 15 lines (5 values of I times 3 values of J), from "I=1 J=7" down to
 *         "I=9 J=13".
 *
 * Approach: two nested loops. The outer loop walks I over the odd numbers in
 * [1, 9] with step +2. The inner J range is anchored to the current I: it runs
 * from I+6 down to I+4, so the window slides up by 2 every time I does.
 *
 * Complexity: O(1) time and space - a constant number of lines.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // I covers the odd numbers 1..9; J's three-value window is anchored at I+6.
    for (int i = 1; i <= 9; i += 2)
        for (int j = i + 6; j >= i + 4; --j)
            std::cout << "I=" << i << " J=" << j << '\n';

    return 0;
}

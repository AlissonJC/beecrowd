/*
 * Beecrowd 1096 - Sequence IJ 2
 *
 * Print a fixed sequence of lines "I=<i> J=<j>". The outer counter I takes the
 * odd values 1, 3, 5, 7, 9; for each I, the inner counter J counts down 7, 6, 5.
 *
 * Input : none.
 * Output: 15 lines (5 values of I times 3 values of J), from "I=1 J=7" down to
 *         "I=9 J=5".
 *
 * Approach: two nested loops. The outer loop walks I over the odd numbers in
 * [1, 9] with step +2; the inner loop walks J from 7 down to 5 with step -1,
 * restarting at 7 for every new I.
 *
 * Complexity: O(1) time and space - a constant number of lines.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // I covers the odd numbers 1, 3, 5, 7, 9; for each, J counts down 7, 6, 5.
    for (int i = 1; i <= 9; i += 2)
        for (int j = 7; j >= 5; --j)
            std::cout << "I=" << i << " J=" << j << '\n';

    return 0;
}

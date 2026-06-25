/*
 * Beecrowd 1095 - Sequence IJ 1
 *
 * Print a fixed sequence of lines "I=<i> J=<j>" where I starts at 1 and grows
 * by 3 on each line, while J starts at 60 and falls by 5 on each line. The
 * sequence stops on the line where J reaches 0.
 *
 * Input : none.
 * Output: 13 lines, from "I=1 J=60" down to "I=37 J=0".
 *
 * Approach: advance two coupled counters together - I += 3 and J -= 5 per line
 * - and loop while J is still non-negative. Since J runs 60, 55, ..., 0 that
 * is exactly 13 iterations, and I ends at 1 + 3*12 = 37.
 *
 * Complexity: O(1) time and space - a constant number of lines.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // I climbs by 3 from 1; J drops by 5 from 60. Keep going through the J=0 line.
    for (int i = 1, j = 60; j >= 0; i += 3, j -= 5)
        std::cout << "I=" << i << " J=" << j << '\n';

    return 0;
}

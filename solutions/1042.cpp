/*
 * Beecrowd 1042 - Simple Sort
 *
 * Read three integers, print them in ascending order (one per line), then a
 * blank line, and finally the three values again in the original input order.
 *
 * Input : three integers on one line.
 * Output: the three values sorted ascending (one per line), a blank line, then
 *         the three values in the order they were read (one per line).
 *
 * Approach: Keep the original three values and a sorted copy. With only three
 * numbers, sorting is trivial -- sort the copy and print both blocks.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>
#include <algorithm>

int main() {
    int v[3];
    std::cin >> v[0] >> v[1] >> v[2];

    // Sorted copy for the first block; the original order is kept in v[] for
    // the second block.
    int s[3] = {v[0], v[1], v[2]};
    std::sort(s, s + 3);

    // Ascending block.
    std::cout << s[0] << "\n" << s[1] << "\n" << s[2] << "\n";
    // Blank separator line.
    std::cout << "\n";
    // Original input order.
    std::cout << v[0] << "\n" << v[1] << "\n" << v[2] << "\n";

    return 0;
}

/*
 * Beecrowd 1070 - Six Odd Numbers
 *
 * Read a positive integer X and print the first six consecutive odd numbers
 * starting from X, one per line. X itself is included when it is already odd;
 * otherwise the sequence begins at the next odd number after X.
 *
 * Input : a single positive integer X.
 * Output: six odd numbers, one per line.
 *
 * Approach: choose the starting odd value - X when X is odd, X + 1 when X is
 * even - then print six terms of the arithmetic progression with common
 * difference 2. Stepping by 2 from an odd number always lands on odd numbers.
 *
 * Complexity: O(1) time and space.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    std::cin >> x;

    // First odd number at or after X: keep X when odd, advance to X+1 when even.
    int start = (x % 2 == 0) ? x + 1 : x;

    // Six consecutive odds form an arithmetic progression with step 2.
    for (int i = 0; i < 6; ++i)
        std::cout << start + 2 * i << '\n';

    return 0;
}

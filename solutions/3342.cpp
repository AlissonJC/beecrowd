/*
 * Beecrowd 3342 — Keanu
 *
 * Count the white and black squares of an n x n chessboard whose topmost,
 * leftmost square is white. Colors alternate in both directions, so the
 * board is a checkerboard pattern starting on white.
 *
 * Input:
 *   A single integer n (2 <= n <= 100).
 *
 * Output:
 *   One line: "a casas brancas e b casas pretas", where a is the number of
 *   white squares and b the number of black squares. The samples show the
 *   message in Portuguese even though the statement's prose is English —
 *   print exactly what the Output Samples show.
 *
 * Approach:
 *   On a checkerboard the two colors split the n*n squares as evenly as
 *   possible, and the starting color gets the extra square when the total
 *   is odd. Hence white = ceil(n^2 / 2) = (n^2 + 1) / 2 with integer
 *   division, and black = n^2 / 2. Check: n=3 -> 5 white / 4 black,
 *   n=4 -> 8 / 8, matching both samples and the figures.
 *
 * Complexity:
 *   O(1) time and space. Max total is 100*100 = 10000, far within int.
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int total = n * n;
    int white = (total + 1) / 2;  // starting (white) color takes the odd extra square
    int black = total / 2;

    // Portuguese output per the Output Samples — do not translate.
    std::cout << white << " casas brancas e " << black << " casas pretas\n";

    return 0;
}

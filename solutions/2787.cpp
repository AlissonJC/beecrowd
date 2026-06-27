/*
 * Beecrowd 2787 - Chess
 *
 * A chessboard has L rows and C columns. The square at row 1, column 1
 * (upper-left corner) is always white, and the colors alternate like a real
 * chessboard. Determine the color of the square in the lower-right corner,
 * i.e. the square at row L, column C.
 *
 * Input : line 1 -> L (1 <= L <= 1000), the number of rows
 *         line 2 -> C (1 <= C <= 1000), the number of columns
 * Output: a single line containing 1 if that square is white, 0 if black.
 *
 * Approach: Color the board by the parity of (row + column). Since (1, 1) is
 * white and has sum 2 (even), a square is white exactly when row + column is
 * even. The lower-right square is (L, C), so it is white iff (L + C) is even.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int L, C;
    std::cin >> L >> C;

    // White when the coordinate sum is even, black when it is odd.
    std::cout << ((L + C) % 2 == 0 ? 1 : 0) << "\n";

    return 0;
}

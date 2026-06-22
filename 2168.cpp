/*
 * Beecrowd 2168 — Twilight at Portland
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Downtown Portland is laid out as an N x N grid of square blocks.
 *   Each block has four corners, and at each corner there may be a
 *   working surveillance camera (1) or no working camera (0). A block
 *   is "safe" iff at least two of its four corners host a working
 *   camera. Given the (N+1) x (N+1) camera map, print an N x N grid
 *   of 'S' (safe) / 'U' (unsafe) labels, one row per line.
 *
 * Input:
 *   Line 1: N (1 <= N <= 100).
 *   Next N + 1 lines: N + 1 integers each (0 or 1), the camera presence
 *   at each corner of the downtown lattice, row-major.
 *
 * Output:
 *   N lines, each with N characters. The character at row i, column j
 *   is 'S' if block (i, j) has at least two cameras among the four
 *   corners (i, j), (i, j+1), (i+1, j), (i+1, j+1); otherwise 'U'.
 *
 * Approach:
 *   Read the corner grid into an (N+1) x (N+1) array, then for each
 *   block at (i, j) sum the four touching corner values and emit
 *   'S' if the sum is >= 2 and 'U' otherwise.
 *
 * Complexity:
 *   O(N^2) corner reads and O(N^2) block evaluations. With N <= 100
 *   that is at most 10 000 + 10 000 operations -- trivial.
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    // Static-size array sized for the upper bound; n is small enough
    // that no dynamic allocation is needed.
    static int corner[101][101];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%d", &corner[i][j]);
        }
    }

    // For each block (i, j) sum the four corners that touch it and
    // emit 'S' if that sum is at least 2, 'U' otherwise. Print row by
    // row with no separators between characters and a trailing newline.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cameras = corner[i][j] + corner[i][j+1]
                        + corner[i+1][j] + corner[i+1][j+1];
            putchar(cameras >= 2 ? 'S' : 'U');
        }
        putchar('\n');
    }

    return 0;
}

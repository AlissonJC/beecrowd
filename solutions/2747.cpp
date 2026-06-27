/*
 * Beecrowd 2747 — Output 1
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Print a fixed rectangular frame:
 *     - a top line of 39 dashes '-';
 *     - five "wall" lines, each with a '|' under the first and the
 *       thirty-ninth dash and 37 spaces in between (total width 39);
 *     - a bottom line identical to the top (39 dashes).
 *   There is no input — the figure is always the same.
 *
 * Input:
 *   None.
 *
 * Output:
 *   The 7-line frame described above, each line 39 characters wide, with
 *   no trailing spaces and a newline after every line.
 *
 * Approach:
 *   Emit the constant figure directly: build the horizontal border once,
 *   print it, print the five wall lines, then print the border again. The
 *   wall interior is exactly 37 spaces so the right '|' lands on column 39,
 *   matching the dash above it.
 *
 * Complexity:
 *   O(1) — a constant amount of output.
 */

#include <cstdio>

int main() {
    const int WIDTH = 39;   // total columns per line
    const int WALLS = 5;    // procedure 2 once + four repeats

    // Top border: 39 dashes.
    for (int i = 0; i < WIDTH; i++) putchar('-');
    putchar('\n');

    // Wall lines: '|', then 37 interior spaces, then '|'. The interior
    // count is WIDTH - 2 so the closing bar sits on the last column.
    for (int row = 0; row < WALLS; row++) {
        putchar('|');
        for (int i = 0; i < WIDTH - 2; i++) putchar(' ');
        putchar('|');
        putchar('\n');
    }

    // Bottom border: identical to the top.
    for (int i = 0; i < WIDTH; i++) putchar('-');
    putchar('\n');

    return 0;
}

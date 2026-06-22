/*
 * Beecrowd 2749 — Output 3
 *
 * Print a fixed 39-column "screen": top and bottom borders of 39 dashes, with
 * five inner rows bounded by '|' at columns 1 and 39. Three inner rows contain
 * the text "x = 35" starting under the 2nd, 17th and 33rd dash respectively; the
 * remaining two inner rows are blank. There is no input.
 *
 * Output:
 *   The exact 7-line drawing described above (every line is 39 characters wide).
 *
 * Approach:
 *   Build each line from "x = 35" plus exact runs of spaces so the borders land
 *   on columns 1 and 39 and the text starts on the required column.
 *
 * Complexity:
 *   O(1).
 */

#include <iostream>
#include <string>

int main() {
    const std::string dashes(39, '-');

    std::cout << dashes << '\n';
    // "x = 35" at column 2 (under the 2nd dash); blanks fill up to the border.
    std::cout << "|x = 35" << std::string(31, ' ') << "|" << '\n';
    // Blank inner row.
    std::cout << "|" << std::string(37, ' ') << "|" << '\n';
    // "x = 35" at column 17 (under the 17th dash), centered.
    std::cout << "|" << std::string(15, ' ') << "x = 35" << std::string(16, ' ') << "|" << '\n';
    // Blank inner row.
    std::cout << "|" << std::string(37, ' ') << "|" << '\n';
    // "x = 35" at column 33 (under the 33rd dash); it reaches the right border.
    std::cout << "|" << std::string(31, ' ') << "x = 35" << "|" << '\n';
    std::cout << dashes << '\n';

    return 0;
}

/*
 * Beecrowd 2748 — Output 2
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Print a fixed framed screen, 39 columns wide:
 *     - a top border of 39 dashes '-';
 *     - a wall line with the word "Roberto" starting under the 10th dash;
 *     - an empty wall line;
 *     - a wall line with the number "5786" starting under the 10th dash;
 *     - another empty wall line;
 *     - a wall line with the word "UNIFEI" starting under the 10th dash;
 *     - a bottom border identical to the top.
 *   Each wall line has a '|' under the 1st and the 39th dash, with the
 *   text placed at column 10 and the remaining interior filled with
 *   spaces. There is no input.
 *
 * Input:
 *   None.
 *
 * Output:
 *   The 7-line figure described above, every line exactly 39 characters
 *   wide, no trailing spaces, newline after each line.
 *
 * Approach:
 *   Build each wall line as a 39-char buffer pre-filled with spaces, set
 *   the bars at the two ends (columns 1 and 39), and copy the label in
 *   starting at column 10 (index 9). The borders are simply 39 dashes.
 *
 * Complexity:
 *   O(1) — constant-size output.
 */

#include <iostream>
#include <string>

namespace {

const int WIDTH = 39;       // columns per line
const int TEXT_START = 9;   // 0-based index of column 10

// Border line: 39 dashes.
std::string border() {
    return std::string(WIDTH, '-');
}

// Wall line: spaces everywhere, '|' at both ends, label placed so its
// first character sits under the 10th dash (column 10). An empty label
// yields a blank wall line.
std::string wall(const std::string& label) {
    std::string line(WIDTH, ' ');
    line[0] = '|';
    line[WIDTH - 1] = '|';
    for (std::size_t i = 0; i < label.size(); ++i) {
        line[TEXT_START + i] = label[i];
    }
    return line;
}

}  // namespace

int main() {
    std::cout << border() << "\n";
    std::cout << wall("Roberto") << "\n";
    std::cout << wall("") << "\n";         // empty wall (procedure 3)
    std::cout << wall("5786") << "\n";
    std::cout << wall("") << "\n";         // repeat procedure 3
    std::cout << wall("UNIFEI") << "\n";
    std::cout << border() << "\n";
    return 0;
}

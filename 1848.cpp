/*
 * Beecrowd 1848 — Counting Crow
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A three-eyed crow communicates lottery results. Each input line is
 *   either a blink (three eyes, each '*' for open or '-' for closed,
 *   left eye most significant) which encodes a binary value 0..7, or
 *   the scream "caw caw" which emits the running sum so far and resets
 *   it to zero. The crow screams exactly three times.
 *
 * Input:
 *   Multiple lines, each either "caw caw" or a blink. Blink chars may
 *   be separated by spaces ("- - *") or packed ("--*"); both layouts
 *   are accepted by reading the line and scanning for '*' / '-'.
 *
 * Output:
 *   Three lines, one per scream, each holding the lottery result.
 *
 * Approach:
 *   Read each line. If it contains the substring "caw" it is a scream:
 *   print the accumulator and reset. Otherwise it is a blink: scan its
 *   characters, shifting an accumulator left and OR-ing in 1 for every
 *   '*', 0 for every '-'. The blink's value is then added to the
 *   running sum.
 *
 * Complexity:
 *   O(total characters in the input). Trivial.
 */

#include <iostream>
#include <string>

int main() {
    int sum = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.find("caw") != std::string::npos) {
            // Scream: emit the accumulated total and reset.
            std::cout << sum << "\n";
            sum = 0;
        } else {
            // Blink line: read eyes left to right, building a binary
            // number with the leftmost '*'/'-' as the most significant
            // bit. Whitespace between eye characters is ignored.
            int val = 0;
            for (char c : line) {
                if (c == '*')      val = (val << 1) | 1;
                else if (c == '-') val =  val << 1;
            }
            sum += val;
        }
    }
    return 0;
}

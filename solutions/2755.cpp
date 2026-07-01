/*
 * Beecrowd 2755 — Output 9
 *
 * A pure-output exercise: there is no input. Print four fixed lines exactly as
 * given by the problem's Output Sample. The lines are made of punctuation
 * "faces" plus one embedded TAB character on the first line.
 *
 * Input:
 *   None ("There is not.").
 *
 * Output (exact, four lines):
 *   Line 1: a quoted string with a TAB between "Ro'b'er" and "to", then \/ and a
 *           closing quote — i.e.  "Ro'b'er<TAB>to\/"  with no space before the \.
 *   Line 2: five faces separated by single spaces. The 2nd, 3rd and 4th carry a
 *           space just inside the parentheses — "( l: )", "( .-. )", "( :l )" —
 *           while the 1st and 5th are compact "(._.)".
 *   Line 3: (^_-) (-_-) (-_^)
 *   Line 4: ("_") ('.')
 *
 * Approach:
 *   Nothing to compute — emit the four literal lines. The only care needed is
 *   escaping the double quotes and backslash, and writing a real tab ('\t')
 *   where the statement notes "Between r and t has a tab". Line 2 follows the
 *   Output Sample rather than the prose: the sample spaces the inside of three
 *   faces even though the prose shows two of them compact.
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <iostream>

int main() {
    // Line 1: \" -> ", \t -> the required tab, \\ -> a single backslash, then /.
    std::cout << "\"Ro'b'er\tto\\/\"\n";
    // Line 2: faces 2-4 have a space just inside the parentheses (per the sample).
    std::cout << "(._.) ( l: ) ( .-. ) ( :l ) (._.)\n";
    // Line 3: three compact faces separated by single spaces.
    std::cout << "(^_-) (-_-) (-_^)\n";
    // Line 4: \" prints the literal double quotes around the underscore.
    std::cout << "(\"_\") ('.')\n";
    return 0;
}

/*
 * Beecrowd 2126 — Searching Subsequences
 *
 * N1 is a "contiguous subsequence" of N2 when the decimal digits of N1 occur
 * in N2 in the same order and adjacent to each other — i.e. the string of N1
 * is a substring of the string of N2. For each pair (N1, N2) report how many
 * times N1 occurs in N2 and the 1-based starting position of the LAST
 * occurrence; if it never occurs, report that instead.
 *
 * Input:
 *   Several test cases until EOF. Each case has N1 on one line (1 < N1 < 10^10)
 *   and N2 on the next (N1 < N2 < 10^32). N2 can reach 32 digits, far beyond
 *   64-bit range, so both values are handled as strings rather than integers.
 *
 * Output (per case, followed by a blank line):
 *   Caso #X:
 *   Qtd.Subsequencias: <count>
 *   Pos: <1-based start of the last occurrence>
 *   ...or, when there is no occurrence:
 *   Caso #X:
 *   Nao existe subsequencia
 *
 * Approach:
 *   Scan N2 for every starting index where N1 matches, advancing one position
 *   at a time so overlapping occurrences are counted too. Track the number of
 *   matches and the position of the last one.
 *
 * Complexity:
 *   O(|N2| * |N1|) per test case (at most ~32 * 10), trivial for these limits.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string n1, n2;
    int caseNum = 0;
    std::string out;

    // Reading with >> consumes whitespace/newlines, naturally pairing N1 with
    // N2 and stopping at EOF.
    while (std::cin >> n1 >> n2) {
        ++caseNum;

        int count = 0;
        int lastPos = 0;  // 1-based start of the last match (0 = none found)

        // Advance from pos + 1 (not pos + length) so overlapping matches count.
        std::string::size_type pos = n2.find(n1);
        while (pos != std::string::npos) {
            ++count;
            lastPos = static_cast<int>(pos) + 1;   // store as 1-based
            pos = n2.find(n1, pos + 1);
        }

        out += "Caso #";
        out += std::to_string(caseNum);
        out += ":\n";
        if (count > 0) {
            out += "Qtd.Subsequencias: ";
            out += std::to_string(count);
            out += "\nPos: ";
            out += std::to_string(lastPos);
            out += '\n';
        } else {
            // Portuguese message per the statement — keep verbatim.
            out += "Nao existe subsequencia\n";
        }
        out += '\n';   // blank line after each case
    }

    std::cout << out;
    return 0;
}

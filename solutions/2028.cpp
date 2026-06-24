/*
 * Beecrowd 2028 — Sequence of Sequence
 *
 * For a given N, build the sequence that starts with 0 and then lists every
 * value k from 1 to N repeated k times:
 *     0 1 2 2 3 3 3 4 4 4 4 ... N (N times)
 * Report how many numbers the full sequence contains, then the sequence
 * itself. The total length is 1 + (1 + 2 + ... + N) = 1 + N(N+1)/2 (the
 * leading 0 plus k copies of each k).
 *
 * Input:
 *   Several test cases until EOF, each a single integer N (0 <= N <= 200).
 *
 * Output:
 *   For the i-th case (1-indexed) print:
 *     "Caso i: C numero"    when C == 1
 *     "Caso i: C numeros"   when C > 1
 *   then a line with the sequence values separated by single spaces, then a
 *   blank line after each case.
 *
 * Complexity:
 *   O(C) per case, where C = 1 + N(N+1)/2 <= 20101 is the sequence length.
 */

#include <cstdio>
#include <string>

int main() {
    int n;
    int caseNum = 0;
    std::string out;          // accumulate all output, flush once at the end
    out.reserve(1 << 16);

    while (scanf("%d", &n) == 1) {
        ++caseNum;

        // Total count: leading 0 plus k copies of each value k in 1..N.
        int total = 1 + n * (n + 1) / 2;

        // Header. Portuguese words per the statement; the singular "numero"
        // only occurs for N = 0, where total == 1.
        out += "Caso ";
        out += std::to_string(caseNum);
        out += ": ";
        out += std::to_string(total);
        out += (total == 1) ? " numero\n" : " numeros\n";

        // Sequence line: print 0 first, then prepend a space before every
        // later value so there is no trailing space.
        out += '0';
        for (int k = 1; k <= n; ++k) {
            std::string s = std::to_string(k);
            for (int c = 0; c < k; ++c) {   // value k appears exactly k times
                out += ' ';
                out += s;
            }
        }
        out += '\n';

        // Blank line after each case, as required.
        out += '\n';
    }

    fputs(out.c_str(), stdout);
    return 0;
}

/*
 * Beecrowd 2763 — CPF Input and Output
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Read a Brazilian CPF written as XXX.YYY.ZZZ-DD (four integer groups
 *   separated by dots and a dash) and print the four groups, one per line,
 *   exactly as they were typed.
 *
 * Input:
 *   Several test cases until end-of-file, one CPF per line in the format
 *   XXX.YYY.ZZZ-DD.
 *
 * Output:
 *   For each CPF, four lines: XXX, YYY, ZZZ, DD, each printed exactly as
 *   read.
 *
 * Approach:
 *   Read the four groups as STRINGS, not integers — the phrase "as it has
 *   been entered" means leading zeros must be kept (e.g. "025" stays "025",
 *   "00" stays "00"), which parsing to int would destroy. scanf splits on
 *   the literal '.' and '-' delimiters; the leading space in the format
 *   skips the newline between consecutive lines so the loop runs to EOF.
 *
 * Complexity:
 *   O(total input length).
 */

#include <cstdio>

int main() {
    char a[64], b[64], c[64], d[64];

    // %[^.] reads up to the next '.', etc.; the literal '.' and '-' consume
    // the delimiters. The leading space skips the newline before each line,
    // so the four scanset reads stay aligned across test cases.
    while (scanf(" %[^.].%[^.].%[^-]-%s", a, b, c, d) == 4) {
        // Print each group verbatim, one per line (leading zeros preserved).
        printf("%s\n%s\n%s\n%s\n", a, b, c, d);
    }

    return 0;
}

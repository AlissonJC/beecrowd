/*
 * Beecrowd 3142 — Excel Bug
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Excel labels its columns with letters: A=1, B=2, ..., Z=26, then
 *   AA=27, AB=28, ..., AZ=52, BA=53, ..., ZZ=702, then AAA=703, and so
 *   on until XFD = 16384, the last existing column. Given a column code
 *   (1..10 uppercase letters), output its numeric position. If the code
 *   sits outside the valid range [1, 16384] -- i.e., it would index a
 *   column beyond XFD -- output the Portuguese sentence
 *       Essa coluna nao existe Tobias!
 *   verbatim (no quotes, no accents).
 *
 * Input (multi-case, EOF-terminated):
 *   Each line holds one column code S, |S| in [1, 10], letters in A..Z.
 *
 * Output (per case):
 *   Either the integer position or the error message above.
 *
 * Approach:
 *   Standard base-26 conversion with the "bijective" A=1 mapping
 *   (Excel-style: there is no zero digit). Iterate the characters
 *   left to right and accumulate value = value * 26 + (c - 'A' + 1).
 *   Compare against 16384 at the end. long long is plenty: 10 letters
 *   reach at most ~10^14, far inside the 64-bit range.
 *
 * Complexity:
 *   O(|S|) per query.
 */

#include <cstdio>
#include <cstring>

int main() {
    char s[16];
    while (scanf("%15s", s) == 1) {
        // Walk the letters left-to-right, treating each as a base-26
        // digit in the [1, 26] range (no zero -- bijective numeration).
        long long value = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            value = value * 26 + (s[i] - 'A' + 1);
        }

        // "XFD" is the last legal Excel column, valued 16384. Anything
        // higher (or zero, which cannot happen for non-empty input)
        // triggers the Portuguese error message verbatim.
        if (value < 1 || value > 16384) {
            puts("Essa coluna nao existe Tobias!");
        } else {
            printf("%lld\n", value);
        }
    }
    return 0;
}

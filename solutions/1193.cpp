/*
 * Beecrowd 1193 — Base Conversion
 * Time limit: 3 s
 *
 * Problem (restated in English):
 *   Julian is learning to convert numbers between binary, decimal, and
 *   hexadecimal. We help him verify his work: given a number X in one of
 *   those three bases (identified by the 3-letter tag "bin", "dec", or
 *   "hex"), print X expressed in the OTHER two bases.
 *
 * Input:
 *   First line: integer N (number of test cases).
 *   Next N lines: a token X followed by a 3-char tag Y in {bin, dec, hex}.
 *   X is positive and fits in a 32-bit integer.
 *
 * Output:
 *   For each test case i (1-indexed):
 *       Case i:
 *       <value> dec      (only if Y != "dec")
 *       <value> hex      (only if Y != "hex", lowercase letters)
 *       <value> bin      (only if Y != "bin")
 *   Order is always dec -> hex -> bin, skipping the source base.
 *   A blank line follows every test case, including the last one.
 *
 * Approach:
 *   For each case, parse X with strtoul using base 2/10/16 according to Y.
 *   Then print the two other representations using printf format specifiers
 *   "%u" (decimal) and "%x" (lowercase hex), and a manual binary builder
 *   since printf has no standard binary specifier.
 *
 * Complexity:
 *   O(N * log X) total. Effectively constant per test case for 32-bit X.
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        char x[40];     // a 32-bit number fits comfortably in <= 32 binary chars
        char base[8];   // 3-char tag plus null terminator, with slack
        scanf("%s %s", x, base);

        // Parse the input number according to its declared base.
        // strtoul handles the full unsigned 32-bit range (0 .. 2^32 - 1),
        // which is wider than signed int. The problem only guarantees
        // "32-bit integer" without specifying signedness, so we play safe.
        unsigned int value;
        if (strcmp(base, "bin") == 0) {
            value = (unsigned int) strtoul(x, nullptr, 2);
        } else if (strcmp(base, "dec") == 0) {
            value = (unsigned int) strtoul(x, nullptr, 10);
        } else { // "hex"
            value = (unsigned int) strtoul(x, nullptr, 16);
        }

        printf("Case %d:\n", i);

        // Always emit in the order dec -> hex -> bin, skipping the source base.
        if (strcmp(base, "dec") != 0) {
            printf("%u dec\n", value);
        }
        if (strcmp(base, "hex") != 0) {
            // "%x" produces lowercase hex digits a-f, matching the spec.
            // Uppercase "%X" would cause Wrong Answer here.
            printf("%x hex\n", value);
        }
        if (strcmp(base, "bin") != 0) {
            // Build the binary representation manually: collect digits
            // low-bit first, then emit them in reverse to get the
            // natural high-bit-first reading order.
            char buf[33];
            int k = 0;
            unsigned int v = value;
            if (v == 0) {
                buf[k++] = '0';
            } else {
                while (v > 0) {
                    buf[k++] = (char) ('0' + (v & 1u));
                    v >>= 1;
                }
            }
            while (k--) {
                putchar(buf[k]);
            }
            puts(" bin");
        }

        // Blank line after every test case, including the last one.
        // The statement requires it explicitly; omitting it triggers
        // Presentation Error on Beecrowd.
        putchar('\n');
    }

    return 0;
}

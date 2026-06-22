/*
 * Beecrowd 1236 — Compressing Null and White
 * Time limit: 1 s
 *
 * Read N test cases. For every line, compress runs of consecutive
 * '0's or ' 's into two-byte tokens: '$' followed by chr(count) for
 * spaces, '#' followed by chr(count) for zeros. The byte after the
 * sentinel literally encodes the count, so it can be any value in
 * 1..255 (chr(255) renders as a non-printable byte). Special rules:
 *   - Runs of length 1 or 2 are kept as-is (compression would not
 *     save bytes).
 *   - If a run exceeds 255 chars, split into successive 255-sized
 *     blocks plus a final remainder. A remainder of 1 or 2 is not
 *     compressed, so a run of 256 becomes "$<chr 255>" plus a single
 *     literal space, a run of 257 becomes "$<chr 255>" plus two
 *     literal spaces, and a run of 258 becomes "$<chr 255>$<chr 3>".
 *   - Any other character is copied verbatim.
 *
 * Input format:
 *   First line: integer N. Next N lines: text to compress, up to
 *   2000 characters each. Characters are uppercase, lowercase,
 *   digits and spaces.
 *
 * Output format:
 *   One compressed line per input test case. Output may contain
 *   binary bytes (e.g. ETX = chr(3)) as required by the encoding.
 *
 * Complexity:
 *   O(total input length).
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    // Eat the newline left in the buffer by scanf before reading lines.
    int c = getchar();
    (void)c;

    while (N-- > 0) {
        char buf[2100];
        if (!fgets(buf, (int)sizeof(buf), stdin)) break;
        int len = (int)strlen(buf);
        // Strip trailing \n / \r so the run scan doesn't see them.
        while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) {
            buf[--len] = '\0';
        }

        int i = 0;
        while (i < len) {
            char ch = buf[i];
            if (ch == '0' || ch == ' ') {
                int j = i;
                while (j < len && buf[j] == ch) j++;
                int run = j - i;
                if (run >= 3) {
                    char sym = (ch == '0') ? '#' : '$';
                    int remaining = run;
                    while (remaining > 0) {
                        int chunk = remaining > 255 ? 255 : remaining;
                        if (chunk >= 3) {
                            putchar(sym);
                            putchar(chunk);
                        } else {
                            // Trailing leftover of 1 or 2 chars after
                            // a 255-block -- emit literally because
                            // compression wouldn't save anything.
                            for (int k = 0; k < chunk; k++) putchar(ch);
                        }
                        remaining -= chunk;
                    }
                } else {
                    // Short run of 1 or 2 -- never compressed.
                    for (int k = 0; k < run; k++) putchar(ch);
                }
                i = j;
            } else {
                putchar(ch);
                i++;
            }
        }
        putchar('\n');
    }
    return 0;
}

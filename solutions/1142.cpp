/*
 * Beecrowd 1142 - PUM
 *
 * Read an integer N; N is the number of lines to print. Counting the natural
 * numbers 1, 2, 3, ... in groups of four, every fourth value (i.e. every
 * multiple of 4) is replaced by the word "PUM". Each printed line therefore
 * holds three consecutive numbers followed by "PUM", and exactly N such lines
 * are produced.
 *
 * Input : a single integer N (the number of output lines).
 * Output: N lines; line k (1-based) is "a b c PUM" where a = 4(k-1)+1,
 *         b = a+1, c = a+2 -- the multiple of 4 that would close the group is
 *         printed as "PUM". Tokens are single-space separated; a trailing
 *         newline ends every line (Beecrowd flags missing newlines as PE).
 *
 * Approach: no divisibility test is needed -- the fourth token of every line is
 *           always a multiple of 4, hence always "PUM". So simply emit, for
 *           each line, the three numbers that precede that multiple of 4.
 *
 * Complexity: O(N) time (one line per iteration), O(1) extra space.
 */

#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Line k (0-based) covers the integers 4k+1 .. 4k+4; the last of these is a
    // multiple of 4 and is therefore printed as "PUM".
    for (int k = 0; k < n; ++k) {
        int base = 4 * k;
        printf("%d %d %d PUM\n", base + 1, base + 2, base + 3);
    }

    return 0;
}

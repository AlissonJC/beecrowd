/*
 * Beecrowd 3490 — Find the Password!
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Four papers (labelled A, B, C, D) hold the digits of a 4-digit
 *   password in that order. Given the four digits, print the password
 *   as a single 4-character string with leading zeros preserved.
 *
 * Input (multi-case, EOF-terminated):
 *   Each line has four integers A B C D, each in [0, 9].
 *
 * Output (per case):
 *   The four digits concatenated, e.g. "0 0 0 0" -> "0000".
 *
 * Approach:
 *   Read four ints, print with "%d%d%d%d\n". Each digit is a single
 *   character because 0 <= d <= 9, so there are no padding concerns.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <cstdio>

int main() {
    int a, b, c, d;
    while (scanf("%d %d %d %d", &a, &b, &c, &d) == 4) {
        printf("%d%d%d%d\n", a, b, c, d);
    }
    return 0;
}

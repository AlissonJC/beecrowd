/*
 * Beecrowd 1957 — Converting to Hexadecimal
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Read a single positive integer V in base 10 and print its base-16
 *   representation in UPPERCASE letters (A-F, not a-f).
 *
 * Input:
 *   A single integer V with 1 <= V <= 2 * 10^9. That upper bound is
 *   close to (but below) INT_MAX = 2147483647; using unsigned long is
 *   the safe choice and makes the hex format specifier straightforward.
 *
 * Output:
 *   V written in base 16, uppercase, followed by a newline.
 *
 * Approach:
 *   Read V, hand it to printf with the "%lX" specifier (uppercase hex
 *   for unsigned long). Trailing newline is required per the
 *   statement -- "don't forget the end-of-line character".
 *
 * Complexity:
 *   O(log V) digits to print. Constant for the given bound.
 */

#include <cstdio>

int main() {
    unsigned long v;
    scanf("%lu", &v);

    // "%lX" prints unsigned long in uppercase hexadecimal, no "0x" prefix.
    // Beecrowd is strict about format -- lowercase "%lx" would be WA.
    printf("%lX\n", v);

    return 0;
}

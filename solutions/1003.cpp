/*
 * Beecrowd 1003 - Simple Sum
 *
 * Read two integers A and B, compute SOMA = A + B, and print it as
 * "SOMA = <value>" -- all capitals, with a blank space on each side of the '='
 * sign, followed by an end-of-line.
 *
 * Input : two integers A and B.
 * Output: the line "SOMA = " followed by A + B (and a trailing newline; omitting
 *         it causes a Presentation Error on Beecrowd).
 *
 * Approach: read both numbers and print their sum in the exact required format.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    // Output label is the Portuguese "SOMA" per the statement -- do not translate.
    printf("SOMA = %d\n", a + b);
    return 0;
}

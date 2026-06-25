/*
 * Beecrowd 1001 - Extremely Basic
 *
 * Read two integers A and B, compute their sum X = A + B, and print it as
 * "X = <value>" -- uppercase X with a blank space on each side of the '=' sign,
 * followed by an end-of-line.
 *
 * Input : two integers A and B.
 * Output: the line "X = " followed by A + B (and a trailing newline; omitting
 *         it causes a Presentation Error on Beecrowd).
 *
 * Approach: read both numbers and print the sum in the exact required format.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    // Exact format: 'X', spaces around '=', the sum, then a newline.
    printf("X = %d\n", a + b);
    return 0;
}

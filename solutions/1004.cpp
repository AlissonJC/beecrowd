/*
 * Beecrowd 1004 - Simple Product
 *
 * Read two integers A and B, compute their product PROD = A * B, and print it as
 * "PROD = <value>" -- a blank space on each side of the '=' sign -- followed by
 * an end-of-line.
 *
 * Input : two integers A and B.
 * Output: the line "PROD = " followed by A * B (and a trailing newline; omitting
 *         it causes a Presentation Error on Beecrowd).
 *
 * Approach: read both numbers and print their product in the exact format.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    printf("PROD = %d\n", a * b);
    return 0;
}

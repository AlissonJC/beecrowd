/*
 * Beecrowd 1059 - Even Numbers
 *
 * Print every even number between 1 and 100 (inclusive of 100), one per line.
 *
 * Input : none.
 * Output: the even numbers 2, 4, 6, ..., 100, each on its own line (each
 *         followed by a newline).
 *
 * Approach: iterate from 2 to 100 in steps of 2, printing each value. Starting
 *           at 2 and stepping by 2 visits exactly the even numbers, so no
 *           parity test is needed.
 *
 * Complexity: O(50) time, O(1) space.
 */

#include <cstdio>

int main() {
    // Start at the first even number and step by 2 up to and including 100.
    for (int i = 2; i <= 100; i += 2)
        printf("%d\n", i);
    return 0;
}

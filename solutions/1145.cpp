/*
 * Beecrowd 1145 - Logical Sequence 2
 *
 * Read two integers X and Y (X < Y) and print the natural numbers from 1 up to
 * Y, breaking to a new line after every X numbers. The numbers on a line are
 * separated by a single blank space.
 *
 * Input : two integers X and Y, with 1 < X < 20 and X < Y < 100000.
 * Output: the values 1..Y, X per line, single-space separated. When Y is not a
 *         multiple of X the final line simply holds the leftover numbers.
 *
 * Approach: a single counting loop from 1 to Y. A line ends either when the
 *           current count reaches a multiple of X (i % X == 0) or when we reach
 *           the very last value Y; in both situations print a newline instead of
 *           a trailing space. This keeps every line free of trailing spaces,
 *           which Beecrowd may otherwise flag as a Presentation Error.
 *
 *           The input is consumed with a read-until-exhausted loop. The
 *           statement describes a single X Y pair, and for that single pair the
 *           loop runs exactly once; the loop form just makes the program robust
 *           if the input stream carries more than one pair.
 *
 * Complexity: O(Y) time per pair, O(1) extra space. With Y < 100000 the total
 *             work and output are tiny, well within the time limit.
 */
#include <cstdio>

int main() {
    int x, y;

    // Consume every X Y pair present in the input (normally exactly one).
    while (scanf("%d %d", &x, &y) == 2) {
        for (int i = 1; i <= y; ++i) {
            printf("%d", i);

            // Close the line after each block of X numbers, and also after the
            // final value Y (whose block may be shorter than X). Otherwise the
            // numbers within a line are joined by a single space.
            if (i % x == 0 || i == y) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }

    return 0;
}

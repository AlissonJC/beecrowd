/*
 * Beecrowd 1175 - Array change I
 *
 * Read an array of 20 integers and reverse it: swap the first element with the
 * last, the second with the second-to-last, and so on (the 10th with the 11th).
 * Print the resulting array.
 *
 * Input : 20 integers (each may be positive or negative).
 * Output: 20 lines, each "N[i] = Y" where i is the position (0..19) and Y is the
 *         value now stored there. Note the spaces around '=' in the format.
 *
 * Approach: reversing position i means it ends up holding the original element
 *           at index 19 - i. So read all 20 values, then print, for i = 0..19,
 *           the stored value a[19 - i]. This produces the reversal without an
 *           explicit swap loop.
 *
 * Complexity: O(20) time and space - constant.
 */
#include <cstdio>

int main() {
    int a[20];

    // Read the 20 input values in their original order.
    for (int i = 0; i < 20; ++i) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }

    // Position i of the reversed array is the original element a[19 - i].
    for (int i = 0; i < 20; ++i) {
        printf("N[%d] = %d\n", i, a[19 - i]);
    }

    return 0;
}

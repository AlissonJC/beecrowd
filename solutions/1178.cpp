/*
 * Beecrowd 1178 - Array Fill III
 *
 * Read a real number X and place it at position 0 of an array N[100]. Each later
 * position holds half of the value at the previous position, i.e. N[i] =
 * N[i-1] / 2 for i = 1..99. Print every position.
 *
 * Input : one double-precision number (given with four decimal places).
 * Output: 100 lines "N[i] = Y", where i is the position and Y is the stored
 *         value printed with exactly four digits after the decimal point.
 *
 * Approach: keep a single running value starting at X. For each position print
 *           it with %.4f and then halve it for the next position. No array
 *           storage is needed because each value depends only on the previous.
 *           After ~30 halvings the value is far below 0.00005 and therefore
 *           prints as 0.0000, which is the expected behaviour.
 *
 * Complexity: O(100) time, O(1) space.
 */
#include <cstdio>

int main() {
    double value;
    if (scanf("%lf", &value) != 1) return 0;

    // Position 0 holds X; every subsequent position is half of the one before.
    for (int i = 0; i < 100; ++i) {
        printf("N[%d] = %.4f\n", i, value);
        value /= 2.0;  // prepare the value for the next position
    }

    return 0;
}

/*
 * Beecrowd 2950 - The Two Towers
 *
 * The Magnetic Communication Interference (ICM) between the two Palantir
 * spheres is defined as the distance between them divided by the sum of their
 * diameters. Given the distance and the two diameters, compute the ICM.
 *
 * Input : three integers N, X and Y (0 < N < 10000, 0 < X, Y < 100): the
 *         distance between the Palantir and the diameters of Sauron's and
 *         Saruman's Palantir, respectively.
 * Output: the ICM value, N / (X + Y), printed with exactly 2 decimal places.
 *
 * Approach: A single division. Compute it in floating point (cast the
 * numerator to double so integer division does not truncate) and format with
 * two decimals. Both diameters are at least 1, so the divisor X + Y >= 2 and
 * there is no division by zero.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    int n, x, y;
    if (scanf("%d %d %d", &n, &x, &y) != 3)
        return 0;  // malformed input guard; keeps the compiler from warning

    // Cast to double so the ratio keeps its fractional part; %.2f rounds to
    // two decimals to match the judge's expected text exactly (e.g. 18.18).
    double icm = (double)n / (x + y);
    printf("%.2f\n", icm);

    return 0;
}

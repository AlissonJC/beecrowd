/*
 * Beecrowd 1011 - Sphere
 *
 * Given the radius R of a sphere, compute and print its volume using the
 * formula V = (4/3) * pi * R^3 with pi taken as 3.14159.
 *
 * Input : a floating-point value R (the radius).
 * Output: one line "VOLUME = <value>" with spaces around '=' and exactly three
 *         decimal places.
 *
 * Approach: Apply the formula directly. Write the fraction as 4.0/3.0 so it is
 * evaluated in floating point (4/3 with integer literals would truncate to 1),
 * and use the statement's prescribed pi = 3.14159. R^3 can reach ~10^10, which
 * a double represents exactly enough for three-decimal output.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    double r;
    if (scanf("%lf", &r) != 1)
        return 0;  // malformed input guard; also silences the warning

    // 4.0/3.0 keeps the division in floating point; pi is fixed at 3.14159.
    double volume = (4.0 / 3.0) * 3.14159 * r * r * r;

    printf("VOLUME = %.3f\n", volume);
    return 0;
}

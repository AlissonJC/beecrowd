/*
 * Beecrowd 1043 - Triangle
 *
 * Read three floating-point values A, B and C and decide whether they can be
 * the side lengths of a triangle. If they can, print the triangle's perimeter;
 * otherwise interpret A and B as the two parallel bases and C as the height of
 * a trapezium and print its area.
 *
 * Input : three floating point numbers (A, B, C) on one line.
 * Output: either "Perimetro = P" or "Area = S", with exactly one digit after
 *         the decimal point. The labels stay in Portuguese, exactly as the
 *         statement shows them.
 *
 * Approach: A set of three lengths forms a (non-degenerate) triangle iff every
 * side is strictly less than the sum of the other two -- the triangle
 * inequality. The degenerate case A = B + C is NOT a triangle, so the
 * comparison must be strict: sample "6.0 4.0 2.0" has 6 == 4 + 2 and is
 * therefore rejected, falling through to the trapezium branch.
 *   - Perimeter of the triangle: A + B + C.
 *   - Area of a trapezium with parallel bases A, B and height C: (A + B) / 2 * C.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    // Triangle inequality, checked on all three sides with STRICT "<" so that
    // the degenerate collinear case (one side equal to the sum of the others)
    // is correctly treated as "not a triangle".
    if (a < b + c && b < a + c && c < a + b) {
        // Valid triangle: print its perimeter.
        printf("Perimetro = %.1f\n", a + b + c);
    } else {
        // Not a triangle: A and B are the parallel bases, C is the height.
        printf("Area = %.1f\n", (a + b) / 2.0 * c);
    }

    return 0;
}

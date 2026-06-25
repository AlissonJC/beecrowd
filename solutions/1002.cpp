/*
 * Beecrowd 1002 - Area of a Circle
 *
 * Read the radius R (double precision) and compute the circle area
 * A = pi * R^2, using pi = 3.14159 exactly as fixed by the problem. Print
 * "A=<value>" with four digits after the decimal point, then an end-of-line.
 *
 * Input : a floating-point value R.
 * Output: "A=" immediately followed by the area (no spaces around '='),
 *         formatted with four decimals, plus a trailing newline (omitting it
 *         causes a Presentation Error on Beecrowd).
 *
 * Approach: apply the formula with the given constant and print with %.4f.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    double r;
    if (scanf("%lf", &r) != 1) return 0;
    const double PI = 3.14159;          // value fixed by the statement (not M_PI)
    // "A=" has NO spaces around '=' here (unlike problems 1001 / 1003).
    printf("A=%.4f\n", PI * r * r);
    return 0;
}

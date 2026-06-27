/*
 * Beecrowd 3146 - Riddles in the Dark
 *
 * Given the radius R of a circle, return the length of its circumference. The
 * statement fixes the value of pi at 3.14, so the circumference is 2 * 3.14 * R.
 *
 * Input : a single real value R (0 < R <= 10), the circle's radius.
 * Output: a real value with exactly two decimal places, the circumference.
 *
 * Approach: Apply the circumference formula 2 * pi * R. Crucially, use the
 * problem's prescribed pi = 3.14 (not the library M_PI), or the rounded result
 * would differ from the judge's expected output.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    double r;
    if (scanf("%lf", &r) != 1)
        return 0;  // malformed input guard; also silences the warning

    // pi is fixed at 3.14 by the statement; do not substitute a more precise
    // constant, or the two-decimal rounding would not match.
    double circumference = 2.0 * 3.14 * r;
    printf("%.2f\n", circumference);

    return 0;
}

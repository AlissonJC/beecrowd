/*
 * Beecrowd 2754 — Output 8
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Store two double-precision values, 234.345 and 45.698, and print them
 *   nine times under different printf conversions, the two values on each
 *   line separated by " - " (space, dash, space). The conversions exercise
 *   fixed precision, scientific notation and the shortest "%g" form:
 *     1) %f      - fixed, six decimals (the default)
 *     2) %.0f    - fixed, no decimals
 *     3) %.1f    - fixed, one decimal
 *     4) %.2f    - fixed, two decimals
 *     5) %.3f    - fixed, three decimals
 *     6) %e      - scientific notation with lowercase 'e'
 *     7) %E      - scientific notation with uppercase 'E'
 *     8) %g      - shortest of fixed/scientific, lowercase
 *     9) %G      - shortest of fixed/scientific, uppercase
 *
 * Input:
 *   None.
 *
 * Output:
 *   Nine lines, each "<a> - <b>" formatted as listed above.
 *
 * Approach:
 *   Print directly with the matching conversion specifier. Rounding for the
 *   reduced-precision lines follows the stored binary doubles: 234.345 is
 *   held as a hair below 234.345, so %.2f yields 234.34 (not 234.35), and
 *   %.0f yields 234; 45.698 rounds up to 46 at zero decimals and to 45.70
 *   at two. These match the expected output exactly.
 *
 * Complexity:
 *   O(1) — nine formatted prints.
 */

#include <cstdio>

int main() {
    double a = 234.345;
    double b = 45.698;

    printf("%f - %f\n", a, b);      // six decimals (default for %f)
    printf("%.0f - %.0f\n", a, b);  // no decimals
    printf("%.1f - %.1f\n", a, b);  // one decimal
    printf("%.2f - %.2f\n", a, b);  // two decimals
    printf("%.3f - %.3f\n", a, b);  // three decimals
    printf("%e - %e\n", a, b);      // scientific, lowercase 'e'
    printf("%E - %E\n", a, b);      // scientific, uppercase 'E'
    printf("%g - %g\n", a, b);      // shortest representation, lowercase
    printf("%G - %G\n", a, b);      // shortest representation, uppercase

    return 0;
}

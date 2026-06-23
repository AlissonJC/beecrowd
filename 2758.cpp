/*
 * Beecrowd 2758 - Floating Number Input and Output
 *
 * Read two single-precision reals A, B and two double-precision reals C, D, then
 * print them in the layout "A = <a>, B = <b>" / "C = <c>, D = <d>" six times,
 * each time with a different precision: the default (six decimals), then one, two
 * and three decimals, then three decimals in scientific notation (uppercase E),
 * and finally rounded to the whole part.
 *
 * Input : several test files, each two lines: "A B" then "C D"
 *         (-1000.0 <= A,B,C,D <= 1000.0). Read until end of file.
 * Output: twelve formatted lines per test case, exactly as the samples show.
 *
 * Approach: a formatting exercise -- the only real subtlety is that A and B are
 *   float while C and D are double, so A/B carry single-precision rounding (e.g.
 *   2127.9 prints as 2127.899902) while C/D keep full double precision. Store the
 *   variables with the right types and let printf produce each variant: %f,
 *   %.1f, %.2f, %.3f, %.3E, and %.0f (which rounds to the nearest integer).
 *
 * Complexity: O(1) per test case.
 */

#include <cstdio>

int main() {
    float A, B;            // simple (single) precision
    double C, D;           // double precision

    // EOF-terminated: each case is a line "A B" then a line "C D".
    while (scanf("%f %f", &A, &B) == 2 && scanf("%lf %lf", &C, &D) == 2) {
        printf("A = %f, B = %f\n", A, B);              // default: 6 decimals
        printf("C = %lf, D = %lf\n", C, D);
        printf("A = %.1f, B = %.1f\n", A, B);          // 1 decimal
        printf("C = %.1lf, D = %.1lf\n", C, D);
        printf("A = %.2f, B = %.2f\n", A, B);          // 2 decimals
        printf("C = %.2lf, D = %.2lf\n", C, D);
        printf("A = %.3f, B = %.3f\n", A, B);          // 3 decimals
        printf("C = %.3lf, D = %.3lf\n", C, D);
        printf("A = %.3E, B = %.3E\n", A, B);          // 3 decimals, scientific
        printf("C = %.3E, D = %.3E\n", C, D);
        printf("A = %.0f, B = %.0f\n", A, B);          // whole part (rounded)
        printf("C = %.0lf, D = %.0lf\n", C, D);
    }
    return 0;
}

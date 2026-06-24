/*
 * Beecrowd 1963 — The Motion Picture
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Given the old price A and the new price B of a cinema ticket
 *   (0 < A <= B <= 1000, two decimal places each), compute the
 *   percentage by which the ticket price rose and print it followed
 *   immediately by the '%' symbol, with two decimal places.
 *
 * Input:
 *   One line with two floating-point numbers A and B.
 *
 * Output:
 *   One line: "X.XX%" where X.XX = (B - A) / A * 100.
 *
 * Approach:
 *   Straight percentage formula. Use double precision -- the values
 *   stay well within float range. Printf's "%%" emits a literal '%'.
 *
 * Complexity:
 *   O(1).
 */

#include <cstdio>

int main() {
    double A, B;
    scanf("%lf %lf", &A, &B);

    // Percentage rise relative to the old price. With A > 0 there is
    // no division-by-zero concern, and B >= A guarantees a
    // non-negative result so no sign formatting is needed.
    double pct = (B - A) / A * 100.0;
    printf("%.2f%%\n", pct);
    return 0;
}

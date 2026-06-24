/*
 * Beecrowd 2029 — Honey Reservoir
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Julius stores honey in cylindrical containers. Given the honey
 *   volume V (cm^3) and the container's internal diameter D (cm), the
 *   container is a vertical cylinder of cross-section pi * (D/2)^2.
 *   Compute and print:
 *     - ALTURA: the height h (cm) needed to hold volume V, i.e. h = V / A.
 *     - AREA:   the area A (cm^2) of the mouth, i.e. A = pi * (D/2)^2.
 *   Use the problem's pi = 3.14 (exactly; not std::acos(-1) or M_PI).
 *
 * Input (multi-case, EOF-terminated):
 *   Each test case provides V and D as doubles (1.00 <= V <= 10000.00,
 *   1.00 <= D <= 100.00). The problem statement says "a line with two
 *   values", but the sample shows them on separate lines; scanf("%lf")
 *   skips whitespace so both layouts work.
 *
 * Output (per case):
 *   ALTURA = <h with two decimals>
 *   AREA = <A with two decimals>
 *   The Portuguese keywords "ALTURA" and "AREA" are taken verbatim from
 *   the problem (do not translate). Two spaces flank "=": "ALTURA = X".
 *
 * Approach:
 *   For each (V, D) compute A first, then h = V / A, then print using
 *   "%.2f" so the values are formatted exactly as the judge expects.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <cstdio>

int main() {
    double V, D;
    while (scanf("%lf %lf", &V, &D) == 2) {
        // r is the radius -- inside-of-container radius derived from
        // the diameter D. Using 3.14 verbatim per the problem statement;
        // a more accurate pi would change the second-decimal rounding
        // and trigger a WA on a strictly diffed judge.
        double r = D / 2.0;
        double A = 3.14 * r * r;   // area of the cylindrical mouth
        double h = V / A;          // height that fits volume V

        printf("ALTURA = %.2f\n", h);
        printf("AREA = %.2f\n", A);
    }
    return 0;
}

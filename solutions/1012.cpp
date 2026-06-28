/*
 * Beecrowd 1012 - Area
 *
 * Read three floating-point values A, B and C, then compute and print five
 * areas, each on its own labeled line with three decimal places:
 *   - right triangle with base A and height C : A * C / 2
 *   - circle with radius C (pi = 3.14159)     : pi * C^2
 *   - trapezium with bases A and B, height C   : (A + B) * C / 2
 *   - square with side B                       : B^2
 *   - rectangle with sides A and B             : A * B
 *
 * Input : three double values A, B and C.
 * Output: five lines "LABEL: value" (Portuguese labels, a single space after
 *         the colon, value with 3 decimals).
 *
 * Approach: Apply each closed-form area formula. Use 2.0 in the divisions so
 * they stay floating point, and the statement's pi = 3.14159 for the circle.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        return 0;  // malformed input guard; also silences the warning

    double triangle  = (a * c) / 2.0;
    double circle    = 3.14159 * c * c;     // pi fixed at 3.14159 per statement
    double trapezium = ((a + b) * c) / 2.0;
    double square    = b * b;
    double rectangle = a * b;

    // Portuguese labels with a single space after the colon; 3 decimals each.
    printf("TRIANGULO: %.3f\n", triangle);
    printf("CIRCULO: %.3f\n", circle);
    printf("TRAPEZIO: %.3f\n", trapezium);
    printf("QUADRADO: %.3f\n", square);
    printf("RETANGULO: %.3f\n", rectangle);

    return 0;
}

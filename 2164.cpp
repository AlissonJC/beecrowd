/*
 * Beecrowd 2164 — Fast Fibonacci
 *
 * Compute the n-th Fibonacci number using Binet's closed-form formula:
 *
 *     Fib(n) = ( phi^n - psi^n ) / sqrt(5),
 *     where phi = (1 + sqrt(5)) / 2 and psi = (1 - sqrt(5)) / 2.
 *
 * The result is printed with one decimal place.
 *
 * Input:
 *   A natural number n (0 < n <= 50). Read until EOF so multiple values are
 *   handled robustly as well.
 *
 * Output:
 *   Fibonacci(n) computed via Binet's formula, with one decimal place.
 *
 * Approach:
 *   Evaluate Binet's formula directly in double precision. For n <= 50 the
 *   floating-point error stays far below 0.05, so rounding to one decimal
 *   reproduces the exact integer value followed by ".0".
 *
 * Complexity:
 *   O(1) per query (two pow calls).
 */

#include <cstdio>
#include <cmath>

int main() {
    const double sqrt5 = std::sqrt(5.0);
    const double phi   = (1.0 + sqrt5) / 2.0;   // golden ratio
    const double psi   = (1.0 - sqrt5) / 2.0;   // conjugate

    int n;
    while (scanf("%d", &n) == 1) {
        double fib = (std::pow(phi, n) - std::pow(psi, n)) / sqrt5;
        printf("%.1f\n", fib);
    }

    return 0;
}

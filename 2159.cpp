/*
 * Beecrowd 2159 — Approximate Number of Primes
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Schoenfeld and Rosser proved that for every n >= 17 the count of
 *   primes up to n, pi(n), satisfies the two-sided bound
 *        n / ln(n)  <  pi(n)  <  1.25506 * n / ln(n).
 *   Given n, print the lower bound P and the upper bound M of this
 *   inequality, each formatted with one decimal place and separated by
 *   a single space on a single line.
 *
 * Input:
 *   A single integer n with 17 <= n <= 10^9.
 *
 * Output:
 *   "P M" with one decimal place each, followed by a newline.
 *
 * Approach:
 *   Compute base = n / log(n) with std::log (natural log). The lower
 *   bound is base; the upper bound is 1.25506 * base. Print with
 *   "%.1f %.1f\n". Using double precision is plenty -- n fits in 30
 *   bits, log(n) tops out near ln(10^9) ~ 20.7, and the ratio's
 *   one-decimal display is well inside double's accuracy.
 *
 * Complexity:
 *   O(1).
 */

#include <cstdio>
#include <cmath>

int main() {
    long long n;
    scanf("%lld", &n);

    // Natural logarithm (log() in cmath is base-e). The denominator is
    // never zero because n >= 17.
    double base = (double) n / std::log((double) n);
    double P = base;
    double M = 1.25506 * base;

    printf("%.1f %.1f\n", P, M);
    return 0;
}

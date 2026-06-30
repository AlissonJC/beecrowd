/*
 * Beecrowd 1151 - Easy Fibonacci
 *
 * The Fibonacci sequence starts 0 1 1 2 3 5 8 13 21 ...; after the first two
 * terms, each term is the sum of the two preceding ones. Read an integer N and
 * print the first N terms of the sequence.
 *
 * Input : a single integer N, with 0 < N < 46.
 * Output: the first N Fibonacci numbers on one line, separated by single spaces,
 *         with NO space after the last number (a trailing space would be a
 *         Presentation Error on Beecrowd).
 *
 * Approach: iteratively roll two running terms (a, b) starting at (0, 1). On
 *           step i the current term a is printed and the pair advances to the
 *           next Fibonacci pair. A space is emitted BEFORE every term except the
 *           first, which guarantees no trailing space.
 *
 * Type choice: the largest term that can be printed is the 45th, F(44) =
 *           701408733, which fits in 32-bit int; long long is used anyway to
 *           keep the running sum unambiguously safe.
 *
 * Complexity: O(N) time, O(1) space (N <= 45).
 */
#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        // Separator goes before each term except the first -> no trailing space.
        if (i > 0) printf(" ");
        printf("%lld", a);

        // Advance (a, b) to the next consecutive Fibonacci pair.
        long long next = a + b;
        a = b;
        b = next;
    }
    printf("\n");

    return 0;
}

/*
 * Beecrowd 2807 - Iccanobif
 *
 * "Iccanobif" is simply "Fibonacci" spelled backwards, and that is exactly what
 * the sequence is: the first N Fibonacci numbers printed in reverse (descending)
 * order. Read the printed line from left to right and the rule in the statement
 * holds -- every term equals the sum of the two terms that follow it, and the
 * last two terms are always 1. That is just the Fibonacci recurrence viewed
 * back to front.
 *
 * Input : a single integer N (1 <= N <= 40), the number of terms to print.
 * Output: the N terms of the Iccanobif sequence on one line, separated by a
 *         single space, terminated by a newline.
 *
 * Approach: build the first N Fibonacci numbers ascending (F1 = F2 = 1,
 *           Fi = Fi-1 + Fi-2), then emit them from index N down to 1. Building
 *           forward and printing backward yields the descending order shown in
 *           the samples.
 *
 * Complexity: O(N) time, O(N) space -- trivial for N <= 40.
 *
 * Overflow note: F(40) = 102334155 fits in a 32-bit int, but long long is used
 *                so the absence of overflow is obvious at a glance.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // 1-based array to mirror the F1 = F2 = 1 definition from the statement.
    // Setting both base cases unconditionally is safe even when n == 1, since
    // index 2 is a valid slot and is simply never printed in that case.
    long long fib[41];
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print in reverse (descending) order. To avoid a trailing space, emit a
    // separating space before every term except the first one printed.
    for (int i = n; i >= 1; --i) {
        if (i != n) std::cout << ' ';
        std::cout << fib[i];
    }
    std::cout << '\n';

    return 0;
}

/*
 * Beecrowd 1132 - Multiples of 13
 *
 * Read two integers X and Y (given in no particular order) and sum every
 * integer in the closed interval between them that is NOT divisible by 13,
 * counting both endpoints when they qualify.
 *
 * Input : two integers X and Y, possibly with X > Y.
 * Output: a single integer - the sum of all values in [min(X,Y), max(X,Y)]
 *         that are not multiples of 13.
 *
 * Approach: normalize the endpoints with min/max so the range is well defined
 * regardless of input order, then sweep the interval and add each value whose
 * remainder modulo 13 is non-zero. A 64-bit accumulator guards the running sum
 * against overflow. (i % 13 == 0 also correctly flags negative multiples and 0,
 * so the same test works across the whole integer range.)
 *
 * Complexity: O(hi - lo) time, O(1) space.
 */
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long x, y;
    std::cin >> x >> y;

    // Endpoints may arrive in any order - sort them into [lo, hi].
    long long lo = std::min(x, y);
    long long hi = std::max(x, y);

    // Add every value in the inclusive range that is not a multiple of 13.
    long long sum = 0;
    for (long long i = lo; i <= hi; ++i)
        if (i % 13 != 0)
            sum += i;

    std::cout << sum << '\n';

    return 0;
}

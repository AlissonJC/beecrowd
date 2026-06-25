/*
 * Beecrowd 1099 - Sum of Consecutive Odd Numbers II
 *
 * Read an integer N, the number of test cases. Each test case is a line with two
 * integers X and Y. For each case print the sum of all ODD values strictly
 * between X and Y, excluding X and Y themselves.
 *
 * Input : N on the first line, then N lines each containing two integers X, Y.
 *         X and Y may appear in any order (X may be greater than Y).
 * Output: one integer per test case - the requested sum.
 *
 * Approach: normalize the endpoints with min/max so the range is well defined
 * regardless of input order, then walk every integer strictly inside (lo, hi)
 * and accumulate the odd ones. The "II" variant of this problem exists exactly
 * to test that the X > Y case is handled, so the min/max step is the crux.
 *
 * Complexity: O(hi - lo) per test case, O(sum of ranges) overall; O(1) space.
 */
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    while (n--) {
        int x, y;
        std::cin >> x >> y;

        // Normalize: lo is the smaller endpoint, hi the larger - handles X > Y.
        int lo = std::min(x, y);
        int hi = std::max(x, y);

        // Sum odd numbers in the open interval (lo, hi): start at lo+1, stop
        // before hi, so both endpoints are excluded. long long guards the sum.
        long long sum = 0;
        for (int v = lo + 1; v < hi; ++v)
            if (v % 2 != 0)
                sum += v;

        std::cout << sum << '\n';
    }

    return 0;
}

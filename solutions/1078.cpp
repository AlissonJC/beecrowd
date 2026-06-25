/*
 * Beecrowd 1078 - Multiplication Table
 *
 * Read an integer N and print its multiplication table from 1 to 10, each
 * line written in the form "i x N = product".
 *
 * Input : a single integer N (1 < N < 1000).
 * Output: ten lines, "<i> x <N> = <product>" for i from 1 to 10.
 *
 * Approach: a straightforward loop over i = 1..10 printing each product. The
 * count is fixed at ten lines regardless of N.
 *
 * Complexity: O(1) time and space - exactly ten lines.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // Fixed table from 1 to 10. Mind the exact spacing required by the judge:
    // value, space, 'x', space, N, space, '=', space, product.
    for (int i = 1; i <= 10; ++i)
        std::cout << i << " x " << n << " = " << i * n << '\n';

    return 0;
}

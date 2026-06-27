/*
 * Beecrowd 3047 - The age of Mrs. Monica
 *
 * Mrs. Monica has three children of distinct ages, and this year the sum of the
 * three ages equals her own age M. Given M and the ages A and B of two of the
 * children, the third child's age is whatever is left over, C = M - A - B.
 * Print the age of the oldest child, i.e. the largest of A, B and C.
 *
 * Input : three lines with integers M, A and B (40 <= M <= 110, 1 <= A < M,
 *         1 <= B < M, A != B).
 * Output: a single integer, the age of the oldest child.
 *
 * Approach: Recover the unknown age by subtraction, then take the maximum of
 * the three ages.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>
#include <algorithm>

int main() {
    int m, a, b;
    std::cin >> m >> a >> b;

    // The three ages sum to M, so the missing child's age is the remainder.
    int c = m - a - b;

    // Oldest child = largest of the three ages.
    std::cout << std::max({a, b, c}) << "\n";

    return 0;
}

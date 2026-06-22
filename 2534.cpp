/*
 * Beecrowd 2534 — General Exam
 *
 * Citizens are ranked by their exam grade, highest grade first (rank 1 is the
 * best). For each query position p, report the grade of the citizen at that
 * rank.
 *
 * Input:
 *   Several test cases until EOF. Each begins with N and Q (1 <= N, Q <= 100),
 *   then N grades n_i (0 <= n_i <= 30000), then Q positions p_i.
 *
 * Output:
 *   For each query, the grade of the citizen ranked at position p_i.
 *
 * Approach:
 *   Sort the grades in non-increasing order; the answer to a query p is the
 *   grade at 0-based index p - 1.
 *
 * Complexity:
 *   O(N log N + Q) per test case.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    while (std::cin >> n >> q) {
        std::vector<int> grades(n);
        for (int i = 0; i < n; ++i) std::cin >> grades[i];

        // Rank 1 is the highest grade, so sort in non-increasing order.
        std::sort(grades.begin(), grades.end(), std::greater<int>());

        while (q-- > 0) {
            int p;
            std::cin >> p;
            std::cout << grades[p - 1] << '\n';   // p is 1-based
        }
    }

    return 0;
}

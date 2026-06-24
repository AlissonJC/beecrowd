/*
 * Beecrowd 2540 — Leader's Impeachment
 *
 * N team members vote on impeaching the leader: vote 1 is for the impeachment,
 * 0 is against. The leader loses his position if the number of "for" votes is
 * at least two thirds of N; otherwise the accusation is filed.
 *
 * Input:
 *   Several test cases until EOF. Each has N (1 <= N <= 10^5) followed by a line
 *   of N votes v_i (0 or 1).
 *
 * Output:
 *   "impeachment" if for-votes >= 2N/3, otherwise "acusacao arquivada".
 *
 * Approach:
 *   Count the "for" votes and test the threshold with integer arithmetic:
 *   ones >= (2/3) * N is equivalent to 3 * ones >= 2 * N, avoiding any floating
 *   point and its rounding pitfalls at the boundary.
 *
 * Complexity:
 *   O(N) per test case.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n) {
        int ones = 0;
        for (int i = 0; i < n; ++i) {
            int v;
            std::cin >> v;
            ones += v;          // votes are 0/1, so summing counts the "for" votes
        }

        // ones >= (2/3) * n  <=>  3*ones >= 2*n  (exact integer comparison)
        if (3 * ones >= 2 * n)
            std::cout << "impeachment\n";
        else
            std::cout << "acusacao arquivada\n";
    }

    return 0;
}

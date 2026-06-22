/*
 * Beecrowd 2547 — Roller Coaster
 *
 * Count how many guests are allowed to ride: a guest may ride only if their
 * height lies within the inclusive range [Amin, Amax].
 *
 * Input:
 *   Several test cases until EOF. Each begins with N, Amin and Amax
 *   (1 <= N <= 100, 50 <= Amin <= Amax <= 250), then N guest heights A_i
 *   (50 <= A_i <= 250).
 *
 * Output:
 *   For each test case, the number of guests allowed to ride.
 *
 * Approach:
 *   Count the heights that fall within [Amin, Amax].
 *
 * Complexity:
 *   O(N) per test case.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, lo, hi;
    while (std::cin >> n >> lo >> hi) {
        int allowed = 0;
        for (int i = 0; i < n; ++i) {
            int h;
            std::cin >> h;
            if (h >= lo && h <= hi) ++allowed;   // inclusive range
        }
        std::cout << allowed << '\n';
    }

    return 0;
}

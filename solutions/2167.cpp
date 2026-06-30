/*
 * Beecrowd 2167 - Engine Failure
 *
 * An engine test records N speed measures (RPM) taken at fixed intervals.
 * A "speed fall" is a measure that is strictly lower than the one before it.
 * Report the 1-based index of the FIRST measure where a speed fall happens,
 * or 0 if the readings never drop.
 *
 * Input : line 1 has N (1 < N <= 100); line 2 has N integers R_1..R_N
 *         (0 <= R_i <= 10000).
 * Output: the index i (1-based) of the first measure with R_i < R_{i-1},
 *         or 0 if no such measure exists.
 *
 * Approach   : scan left to right keeping the previous reading; the first time
 *              the current reading is strictly smaller, print its index and stop.
 *              "Strictly smaller" matters: equal consecutive values (sample 2's
 *              199 199) are NOT a fall, so the answer there is 4, not 3.
 * Complexity : O(N) time, O(1) space.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int prev;
    std::cin >> prev;            // first reading: index 1, has nothing before it

    int answer = 0;              // 0 means "no speed fall found"
    for (int i = 2; i <= n; ++i) {
        int cur;
        std::cin >> cur;
        // Strict drop versus the previous reading is the first speed fall.
        if (answer == 0 && cur < prev) {
            answer = i;
            // Keep reading the rest of the line so input is fully consumed,
            // but the answer is already locked to this first occurrence.
        }
        prev = cur;
    }

    std::cout << answer << '\n';
    return 0;
}

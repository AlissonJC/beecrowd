/*
 * Beecrowd 2551 — New Record
 *
 * Flávio runs once per day; training i has duration T_i and distance D_i, giving
 * an average speed D_i / T_i. He beats his record on a day whose average speed
 * is strictly greater than every previous day's speed. Day 1 is always a record.
 * List the days (1-based, ascending) on which he set a new record.
 *
 * Input:
 *   Several test cases until EOF. Each begins with N (1 <= N <= 30), then N
 *   lines with T_i and D_i (1 <= T_i, D_i <= 100).
 *
 * Output:
 *   For each test case, the record-setting days, one per line, in ascending
 *   order (day 1 is always printed).
 *
 * Approach:
 *   Track the best speed seen as a fraction (bestD / bestT) and compare via
 *   cross multiplication (D_i * bestT > bestD * T_i) to avoid floating-point
 *   error. Process the days in order and print each new record immediately.
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
        long long bestD = -1, bestT = 1;   // a speed below any real training

        for (int day = 1; day <= n; ++day) {
            long long t, d;
            std::cin >> t >> d;

            // speed_i > best  <=>  d/t > bestD/bestT  <=>  d*bestT > bestD*t
            // (all denominators are positive, so cross multiplication is safe).
            if (d * bestT > bestD * t) {
                std::cout << day << '\n';
                bestD = d;
                bestT = t;
            }
        }
    }

    return 0;
}

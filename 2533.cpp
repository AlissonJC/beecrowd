/*
 * Beecrowd 2533 — Internship
 *
 * Compute the Academic Performance Index (API) from grades N_i and workloads
 * C_i over M subjects:
 *
 *     API = ( sum_i N_i * C_i ) / ( ( sum_i C_i ) * 100 )
 *
 * printed with exactly four decimal places.
 *
 * Input:
 *   Several test cases until EOF. Each begins with M (1 <= M <= 40), then M
 *   lines with two integers N_i and C_i (0 <= N_i <= 100, 30 <= C_i <= 120).
 *
 * Output:
 *   For each test case, the API rounded to four decimal places.
 *
 * Approach:
 *   Accumulate the weighted grade sum and the total workload as integers, then
 *   divide as a double. The denominator is always positive (C_i >= 30).
 *
 * Complexity:
 *   O(M) per test case.
 */

#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(4);

    int m;
    while (std::cin >> m) {
        long long weighted = 0;   // sum of N_i * C_i
        long long load = 0;       // sum of C_i

        for (int i = 0; i < m; ++i) {
            long long n, c;
            std::cin >> n >> c;
            weighted += n * c;
            load += c;
        }

        double api = static_cast<double>(weighted) / (load * 100.0);
        std::cout << api << '\n';
    }

    return 0;
}

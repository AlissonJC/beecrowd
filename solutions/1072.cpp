/*
 * Beecrowd 1072 - Interval 2
 *
 * Read an integer N, then read N integers X. Count how many of those values
 * lie inside the closed interval [10, 20] and how many fall outside it, and
 * print the two totals.
 *
 * Input : first line N (N < 10000); then N integers X (-10^7 < X < 10^7).
 * Output: "<count> in"  - number of values inside [10, 20];
 *         "<count> out" - number of values outside it.
 *
 * Approach: a single linear pass over the N values, incrementing one of two
 * counters depending on whether 10 <= X <= 20. The interval is closed, so the
 * endpoints 10 and 20 are themselves counted as "in".
 *
 * Complexity: O(N) time, O(1) space.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int inside = 0, outside = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        // Closed interval: the boundary values 10 and 20 count as "in".
        if (x >= 10 && x <= 20) ++inside;
        else                    ++outside;
    }

    std::cout << inside  << " in\n";
    std::cout << outside << " out\n";

    return 0;
}

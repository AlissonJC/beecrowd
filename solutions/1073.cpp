/*
 * Beecrowd 1073 - Even Square
 *
 * Read an integer N and print, for every even number i in the range 1..N
 * (including N when N is even), the line "i^2 = <square>", i.e. the value
 * followed by its square.
 *
 * Input : a single integer N (5 < N < 2000).
 * Output: one line per even i from 2 to N: "<i>^2 = <i squared>".
 *
 * Approach: iterate i = 2, 4, 6, ... up to N and print each square. Plain
 * integer arithmetic is used on purpose: the statement's "1e+006" warning
 * only affects languages that default to floating-point/scientific output,
 * which integer printing here avoids. The largest square, 1998^2 = 3992004,
 * fits comfortably in a 32-bit int.
 *
 * Complexity: O(N) time, O(1) space.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // Step through even numbers only; print each value and its square.
    for (int i = 2; i <= n; i += 2)
        std::cout << i << "^2 = " << i * i << '\n';

    return 0;
}

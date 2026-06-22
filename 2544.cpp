/*
 * Beecrowd 2544 — Kage Bunshin no Jutsu
 *
 * Each use of the Shadow Clone technique doubles the number of ninjas, starting
 * from a single (original) ninja: after k uses there are 2^k ninjas. Given the
 * total number of ninjas N (a power of two), report how many times the technique
 * was used, i.e. log2(N).
 *
 * Input:
 *   Several test cases until EOF, each a number N (1 <= N <= 10^6), guaranteed
 *   to be a power of two.
 *
 * Output:
 *   For each N, the number of uses (log2(N)).
 *
 * Approach:
 *   Halve N until it reaches 1, counting the steps. Since N is a power of two,
 *   this count is exactly log2(N).
 *
 * Complexity:
 *   O(log N) per test case.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    while (std::cin >> n) {
        int uses = 0;
        while (n > 1) {          // N is a power of two, so this terminates at 1
            n /= 2;
            ++uses;
        }
        std::cout << uses << '\n';
    }

    return 0;
}

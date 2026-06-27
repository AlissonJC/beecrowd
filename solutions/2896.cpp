/*
 * Beecrowd 2896 - Enjoy the Offer
 *
 * A supermarket promotion lets a customer trade every set of K empty bottles
 * for one full bottle the day after buying. A customer buys N bottles on the
 * first day; on the second day he brings back the N empties and exchanges as
 * many full sets of K as possible. Report how many bottles he then has.
 *
 * Reading the samples pins down the exact accounting: the customer ends the
 * second day holding floor(N / K) full bottles received from the exchange plus
 * the N mod K empties that could not form a complete set of K. For example,
 * N = 4000, K = 7 gives 571 full + 3 leftover = 574, matching the sample. This
 * is a single exchange pass (he does not re-drink and re-exchange), which also
 * keeps K = 1 well defined instead of looping forever.
 *
 * Input : first line has T (1 <= T <= 10^4), the number of test cases. Each of
 *         the next T lines has two integers N and K (1 <= K, N <= 10^4): the
 *         bottles bought and the empties needed to earn a full one.
 * Output: for each test case, print floor(N / K) + (N mod K).
 *
 * Approach: One integer division and one modulo per test case.
 *
 * Complexity: O(T) time, O(1) space.
 */

#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        // Full bottles gained from the exchange plus the empties left over
        // that did not complete another set of K.
        std::cout << (n / k + n % k) << "\n";
    }

    return 0;
}

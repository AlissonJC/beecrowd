/*
 * Beecrowd 2542 — Iu-Di-Oh!
 *
 * Two players, Marcos and Leonardo, each pick one card from their deck; every
 * card holds N attribute values. A single attribute A is chosen, and whoever's
 * picked card has the larger value of attribute A wins (equal values tie).
 *
 * Input:
 *   Several test cases until EOF. Each: N (attributes per card); then M and L
 *   (deck sizes); then M lines of N integers (Marcos' cards) and L lines of N
 *   integers (Leonardo's cards); then C_M and C_L (1-based chosen cards); then
 *   A (1-based chosen attribute). Values: 1 <= N,M,L <= 100, 1 <= a_ij <= 10^9.
 *
 * Output:
 *   "Marcos", "Leonardo", or "Empate".
 *
 * Approach:
 *   Read both decks, then compare Marcos' card C_M attribute A against
 *   Leonardo's card C_L attribute A.
 *
 * Complexity:
 *   O(N * (M + L)) per test case (dominated by reading the decks).
 */

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n) {
        int m, l;
        std::cin >> m >> l;

        std::vector<std::vector<long long>> marcos(m, std::vector<long long>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                std::cin >> marcos[i][j];

        std::vector<std::vector<long long>> leonardo(l, std::vector<long long>(n));
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < n; ++j)
                std::cin >> leonardo[i][j];

        int cm, cl, a;
        std::cin >> cm >> cl >> a;

        // Convert the 1-based card and attribute indices to 0-based.
        long long mv = marcos[cm - 1][a - 1];
        long long lv = leonardo[cl - 1][a - 1];

        if (mv > lv)      std::cout << "Marcos\n";
        else if (lv > mv) std::cout << "Leonardo\n";
        else              std::cout << "Empate\n";
    }

    return 0;
}

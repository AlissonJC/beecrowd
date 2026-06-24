/*
 * Beecrowd 2310 — Volleyball
 *
 * A coach records, per player, the number of service, block and attack
 * attempts and how many of each were successful. Report the whole team's
 * success percentage for each of the three categories, with two decimals.
 *
 * Input:
 *   First line: N players (1 <= N <= 100). For each player: a line with the
 *   name, then a line with attempts S B A (0 <= S,B,A <= 10000) and a line with
 *   the successful counts S1 B1 A1 (0 <= S1 <= S, 0 <= B1 <= B, 0 <= A1 <= A).
 *
 * Output:
 *   Pontos de Saque: <pct> %.
 *   Pontos de Bloqueio: <pct> %.
 *   Pontos de Ataque: <pct> %.
 *   where each pct = 100 * (team successes) / (team attempts) for the category.
 *
 * Approach:
 *   Accumulate attempts and successes across all players per category, then
 *   print successes / attempts * 100 with two decimal places.
 *
 * Complexity:
 *   O(N) time, O(1) space.
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    long long totS = 0, totB = 0, totA = 0;   // attempts per category
    long long sucS = 0, sucB = 0, sucA = 0;   // successes per category

    std::string name;
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, name);         // name read via getline (unused)

        long long s, b, a, s1, b1, a1;
        std::cin >> s >> b >> a >> s1 >> b1 >> a1;
        // Skip to the next line so the following getline lands on the name.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        totS += s;  totB += b;  totA += a;
        sucS += s1; sucB += b1; sucA += a1;
    }

    // Guard against division by zero if a category had no attempts at all.
    auto pct = [](long long suc, long long tot) {
        return tot > 0 ? 100.0 * suc / tot : 0.0;
    };

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Pontos de Saque: "    << pct(sucS, totS) << " %.\n";
    std::cout << "Pontos de Bloqueio: " << pct(sucB, totB) << " %.\n";
    std::cout << "Pontos de Ataque: "   << pct(sucA, totA) << " %.\n";

    return 0;
}

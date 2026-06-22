/*
 * Beecrowd 2031 — Rock, Paper, Airstrike
 *
 * Two players each pick one of three signs:
 *   "ataque" (Airstrike), "pedra" (Rock), "papel" (Paper).
 * Unlike ordinary rock-paper-scissors, the winning relation is a strict
 * total order rather than a cycle:
 *   - Airstrike beats Rock      (ataque > pedra)
 *   - Rock beats Paper          (pedra  > papel)
 *   - Airstrike beats Paper     (ataque > papel)
 * hence Airstrike > Rock > Paper. When both players pick the same sign the
 * result is a special case:
 *   - Paper vs Paper          -> both win      ("Ambos venceram")
 *   - Rock vs Rock            -> no winner      ("Sem ganhador")
 *   - Airstrike vs Airstrike  -> mutual loss    ("Aniquilacao mutua")
 *
 * Input:
 *   First line: N (1 <= N <= 1000) test cases. Each case is two lines: the
 *   sign chosen by Player 1, then the sign chosen by Player 2.
 *
 * Output:
 *   One line per case (Portuguese, verbatim):
 *     "Jogador 1 venceu", "Jogador 2 venceu", "Ambos venceram",
 *     "Sem ganhador", or "Aniquilacao mutua".
 *
 * Approach:
 *   Map each sign to a strength (Airstrike=3, Rock=2, Paper=1). For different
 *   signs the higher strength wins. For equal signs, choose the dedicated
 *   message based on the sign itself.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <iostream>
#include <string>

// Strength of a sign: when the two signs differ, the higher one wins.
int strength(const std::string& s) {
    if (s == "ataque") return 3;  // Airstrike — strongest
    if (s == "pedra")  return 2;  // Rock
    return 1;                     // "papel" (Paper) — weakest
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string a, b;
    while (n-- > 0) {
        std::cin >> a >> b;   // Player 1's sign, then Player 2's sign

        if (a != b) {
            // Different signs: the stronger sign decides who wins.
            std::cout << (strength(a) > strength(b) ? "Jogador 1 venceu"
                                                    : "Jogador 2 venceu") << '\n';
        } else if (a == "papel") {
            std::cout << "Ambos venceram\n";     // Paper vs Paper: both win
        } else if (a == "pedra") {
            std::cout << "Sem ganhador\n";       // Rock vs Rock: nobody wins
        } else {
            std::cout << "Aniquilacao mutua\n";  // Airstrike vs Airstrike
        }
    }

    return 0;
}

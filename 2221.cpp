/*
 * Beecrowd 2221 — Pomekons Battle
 *
 * Two masters, Dabriel and Guarte, each field a Pomekon. A Pomekon's value is
 *     Value = (Attack + Defense) / 2 + Bonus,
 * where the Bonus counts only when the Pomekon's level is even. The master with
 * the larger value wins; equal values are a tie ("Empate").
 *
 * Input:
 *   First line: T instances. Each instance has a line with the bonus B
 *   (0 <= B <= 100), then two lines each with Ai Di Li (1 <= Ai, Di <= 100,
 *   1 <= Li <= 50) — the first line is Dabriel's Pomekon, the second Guarte's.
 *
 * Output:
 *   For each instance, the winner's name ("Dabriel" or "Guarte"), or "Empate".
 *
 * Approach:
 *   Since (A + D) / 2 may be a half-integer, compare twice the values to keep
 *   the arithmetic integral: value2 = (A + D) + (level even ? 2*B : 0).
 *
 * Complexity:
 *   O(1) per instance.
 */

#include <iostream>

// Twice the Pomekon's value, kept integral. The (doubled) bonus applies only
// when the level is even.
int value2(int a, int d, int level, int bonus) {
    return a + d + (level % 2 == 0 ? 2 * bonus : 0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) return 0;

    while (t-- > 0) {
        int b, ad, dd, ld, ag, dg, lg;
        std::cin >> b;
        std::cin >> ad >> dd >> ld;   // Dabriel: attack, defense, level
        std::cin >> ag >> dg >> lg;   // Guarte:  attack, defense, level

        int vd = value2(ad, dd, ld, b);
        int vg = value2(ag, dg, lg, b);

        if (vd > vg)      std::cout << "Dabriel\n";
        else if (vg > vd) std::cout << "Guarte\n";
        else              std::cout << "Empate\n";
    }

    return 0;
}

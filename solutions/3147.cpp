/*
 * Beecrowd 3147 - The Battle of the Five Armies
 *
 * The good side gathers humans, elves and dwarves; the evil side gathers orcs
 * and wargs. Decide who wins by comparing total army sizes, with two extra
 * rules in the good side's favor:
 *   - If the good armies would lose or draw, Gandalf's plan B summons the
 *     eagles, adding them to the good side.
 *   - If, even with the eagles, the two sides tie, Bilbo uses Sting to destroy
 *     one last orc or warg, tipping the tie to the good side.
 *
 * Both rules only ever help the good side, so the whole decision reduces to a
 * single test: the good side wins exactly when humans + elves + dwarves +
 * eagles is greater than OR EQUAL to orcs + wargs (equality is the eagle-aided
 * tie that Sting breaks).
 *
 * Input : six integers H, E, A, O, W, X -- humans, elves, dwarves, orcs, wargs
 *         and eagles, respectively.
 * Output: "Middle-earth is safe." if the good side wins, otherwise
 *         "Sauron has returned.".
 *
 * Approach: Sum each side (eagles always counted on the good side, since they
 * only matter when good is behind) and compare with >=.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    // Use 64-bit since the statement gives no explicit upper bound on the
    // army sizes, and four of them are summed together.
    long long h, e, a, o, w, x;
    std::cin >> h >> e >> a >> o >> w >> x;

    long long good = h + e + a + x;  // eagles join whenever they could help
    long long evil = o + w;

    // good >= evil covers an outright win, an eagle-aided win, and the
    // eagle-aided tie that Bilbo's Sting turns into a win.
    if (good >= evil)
        std::cout << "Middle-earth is safe.\n";
    else
        std::cout << "Sauron has returned.\n";

    return 0;
}

/*
 * Beecrowd 3037 — Playing Darts by Distance
 *
 * John and Mary play a darts variant where each player throws 3 darts and
 * chooses how far from the target to stand. A throw that would normally be
 * worth X points scores X*D instead, where D is the distance between the
 * shooter and the target. The player with the larger total over the 3
 * throws wins the game.
 *
 * Input:
 *   N — number of test cases. Each test case has 6 lines, each with two
 *   numbers X (score) and D (distance) describing one throw: the first 3
 *   lines are John's throws, the next 3 are Mary's.
 *
 * Output:
 *   For each test case, one line with the winner: "JOAO" or "MARIA"
 *   (uppercase ASCII exactly as the sample shows — no accent on JOAO).
 *
 * Approach:
 *   Pure simulation — accumulate X*D over each player's 3 throws and
 *   compare the totals. Values are read as double: the samples only show
 *   integers (which double represents exactly, so the comparison stays
 *   exact), and this also survives fractional input should the hidden data
 *   contain any. The statement never defines a tie, so totals are assumed
 *   to always differ; the tie path falls through to MARIA.
 *
 * Complexity:
 *   O(1) per test case, O(N) overall.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    while (n--) {
        // First 3 lines belong to John, the next 3 to Mary.
        double john = 0.0, mary = 0.0;
        for (int i = 0; i < 6; ++i) {
            double x, d;
            std::cin >> x >> d;
            if (i < 3)
                john += x * d;  // throw is worth score times distance
            else
                mary += x * d;
        }

        // Winner strings are printed verbatim from the Output Sample.
        std::cout << (john > mary ? "JOAO" : "MARIA") << '\n';
    }

    return 0;
}

/*
 * Beecrowd 3170 - Christmas Balls
 *
 * Amelia wants no more than half of her tree's branches to hold balls: a tree
 * with G branches needs G / 2 balls, rounded down when G is odd. Given how many
 * balls B she already owns and the number of branches G of her new tree, tell
 * how many more balls she must buy.
 *
 * Input : two lines with integers B and G (1 < B < 1000, 100 < G < 1000): the
 *         balls Amelia already has and the branches of the new tree.
 * Output: if B is enough (B >= G / 2), print "Amelia tem todas bolinhas!".
 *         Otherwise print "Faltam X bolinha(s)", where X = G / 2 - B is how
 *         many balls she still needs to buy.
 *
 * Approach: Compute the requirement G / 2 with integer division (which floors
 * for odd G, exactly as required) and compare with B.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int b, g;
    std::cin >> b >> g;

    int needed = g / 2;  // integer division floors odd G, as the statement asks

    // Output strings are verbatim Portuguese from the sample, including the
    // literal "(s)" suffix and "Amelia" without an accent.
    if (b >= needed)
        std::cout << "Amelia tem todas bolinhas!\n";
    else
        std::cout << "Faltam " << (needed - b) << " bolinha(s)\n";

    return 0;
}

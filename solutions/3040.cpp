/*
 * Beecrowd 3040 - The Christmas Tree
 *
 * Roberto only accepts a Christmas tree that satisfies every requirement at
 * once: its height must be between 200 and 300 centimeters (inclusive), its
 * trunk diameter must be 50 centimeters or more, and it must have at least 150
 * branches. For each candidate tree, decide whether he can choose it.
 *
 * Input : first line has N (0 < N <= 10000), the number of trees. Each of the
 *         next N lines has three integers h, d, g (0 < h, d, g <= 5000): the
 *         height in cm, the trunk diameter in cm, and the number of branches.
 * Output: for each tree print "Sim" if Roberto can choose it, otherwise "Nao".
 *
 * Approach: A direct conjunction of the three acceptance conditions per tree.
 * Note height has both a lower and an upper bound (200..300), while diameter
 * and branch count have only lower bounds.
 *
 * Complexity: O(N) time, O(1) space.
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int h, d, g;
        std::cin >> h >> d >> g;

        // All three must hold: height within [200, 300], diameter >= 50,
        // and branches >= 150. Output strings are Portuguese per the statement
        // ("Sim"/"Nao", no accent) so they match the judge byte for byte.
        if (h >= 200 && h <= 300 && d >= 50 && g >= 150)
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
    }

    return 0;
}

/*
 * Beecrowd 1035 - Selection Test 1
 *
 * Read four integers A, B, C and D. Accept the values when ALL of the following
 * hold: B > C, D > A, C + D > A + B, C and D are both positive, and A is even.
 * Print the corresponding Portuguese message.
 *
 * Input : four integers A, B, C and D.
 * Output: "Valores aceitos" if every condition holds, otherwise
 *         "Valores nao aceitos" (no accent, exactly as in the sample).
 *
 * Approach: Evaluate the conjunction of the five conditions directly.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    // All five conditions must hold simultaneously. (a % 2 == 0 tests parity;
    // it is correct for negative even values too, e.g. -4 % 2 == 0.)
    bool accepted = b > c && d > a && (c + d) > (a + b) &&
                    c > 0 && d > 0 && a % 2 == 0;

    // Output strings are Portuguese per the statement; use the accent-free form
    // shown in the Output Sample ("nao", not "não").
    std::cout << (accepted ? "Valores aceitos" : "Valores nao aceitos") << "\n";

    return 0;
}

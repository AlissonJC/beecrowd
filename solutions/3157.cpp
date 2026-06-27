/*
 * Beecrowd 3157 - Long Live Science!
 *
 * Oronob's bot spreads opinions against science. Whatever opinion text it
 * produces, the correct reply -- the "truth" -- is always the same sentence.
 * The three sample inputs differ completely yet all map to one fixed output,
 * so the opinion text is irrelevant and can be ignored entirely.
 *
 * Input : a text S with alphanumeric characters and possible spaces
 *         (0 < |S| <= 280). It does not affect the answer.
 * Output: the fixed line "Nao se refuta ciencia com opiniao".
 *
 * Approach: Print the constant answer. The output string is kept verbatim in
 * Portuguese without accents, exactly as the judge expects.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    // The reply never depends on the input opinion, so just emit the truth.
    std::cout << "Nao se refuta ciencia com opiniao\n";
    return 0;
}

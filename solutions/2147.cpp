/*
 * Beecrowd 2147 - Galopeira ("The Typing Challenge")
 *
 * Two typists race to type a word. Pressing a key takes exactly 1/100 second.
 * Given the typed word, report how much time, in seconds, was spent typing it.
 *
 * Reading the samples settles the rule (the prose is noise):
 *   "galopeira"               ->  9 letters -> 0.09
 *   "galopeeeeeeeeeeeeeeeeira" -> 25 letters -> 0.25
 *   "galopeeira"              -> 10 letters -> 0.10
 * If consecutive duplicates collapsed, "galopeeira" would cost the same as
 * "galopeira" (0.09); instead it costs 0.10. So EVERY letter is one keystroke,
 * and the time is simply (number of letters) * 1/100 second.
 *
 * Input : C, the number of test cases; then C words, one per line.
 *         Each word has between 9 and 10000 letters.
 * Output: for each word, the time in seconds with exactly two decimal digits.
 *
 * Approach   : count the letters in the word and divide by 100. The repeated-key
 *              story does not affect the count, so no special handling is needed.
 * Complexity : O(L) per case to read the word (L = its length); O(1) extra space.
 */

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c;                       // number of test cases
    std::cin >> c;

    std::cout << std::fixed << std::setprecision(2);

    std::string word;
    while (c-- > 0) {
        std::cin >> word;        // each case is a single whitespace-delimited word
        // Each character is one keystroke at 1/100 s, so total time = length / 100.
        std::cout << word.size() / 100.0 << '\n';
    }

    return 0;
}

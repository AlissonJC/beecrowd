/*
 * Beecrowd 1113 - Ascending and Descending
 *
 * Read an undetermined number of pairs of integers X and Y. For each pair,
 * report whether the two numbers are in ascending or descending order. Reading
 * stops at the first pair where X equals Y, and that terminating pair produces
 * no output.
 *
 * Input : several lines, each with two integers X and Y. The sequence ends on
 *         the line where X == Y.
 * Output: for each pair before termination, "Crescente" when X < Y, otherwise
 *         "Decrescente".
 *
 * Approach: a sentinel-terminated read loop. Keep reading pairs while the stream
 * is good AND X != Y; the moment X == Y the loop stops without printing. Since
 * the terminating pair is equal, every printed pair is strictly ordered, so a
 * single comparison X < Y decides ascending vs descending.
 *
 * Complexity: O(1) per pair, O(number of pairs) overall; O(1) space.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    // Sentinel: stop as soon as a pair has X == Y (that pair is not printed).
    while (std::cin >> x >> y && x != y)
        // Portuguese output strings per the statement - do not translate.
        std::cout << (x < y ? "Crescente" : "Decrescente") << '\n';

    return 0;
}

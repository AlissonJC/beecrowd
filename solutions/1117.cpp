/*
 * Beecrowd 1117 - Score Validation
 *
 * Read student scores and compute the average of the first TWO valid ones. A
 * score is valid only when it lies in the closed interval [0, 10]; each score is
 * validated on its own. Every time an invalid score is read, a warning is
 * printed. Once two valid scores have been gathered, print their average.
 *
 * Input : a stream of floating-point numbers (may be negative or > 10). Reading
 *         ends as soon as two valid scores have been accepted.
 * Output: "nota invalida" for each invalid score, in the order they appear, then
 *         "media = <avg>" with two decimal places after the second valid score.
 *
 * Approach: loop reading doubles, keeping a running sum and a count of valid
 * scores. A value in [0, 10] is accepted (added to the sum); anything else
 * triggers the "nota invalida" message. Stop the moment the count hits 2, then
 * print sum / 2 formatted with two decimals. Only valid scores feed the sum.
 *
 * Complexity: O(1) per number read, O(k) for k numbers until two are valid;
 * O(1) space.
 */
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double score;
    double sum = 0.0;   // running total of the valid scores only
    int valid = 0;      // how many valid scores accepted so far

    // Read until two valid scores are in hand (or input is exhausted).
    while (valid < 2 && std::cin >> score) {
        if (score >= 0.0 && score <= 10.0) {   // closed interval [0, 10]
            sum += score;
            ++valid;
        } else {
            // Portuguese message per the statement - do not translate.
            std::cout << "nota invalida\n";
        }
    }

    // Average of the two accepted scores, two decimal places.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "media = " << sum / 2.0 << '\n';

    return 0;
}

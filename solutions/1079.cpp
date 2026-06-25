/*
 * Beecrowd 1079 - Weighted Averages
 *
 * Read N test cases; each case is three floating-point numbers a, b, c (each
 * given with one decimal digit). Print the weighted average of the three,
 * where a has weight 2, b has weight 3 and c has weight 5.
 *
 * The weighted average is (2a + 3b + 5c) / (2 + 3 + 5) = (2a + 3b + 5c) / 10.
 *
 * Input : first line N; then N lines, each with three floats a b c.
 * Output: for each case, the weighted average rounded to one decimal place.
 *
 * Approach: read each triple, apply the fixed weights, divide by the total
 * weight 10, and print with exactly one digit after the decimal point. The
 * judge compares text, so the format is fixed-point (%.1f), not free-form.
 *
 * Complexity: O(N) time, O(1) space.
 */
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // One digit after the decimal point, fixed-point, for every line.
    std::cout << std::fixed << std::setprecision(1);

    while (n--) {
        double a, b, c;
        std::cin >> a >> b >> c;

        // Weights 2, 3, 5 add up to 10, so divide the weighted sum by 10.
        double average = (a * 2 + b * 3 + c * 5) / 10.0;
        std::cout << average << '\n';
    }

    return 0;
}

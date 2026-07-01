/*
 * Beecrowd 2630 — Greyscale
 *
 * Convert a single RGB pixel to a grey value P using one of four methods:
 *   - "eye":  P = 0.30*R + 0.59*G + 0.11*B  (weighted for human perception)
 *   - "mean": arithmetic mean of the components, (R + G + B) / 3
 *   - "max":  the largest of the three components
 *   - "min":  the smallest of the three components
 * The decimal part of the result is discarded (truncated toward zero).
 *
 * Input:
 *   T test cases (1 <= T <= 100). For each case: one line with the method name,
 *   then one line with three integers R, G, B (0 <= R, G, B <= 255).
 *
 * Output:
 *   For each test case, the line "Caso #t: P" (t is 1-based), each followed by a
 *   line break.
 *
 * Approach:
 *   Every conversion reduces to exact integer arithmetic, so no floating point
 *   is used — this avoids rounding surprises when truncating. The "eye" weights
 *   0.30 / 0.59 / 0.11 are exactly 30 / 59 / 11 over 100, hence
 *   P = (30*R + 59*G + 11*B) / 100 with integer division yields the truncated
 *   result directly. Max component value is 100 * 255 = 25500, well within int.
 *
 * Complexity:
 *   O(1) per test case, O(T) overall.
 */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int c = 1; c <= t; ++c) {
        std::string method;
        int r, g, b;
        std::cin >> method >> r >> g >> b;

        int p = 0;
        if (method == "eye") {
            // 0.30R + 0.59G + 0.11B kept exact as an integer over 100; the
            // integer division then truncates the fractional part as required.
            p = (30 * r + 59 * g + 11 * b) / 100;
        } else if (method == "mean") {
            // Integer division truncates the fractional part of the average.
            p = (r + g + b) / 3;
        } else if (method == "max") {
            p = std::max({r, g, b});
        } else { // "min"
            p = std::min({r, g, b});
        }

        // Output label is Portuguese "Caso" per the statement — do not translate.
        std::cout << "Caso #" << c << ": " << p << '\n';
    }

    return 0;
}

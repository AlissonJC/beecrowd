/*
 * Beecrowd 1116 - Dividing X by Y
 *
 * Read N pairs of integers X (dividend) and Y (divisor) and, for each pair,
 * print the quotient X / Y with one digit after the decimal point. When the
 * division cannot be performed (divisor equal to zero) print the message
 * "divisao impossivel" instead.
 *
 * Input : N on the first line, then N lines each with two integers X and Y.
 * Output: one line per pair - either X/Y formatted with a single decimal place,
 *         or the literal "divisao impossivel" when Y == 0.
 *
 * Approach: straightforward per-case branch. Guard the divisor against zero
 * first; otherwise cast the dividend to double BEFORE dividing so the result
 * keeps its fractional part - integer division would truncate it (the "use
 * cast" hint in the statement). Output uses fixed notation with precision 1.
 *
 * Complexity: O(1) per pair, O(N) overall; O(1) space.
 */
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // One decimal place, fixed notation, for every numeric result.
    std::cout << std::fixed << std::setprecision(1);

    while (n--) {
        int x, y;
        std::cin >> x >> y;

        // A zero divisor makes the division impossible - Portuguese message,
        // ASCII exactly as the judge expects (no accents/cedilla).
        if (y == 0) {
            std::cout << "divisao impossivel\n";
        } else {
            // Cast to double so the quotient is real, not integer-truncated.
            std::cout << static_cast<double>(x) / y << '\n';
        }
    }

    return 0;
}

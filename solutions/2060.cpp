/*
 * Beecrowd 2060 - "Bino's Challenge"
 *
 * Given a list of numbers, count how many of them are multiples of 2, 3, 4
 * and 5, and report each count on its own line.
 *
 * Input : line 1 -> N        (1 <= N <= 1000) amount of numbers in the list.
 *         line 2 -> N integers L_i (1 <= L_i <= 100).
 * Output: four lines, one per divisor d in the order 2, 3, 4, 5, each line:
 *             "<count> Multiplo(s) de <d>"
 *         The word "Multiplo(s)" is Portuguese and printed verbatim (no accent,
 *         exactly as in the sample); the formatting must match byte for byte.
 *
 * Approach  : single pass over the list, incrementing a counter for each
 *             divisor the current value is divisible by. Counters are
 *             independent, so a value like 20 contributes to 2, 4 and 5 at once.
 * Complexity: O(N) time, O(1) extra space.
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Divisors to test, kept parallel to their counts so the output order is fixed.
    const int divs[4] = {2, 3, 4, 5};
    int count[4] = {0, 0, 0, 0};

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        // A number can be a multiple of several divisors simultaneously, so
        // every divisor is tested independently (no else-if chaining).
        for (int k = 0; k < 4; ++k) {
            if (x % divs[k] == 0) ++count[k];
        }
    }

    // Exact required format: "<count> Multiplo(s) de <divisor>".
    for (int k = 0; k < 4; ++k) {
        cout << count[k] << " Multiplo(s) de " << divs[k] << "\n";
    }
    return 0;
}

/*
 * Beecrowd 2582 — System of a Download
 *
 * A device has six buttons numbered 0..5. Pressing two buttons sums their
 * numbers (0..10), and that sum selects one of eleven songs. Given the two
 * pressed buttons, print the song that plays.
 *
 * Input:
 *   C (number of test cases), then C lines each with two integers X and Y
 *   (0 <= X, Y <= 5).
 *
 * Output:
 *   For each case, the name of the song mapped to X + Y.
 *
 * Approach:
 *   Index a fixed table of the eleven song names by the sum X + Y.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Song for each possible sum 0..10 (titles kept verbatim from the problem).
    const std::string songs[11] = {
        "PROXYCITY", "P.Y.N.G.", "DNSUEY!", "SERVERS", "HOST!", "CRIPTONIZE",
        "OFFLINE DAY", "SALT", "ANSWER!", "RAR?", "WIFI ANTENNAS"
    };

    int c;
    std::cin >> c;
    while (c-- > 0) {
        int x, y;
        std::cin >> x >> y;
        std::cout << songs[x + y] << '\n';   // sum is always within 0..10
    }

    return 0;
}

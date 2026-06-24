/*
 * Beecrowd 2685 — The Change
 *
 * Given the inclination angle M (0..360) of the Sun/Moon relative to Earth,
 * report the period of the day. The circle splits into four 90-degree quadrants:
 *   [0, 90)    -> "Bom Dia!!"       (morning)
 *   [90, 180)  -> "Boa Tarde!!"     (afternoon)
 *   [180, 270) -> "Boa Noite!!"     (night)
 *   [270, 360) -> "De Madrugada!!"  (dawn)
 * with 360 wrapping back to 0 (morning).
 *
 * Input:
 *   Several integers M (0 <= M <= 360), one per case, until EOF.
 *
 * Output:
 *   The greeting for each angle's period of day.
 *
 * Approach:
 *   Reduce M modulo 360 (so 360 maps to 0) and take M / 90 to pick the quadrant,
 *   indexing a fixed table of the four greetings.
 *
 * Complexity:
 *   O(1) per case.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::string period[4] = {
        "Bom Dia!!", "Boa Tarde!!", "Boa Noite!!", "De Madrugada!!"
    };

    int m;
    while (std::cin >> m) {
        int q = (m % 360) / 90;        // 360 wraps to 0; quadrant is 0..3
        std::cout << period[q] << '\n';
    }

    return 0;
}

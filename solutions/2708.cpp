/*
 * Beecrowd 2708 — Tourists in the Huacachina Park
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A checkpoint logs jeeps moving in and out of a park. Each event is a
 *   word followed by a tourist count T (0 <= T <= 20):
 *     "SALIDA" — the jeep leaves the center and ENTERS the park,
 *                carrying T tourists in.
 *     "VUELTA" — the jeep RETURNS from the ride, bringing T tourists back.
 *   The word "ABEND" ends the log. At the end of the shift, report how
 *   many tourists and how many jeeps are still out in the park (i.e. have
 *   not yet returned).
 *
 * Input:
 *   A sequence of "SALIDA T" / "VUELTA T" pairs, terminated by "ABEND".
 *
 * Output:
 *   Two lines:
 *     line 1 — number of tourists still in the park,
 *     line 2 — number of jeeps still in the park.
 *
 * Approach:
 *   Track two running balances. A SALIDA adds its tourists and one jeep
 *   to the "inside the park" totals; a VUELTA subtracts them. After the
 *   ABEND sentinel, whatever remains is what is still out on the ride.
 *
 * Complexity:
 *   O(number of events) time, O(1) space.
 */

#include <iostream>
#include <string>

int main() {
    std::string command;
    int touristsInside = 0;  // tourists currently out in the park
    int jeepsInside = 0;     // jeeps currently out in the park

    // Process events until the "ABEND" sentinel.
    while (std::cin >> command && command != "ABEND") {
        int t;
        std::cin >> t;

        if (command == "SALIDA") {
            // Jeep enters the park carrying t tourists.
            touristsInside += t;
            jeepsInside += 1;
        } else {  // "VUELTA": jeep comes back bringing t tourists.
            touristsInside -= t;
            jeepsInside -= 1;
        }
    }

    // Report tourists first, then jeeps, each on its own line.
    std::cout << touristsInside << "\n";
    std::cout << jeepsInside << "\n";

    return 0;
}

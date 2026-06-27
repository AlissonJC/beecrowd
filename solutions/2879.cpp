/*
 * Beecrowd 2879 - Unraveling Monty Hall
 *
 * Simulate the Monty Hall game under a fixed strategy: the player always picks
 * door 1, then always switches after the host opens one of the other two doors
 * to reveal a goat. Given, for each of N games, which door hides the car, count
 * how many games the player wins.
 *
 * Key observation: the player picks door 1 and then switches to the only other
 * still-closed door. If the car is behind door 1, switching always moves away
 * from it -> a loss. If the car is behind door 2 or 3, the host is forced to
 * reveal the other goat, so switching lands exactly on the car -> a win.
 * Therefore the player wins precisely when the car is NOT behind door 1.
 *
 * Input : first line has N (1 <= N <= 10^4), the number of games. Each of the
 *         next N lines has an integer in {1, 2, 3}, the car's door in that game.
 * Output: a single integer -- the number of games the player wins.
 *
 * Approach: Count how many of the N door numbers differ from 1. O(N).
 *
 * Complexity: O(N) time, O(1) space.
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int wins = 0;
    for (int i = 0; i < n; ++i) {
        int door;
        std::cin >> door;
        // Switching wins exactly when the car is not behind the initially
        // chosen door 1.
        if (door != 1)
            ++wins;
    }

    std::cout << wins << "\n";
    return 0;
}

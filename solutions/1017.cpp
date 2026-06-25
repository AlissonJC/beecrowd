/*
 * Beecrowd 1017 - Fuel Spent
 *
 * A car runs 12 km on each liter of fuel. Given the time spent on a trip (in
 * hours) and the average speed during the trip (in km/h), compute how many
 * liters of fuel the trip consumed.
 *
 * Input : two integers -- the trip time in hours and the average speed in km/h.
 * Output: the fuel needed in liters, printed with exactly three digits after
 *         the decimal point, followed by a trailing newline (omitting it causes
 *         a Presentation Error on Beecrowd).
 *
 * Approach: distance = time * speed, and fuel = distance / 12. Combine into
 *           fuel = (time * speed) / 12.0. Dividing by 12.0 (a double) forces
 *           floating-point division, so the fractional part is preserved.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    int time, speed;
    if (scanf("%d %d", &time, &speed) != 2) return 0;

    // distance = time * speed (km); fuel = distance / 12 (L).
    // Divide by 12.0 so the division is floating-point, not integer.
    double liters = (time * speed) / 12.0;

    // %.3f gives exactly three decimal places, as required.
    printf("%.3f\n", liters);
    return 0;
}

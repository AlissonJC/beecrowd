/*
 * Beecrowd 1014 - Consumption
 *
 * Given the total distance a car traveled (in km) and the total fuel it spent
 * (in liters), compute its average fuel consumption in kilometers per liter.
 *
 * Input : two values on the input -- an integer X (total distance in km) and a
 *         floating-point number Y (total fuel spent, one decimal digit).
 * Output: the average consumption X / Y printed with exactly three digits
 *         after the decimal point, followed by a space and the literal message
 *         "km/l", then a trailing newline (omitting it causes a Presentation
 *         Error on Beecrowd).
 *
 * Approach: average consumption is simply distance divided by fuel. Keep the
 *           fuel value as a double so the division is floating-point; reading
 *           it as an integer would truncate Y and give a Wrong Answer.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    int x;       // total distance in km
    double y;    // total fuel spent in liters
    if (scanf("%d %lf", &x, &y) != 2) return 0;

    // x / y: x is promoted to double, so the result is a real number and is
    // not truncated. %.3f then rounds it to three decimal places.
    printf("%.3f km/l\n", x / y);
    return 0;
}

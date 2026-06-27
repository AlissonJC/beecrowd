/*
 * Beecrowd 3145 - An unexpected Journey
 *
 * The number of days to reach the Lonely Mountain is the distance divided by
 * the number of people on the journey. The travelers are the N dwarves plus 2
 * (Bilbo and Gandalf also go), so the head count is N + 2 and the answer is
 * X / (N + 2).
 *
 * Input : a single line with two integers N and X (1 <= N <= 100, 1 <= X <=
 *         1000): the number of dwarves and the distance to the Lonely Mountain.
 * Output: a real number with exactly two decimal places, the number of days.
 *
 * Approach: One division. Add 2 to the dwarf count for Bilbo and Gandalf, then
 * divide the distance by that total in floating point.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    int n, x;
    if (scanf("%d %d", &n, &x) != 2)
        return 0;  // malformed input guard; also silences the warning

    // Travelers = dwarves + Bilbo + Gandalf. Cast to double so the division
    // keeps its fractional part; %.2f rounds to two decimals (e.g. 66.67).
    double days = (double)x / (n + 2);
    printf("%.2f\n", days);

    return 0;
}

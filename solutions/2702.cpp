/*
 * Beecrowd 2702 — Hard Choice
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A flight offers three meal types: chicken, beef and pasta. Given how
 *   many of each are available and how many passengers requested each,
 *   count how many passengers will SURELY not get their chosen meal.
 *   For a single meal type, if requests exceed the supply, exactly
 *   (requests - supply) passengers go unsatisfied; if supply meets or
 *   exceeds requests, nobody is left out for that type.
 *
 * Input:
 *   Line 1: Ca Ba Pa — available chicken, beef, pasta (0 <= each <= 100).
 *   Line 2: Cr Br Pr — requested chicken, beef, pasta (0 <= each <= 100).
 *
 * Output:
 *   One line with the total number of passengers who will not receive
 *   their selected meal.
 *
 * Approach:
 *   Each meal type is independent: the unsatisfied count is
 *   max(0, requested - available). Sum that shortfall across the three
 *   types. (Surplus of one meal cannot cover demand for another, so the
 *   types never interact.)
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <cstdio>
#include <algorithm>

int main() {
    int ca, ba, pa;  // available: chicken, beef, pasta
    int cr, br, pr;  // requested: chicken, beef, pasta
    scanf("%d %d %d", &ca, &ba, &pa);
    scanf("%d %d %d", &cr, &br, &pr);

    // Per meal, only a positive (requested - available) gap leaves
    // passengers unserved; clamp negatives (surplus) to zero.
    int unsatisfied = std::max(0, cr - ca)
                    + std::max(0, br - ba)
                    + std::max(0, pr - pa);

    printf("%d\n", unsatisfied);

    return 0;
}

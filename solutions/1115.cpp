/*
 * Beecrowd 1115 - Quadrant
 *
 * Read the coordinates (X, Y) of an indeterminate number of points in the
 * Cartesian plane. For each point, print the quadrant it belongs to. Reading
 * stops as soon as at least one coordinate is zero (the point would lie on an
 * axis, belonging to no quadrant), and that terminating pair prints nothing.
 *
 * Input : several lines, each with two integers X and Y. The sequence ends on
 *         the first line where X == 0 or Y == 0.
 * Output: for each point, the Portuguese quadrant name:
 *         (+,+) "primeiro", (-,+) "segundo", (-,-) "terceiro", (+,-) "quarto".
 *
 * Approach: a sentinel read loop that continues while both coordinates are
 * non-zero. Because zeros are excluded, each coordinate is strictly positive or
 * strictly negative, so the sign pair maps to exactly one of the four quadrants
 * - a simple cascade of comparisons covers every case.
 *
 * Complexity: O(1) per point, O(number of points) overall; O(1) space.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    // Stop when either coordinate is zero (point on an axis); no output for it.
    while (std::cin >> x >> y && x != 0 && y != 0) {
        // Both signs are now strict, so the four quadrants are exhaustive.
        // Portuguese names per the statement - do not translate.
        if (x > 0 && y > 0)
            std::cout << "primeiro\n";
        else if (x < 0 && y > 0)
            std::cout << "segundo\n";
        else if (x < 0 && y < 0)
            std::cout << "terceiro\n";
        else  // x > 0 && y < 0
            std::cout << "quarto\n";
    }

    return 0;
}

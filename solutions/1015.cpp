/*
 * Beecrowd 1015 - Distance Between Two Points
 *
 * Given two points in the plane, p1 = (x1, y1) and p2 = (x2, y2), compute the
 * Euclidean distance between them:
 *     distance = sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
 *
 * Input : two lines. The first holds two doubles "x1 y1"; the second holds two
 *         doubles "x2 y2". Whitespace/newlines are interchangeable separators
 *         for scanf, so the two-line layout needs no special handling.
 * Output: the distance printed with exactly four digits after the decimal
 *         point, followed by a trailing newline (omitting it causes a
 *         Presentation Error on Beecrowd).
 *
 * Approach: a direct application of the Euclidean distance formula. The
 *           coordinate differences can be negative, but squaring removes the
 *           sign, so no special handling is needed.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>
#include <cmath>

int main() {
    double x1, y1, x2, y2;
    if (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != 4) return 0;

    double dx = x2 - x1;
    double dy = y2 - y1;
    // hypot(dx, dy) == sqrt(dx*dx + dy*dy), but avoids intermediate overflow
    // and is the clearest expression of the Euclidean distance.
    double distance = std::hypot(dx, dy);

    // %.4f gives exactly four decimal places, as required.
    printf("%.4f\n", distance);
    return 0;
}

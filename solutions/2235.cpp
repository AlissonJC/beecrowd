/*
 * Beecrowd 2235 — Walking in Time
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A time machine has three credits A, B, C, each a number of years.
 *   Each credit may be used at most once, and each use sends you that
 *   many years either to the future (+) or to the past (-). Making
 *   between one and three trips, decide whether you can return exactly
 *   to the present, i.e. whether some non-empty subset of the credits,
 *   with chosen signs, sums to zero.
 *
 * Input:
 *   A single line with three integers A, B, C (1 <= A, B, C <= 1000).
 *
 * Output:
 *   "S" if returning to the present is possible, otherwise "N".
 *
 * Approach:
 *   Every credit is at least 1, so a signed sum of zero is impossible
 *   with a single trip. It reduces to two cases:
 *     - Two trips: +x - y = 0 means two credits are equal.
 *     - Three trips: ±A±B±C = 0 means one credit equals the sum of the
 *       other two (since all values are positive, the largest must
 *       offset the other two).
 *   Any zero-sum combination must contain at least one '-', so the trip
 *   "into the past" is always present; no extra check is needed.
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <cstdio>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Two equal credits cancel (+x - x), or one credit equals the sum
    // of the other two so all three cancel with the right signs.
    bool possible = (a == b) || (a == c) || (b == c)
                 || (a == b + c) || (b == a + c) || (c == a + b);

    printf("%s\n", possible ? "S" : "N");

    return 0;
}

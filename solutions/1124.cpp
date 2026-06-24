/*
 * Beecrowd 1124 - Elevator
 *
 * Two carbon cylinders, seen from above as circles of radii R1 and R2, must be
 * carried together in an elevator whose floor is an L-by-C rectangle. The
 * cylinders stay upright and may not overlap. Decide whether both fit inside the
 * rectangle at the same time.
 *
 * Input : several test cases, each a line with four integers L C R1 R2
 *         (1 <= L,C,R1,R2 <= 100). A line "0 0 0 0" ends the input.
 * Output: one line per case -- 'S' if both cylinders fit, 'N' otherwise.
 *
 * Approach: two requirements. (1) Each circle must fit on its own, i.e. its
 *   diameter fits both sides: 2*R <= L and 2*R <= C for each radius. (2) The two
 *   circles must be separable; the farthest apart their centres can be is at
 *   opposite corners, centre1 = (R1, R1) and centre2 = (L-R2, C-R2). They do not
 *   overlap iff that distance is at least R1+R2. Squaring keeps everything in
 *   exact integer arithmetic (no floating point): the gaps L-R1-R2 and C-R1-R2
 *   are non-negative once requirement (1) holds, so
 *       (L-R1-R2)^2 + (C-R1-R2)^2 >= (R1+R2)^2.
 *   Tangency (equality) counts as fitting -- see the sample where 25 >= 25 -> S.
 *
 * Complexity: O(1) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, C, r1, r2;
    // Read four integers per case; stop at the terminating all-zero line.
    while (scanf("%d %d %d %d", &L, &C, &r1, &r2) == 4 && (L || C || r1 || r2)) {
        // (1) each cylinder fits inside the rectangle by itself
        bool fits = (2 * r1 <= L && 2 * r1 <= C && 2 * r2 <= L && 2 * r2 <= C);
        // (2) opposite-corner placement leaves them non-overlapping (>= allows touching)
        int dx = L - r1 - r2, dy = C - r1 - r2;
        bool apart = (dx * dx + dy * dy >= (r1 + r2) * (r1 + r2));
        printf("%c\n", (fits && apart) ? 'S' : 'N');
    }
    return 0;
}

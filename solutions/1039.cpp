/*
 * Beecrowd 1039 - Fire Flowers
 *
 * A hunter harvests a magical flower by drawing a circle that completely
 * surrounds the flower's circular area; if that circle fails to fully enclose
 * the flower, the hunter is sacrificed. Given the hunter's circle and the
 * flower's circle, report "RICO" (rich) if the hunt succeeds or "MORTO" (dead).
 *
 * Input : several test cases (EOF), each six integers R1 X1 Y1 R2 X2 Y2 -- the
 *         radius and center (X1,Y1) of the hunter's drawn circle followed by the
 *         radius and center (X2,Y2) of the flower's area.
 * Output: one line per case, "RICO" or "MORTO".
 *
 * Constraints: 1 <= R1, R2 <= 1000, |X1|,|Y1|,|X2|,|Y2| <= 1000.
 *
 * Approach: the flower is fully enclosed exactly when the center distance d
 *   satisfies d + R2 <= R1 (internal tangency still counts -- see sample 4,
 *   where d + R2 == R1). Move R2 across and square both sides to stay in exact
 *   integer arithmetic: the answer is RICO iff R1 - R2 >= 0 AND
 *   dx^2 + dy^2 <= (R1 - R2)^2. The slack >= 0 guard is what makes squaring the
 *   inequality valid; R1 < R2 means the flower is wider than the drawn circle
 *   and can never fit -> MORTO.
 *
 * Complexity: O(1) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long r1, x1, y1, r2, x2, y2;
    while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
        long dx = x1 - x2;
        long dy = y1 - y2;
        long dist2 = dx * dx + dy * dy;   // squared distance between the centers
        long slack = r1 - r2;             // how much larger the hunter's circle is

        // Enclosed iff the hunter is at least as large as the flower AND the
        // centers are close enough: d^2 <= (R1 - R2)^2.
        cout << ((slack >= 0 && dist2 <= slack * slack) ? "RICO" : "MORTO") << "\n";
    }
    return 0;
}

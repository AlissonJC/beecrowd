/*
 * Beecrowd 3068 - Meteoros (Meteors)
 *
 * Given an axis-aligned rectangular farm and a list of points where meteors fell,
 * count how many meteors landed inside the farm, counting those exactly on the
 * boundary lines.
 *
 * Input : several test sets. Each starts with X1 Y1 X2 Y2, the upper-left and
 *         lower-right corners (0 <= Y2 < Y1 <= 10000, 0 <= X1 < X2 <= 10000);
 *         then N (0 <= N <= 10000); then N meteor coordinates "X Y". Input ends
 *         with X1 = Y1 = X2 = Y2 = 0.
 * Output: per set, "Teste n" then the count of meteors inside the farm.
 *
 * Approach: a point lies in the farm when X1 <= X <= X2 and Y2 <= Y <= Y1.
 *   Normalize the bounds with min/max for safety and tally the points that fall
 *   within the inclusive range.
 *
 * Complexity: O(N) per test set.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2, caseNum = 1;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;   // terminator

        int loX = min(x1, x2), hiX = max(x1, x2);
        int loY = min(y1, y2), hiY = max(y1, y2);

        int n;
        cin >> n;
        int inside = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x >= loX && x <= hiX && y >= loY && y <= hiY) ++inside;  // boundary counts
        }
        cout << "Teste " << caseNum++ << "\n" << inside << "\n";
    }
    return 0;
}

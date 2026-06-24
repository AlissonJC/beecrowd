/*
 * Beecrowd 3042 — Deflecting from Christmas Trees
 * Time limit: 1 s
 *
 * Multiple test cases, terminated by a line containing only "0".
 * For each test case: integer M (0 < M < 10000) gives the number of
 * one-meter rows on the three-lane track. Each of the next M rows is
 * "L C R" with each value in {0, 1}; a 1 marks a tree blocking that
 * lane. At least one lane is free per row. Santa starts on the centre
 * lane just before row 1; moving from lane p to lane q in a single
 * step costs |p - q| touches. Find the minimum total touches to walk
 * all M rows without ever standing on a blocked lane.
 *
 * Approach:
 *   Small-state DP. Let dp[l] = minimum touches accumulated so far to
 *   be on lane l (0=left, 1=centre, 2=right) AFTER surviving the
 *   current row. Initialise the "row before row 1" implicitly: cost
 *   |l - 1| to reach lane l from the centre. For each subsequent row,
 *   the new cost at lane l' (only if that lane is free in this row)
 *   is min_{l} (dp[l] + |l - l'|). Answer is the minimum of dp over
 *   the three lanes after the last row.
 *
 * Complexity:
 *   O(M) per test case with a 3x3 inner constant -- well inside 1 s.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    while (scanf("%d", &M) == 1 && M != 0) {
        const int INF = INT_MAX / 4;
        int dp[3] = {INF, INF, INF};

        for (int i = 0; i < M; i++) {
            int row[3];
            scanf("%d %d %d", &row[0], &row[1], &row[2]);

            int nd[3] = {INF, INF, INF};
            for (int l = 0; l < 3; l++) {
                if (row[l] == 1) continue; // lane blocked this row

                if (i == 0) {
                    // First row: travel from the centre lane to lane l.
                    nd[l] = abs(l - 1);
                } else {
                    int best = INF;
                    for (int pl = 0; pl < 3; pl++) {
                        if (dp[pl] >= INF) continue;
                        int cand = dp[pl] + abs(l - pl);
                        if (cand < best) best = cand;
                    }
                    nd[l] = best;
                }
            }
            dp[0] = nd[0]; dp[1] = nd[1]; dp[2] = nd[2];
        }

        int ans = min({dp[0], dp[1], dp[2]});
        printf("%d\n", ans);
    }
    return 0;
}

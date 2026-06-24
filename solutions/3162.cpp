/*
 * Beecrowd 3162 - Space Communication
 *
 * Ships are points in 3D space. The communication quality with the nearest ship
 * depends on the distance: up to 20 m.u. is high ("A"), above 20 and up to 50 is
 * medium ("M"), above 50 is low ("B"). For each ship report its signal strength
 * to its closest neighbour.
 *
 * Input : N (2 <= N <= 10); then N lines with integer coordinates x y z (0..100).
 *         (Read until EOF to be safe.)
 * Output: one line per ship with its signal letter (A, M or B).
 *
 * Approach: for each ship scan all others (N is tiny) and keep the minimum
 *   distance. Compare squared distances against 20^2 = 400 and 50^2 = 2500 so the
 *   whole thing stays in exact integer arithmetic -- no floating point or sqrt.
 *
 * Complexity: O(N^2) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<array<int, 3>> p(n);
        for (auto &s : p) cin >> s[0] >> s[1] >> s[2];

        for (int i = 0; i < n; ++i) {
            int best = INT_MAX;                       // nearest squared distance
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int dx = p[i][0] - p[j][0];
                int dy = p[i][1] - p[j][1];
                int dz = p[i][2] - p[j][2];
                best = min(best, dx * dx + dy * dy + dz * dz);
            }
            // Boundaries inclusive: d <= 20 -> d^2 <= 400, d <= 50 -> d^2 <= 2500.
            char c = (best <= 400) ? 'A' : (best <= 2500) ? 'M' : 'B';
            cout << c << "\n";
        }
    }
    return 0;
}

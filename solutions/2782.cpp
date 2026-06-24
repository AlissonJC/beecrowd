/*
 * Beecrowd 2782 - Stepladder
 *
 * A "stepladder" is a run of numbers with a constant difference between
 * consecutive terms (an arithmetic progression); any one- or two-element run
 * counts too. Split the given sequence into the longest possible stepladders --
 * where a stepladder that is part of a larger one is not counted separately --
 * and report how many there are. Consecutive stepladders share their boundary
 * element (e.g. 1 1 1 / 1 3 5 / 5 4 / 4 8 12).
 *
 * Input : N (1 <= N <= 1000), then N integers in [-1e6, 1e6].
 * Output: the number of maximal stepladders.
 *
 * Approach: look at the consecutive differences d[i] = a[i+1] - a[i]. A maximal
 *   stepladder is exactly a maximal run of equal differences, so the answer is
 *   the count of such runs = 1 + (number of places where the difference changes).
 *   A single number (N = 1) has no differences but is itself one stepladder.
 *
 * Complexity: O(N) time, O(N) space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {                       // single case, but loop is harmless
        vector<long long> a(n);
        for (auto &v : a) cin >> v;

        if (n == 1) { cout << 1 << "\n"; continue; }  // lone number is one ladder

        int runs = 1;                        // at least one stepladder exists
        long long prevDiff = a[1] - a[0];
        for (int i = 2; i < n; ++i) {
            long long d = a[i] - a[i - 1];
            if (d != prevDiff) {             // difference changed -> new stepladder
                ++runs;
                prevDiff = d;
            }
        }
        cout << runs << "\n";
    }
    return 0;
}

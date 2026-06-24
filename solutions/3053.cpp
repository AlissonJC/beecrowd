/*
 * Beecrowd 3053 - Jogo Dos Copos (The Cups Game)
 *
 * Three cups sit at positions A, B, C with a coin hidden under one. The dealer
 * performs N swaps -- type 1 swaps the cups at A and B, type 2 swaps B and C,
 * type 3 swaps A and C -- and the coin moves with its cup. Report where the coin
 * ends up.
 *
 * Input : N (1 <= N <= 1000); the coin's start position (A, B or C); then N move
 *         types (1, 2 or 3). (Read until EOF to be safe.)
 * Output: the coin's final position (A, B or C).
 *
 * Approach: keep the coin's current position as a single character and apply
 *   each swap: a swap only changes the position when the coin is at one of the
 *   two swapped slots.
 *
 * Complexity: O(N) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        char pos;
        cin >> pos;                          // where the coin starts
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            if (m == 1) {                    // swap A <-> B
                if (pos == 'A') pos = 'B';
                else if (pos == 'B') pos = 'A';
            } else if (m == 2) {             // swap B <-> C
                if (pos == 'B') pos = 'C';
                else if (pos == 'C') pos = 'B';
            } else {                         // swap A <-> C
                if (pos == 'A') pos = 'C';
                else if (pos == 'C') pos = 'A';
            }
        }
        cout << pos << "\n";
    }
    return 0;
}

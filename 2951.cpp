/*
 * Beecrowd 2951 - The Return of The King
 *
 * Each rune (a letter A..Z) emits a (possibly negative) amount of friendship.
 * Given the friendship G needed to defeat Gollum, the value of every rune, and
 * the runes Frodo and Sam recited, sum the friendship of the recited runes and
 * decide whether it is enough.
 *
 * Input : N and G; then N lines "R V" (rune letter, value in [-100,100]); then X;
 *         then X recited rune letters. (Read until EOF to be safe.)
 * Output: line 1 = total friendship; line 2 = "You shall pass!" if total >= G,
 *         otherwise "My precioooous".
 *
 * Approach: store each rune's value in a 26-slot table indexed by letter, then
 *   add up the values of the X recited runes and compare the total against G.
 *
 * Complexity: O(N + X) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, g;
    while (cin >> n >> g) {
        long long val[26] = {0};            // friendship value of each rune letter
        for (int i = 0; i < n; ++i) {
            char r; long long v;
            cin >> r >> v;
            val[r - 'A'] = v;
        }
        int x;
        cin >> x;
        long long total = 0;
        for (int i = 0; i < x; ++i) {
            char c;
            cin >> c;
            total += val[c - 'A'];          // accumulate the recited runes
        }
        cout << total << "\n";
        cout << (total >= g ? "You shall pass!" : "My precioooous") << "\n";
    }
    return 0;
}

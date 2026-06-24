/*
 * Beecrowd 2808 - Knights Again
 *
 * Given a knight's starting square and a target square on a chessboard, decide
 * whether the knight can reach the target in exactly one move.
 *
 * Input : a starting position and a target position separated by a space; each
 *         position is a column letter ('a'..'h') followed by a row digit
 *         ('1'..'8'). (Read until end of file to be safe.)
 * Output: "VALIDO" if it is a legal knight move, otherwise "INVALIDO".
 *
 * Approach: a knight moves in an L shape -- two squares along one axis and one
 *   along the other. So compute the absolute column and row distances and accept
 *   exactly when the unordered pair {dx, dy} equals {1, 2}.
 *
 * Complexity: O(1) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string from, to;
    while (cin >> from >> to) {
        int dx = abs((from[0] - 'a') - (to[0] - 'a'));   // column distance
        int dy = abs((from[1] - '1') - (to[1] - '1'));   // row distance
        bool ok = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
        // "VALIDO" / "INVALIDO" are the Portuguese strings the problem asks for.
        cout << (ok ? "VALIDO" : "INVALIDO") << "\n";
    }
    return 0;
}

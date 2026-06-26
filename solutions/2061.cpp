/*
 * Beecrowd 2061 - "Closing Tabs"
 *
 * Pericles' browser is infected: whenever he closes a tab ("fechou"), two new
 * tabs open in its place; whenever he clicks an ad ("clicou"), that tab simply
 * crashes and nothing new opens. Starting from an initial tab count and a list
 * of actions, report how many tabs remain at the end.
 *
 * Input : line 1 -> N M  (0 < N, M < 500): initial number of tabs and number
 *         of actions. Then M lines, each the word "fechou" or "clicou".
 * Output: a single line with the final number of tabs.
 *
 * Net effect per action:
 *   fechou -> close 1, open 2  => tabs change by (-1 + 2) = +1
 *   clicou -> close 1, open 0  => tabs change by (-1)      = -1
 * The statement guarantees the count never drops below zero, so no clamping
 * is required.
 *
 * Approach  : straightforward simulation; add 1 for each "fechou" and subtract
 *             1 for each "clicou". Only the first letter ('f' vs 'c') is needed
 *             to tell the actions apart.
 * Complexity: O(M) time, O(1) space.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tabs, m;
    cin >> tabs >> m;

    string action;
    for (int i = 0; i < m; ++i) {
        cin >> action;
        // "fechou" nets +1 tab, "clicou" nets -1; distinguish by first letter.
        if (action[0] == 'f') tabs += 1;
        else                  tabs -= 1;
    }

    cout << tabs << "\n";
    return 0;
}

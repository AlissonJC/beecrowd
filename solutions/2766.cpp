/*
 * Beecrowd 2766 - Input and Output Reading and Skipping Names
 *
 * Read ten names (each without spaces) and print just the third, seventh and
 * ninth of them, skipping the rest.
 *
 * Input : several test files, each ten lines, one name per line (at most 30
 *         characters, no spaces). Read until end of file.
 * Output: three lines per test case -- the 3rd, 7th and 9th names.
 *
 * Approach: the names have no spaces, so read them as tokens with cin >>; keep
 *   the ten in an array and emit positions 2, 6 and 8 (0-based). Reading the
 *   first token in the while condition cleanly stops the loop at end of file.
 *
 * Complexity: O(1) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string name[10];
    // Try to read the first name; failure means the input is exhausted.
    while (cin >> name[0]) {
        for (int i = 1; i < 10; ++i) cin >> name[i];
        // 3rd, 7th and 9th names are indices 2, 6 and 8.
        cout << name[2] << "\n" << name[6] << "\n" << name[8] << "\n";
    }
    return 0;
}

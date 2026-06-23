/*
 * Beecrowd 2760 - String Input and Output
 *
 * Read three phrases A, B, C (each a full line of up to 100 characters, spaces
 * included) and print four lines: the three phrases concatenated in the orders
 * A B C, then B C A, then C A B, and finally A B C again but using only the
 * first ten characters of each phrase.
 *
 * Input : several test files, each three lines (phrases A, B, C). Read until EOF.
 * Output: four concatenated lines per test case.
 *
 * Approach: read whole lines with getline (the phrases contain spaces, so a
 *   token read would split them) and concatenate. "Only 10 characters" is just
 *   substr(0, 10), which safely yields the whole phrase when it is shorter.
 *
 * Complexity: O(total characters) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B, C;
    // Each test case is exactly three lines; stop when the input ends.
    while (getline(cin, A) && getline(cin, B) && getline(cin, C)) {
        // Guard against a stray carriage return from CRLF input.
        auto chop = [](string &s) { if (!s.empty() && s.back() == '\r') s.pop_back(); };
        chop(A); chop(B); chop(C);

        cout << A + B + C << "\n";                                   // order A B C
        cout << B + C + A << "\n";                                   // order B C A
        cout << C + A + B << "\n";                                   // order C A B
        // Same as line 1 but only the first 10 characters of each phrase.
        cout << A.substr(0, 10) + B.substr(0, 10) + C.substr(0, 10) << "\n";
    }
    return 0;
}

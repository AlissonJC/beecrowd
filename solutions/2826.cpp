/*
 * Beecrowd 2826 - Lexical
 *
 * Read two lowercase words and print them in lexicographical (dictionary) order:
 * compare character by character, and when one word is a prefix of the other put
 * the shorter one first.
 *
 * Input : two words (letters a..z, length <= 20). Read until end of file.
 * Output: the two words in lexicographical order, one per line.
 *
 * Approach: C++'s std::string comparison already implements exactly this rule
 *   (lexicographic, with the shorter prefix ordered first), so just swap the two
 *   words when they are out of order and print them.
 *
 * Complexity: O(L) per test case, L = word length.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    while (cin >> a >> b) {
        if (a > b) swap(a, b);          // ensure a is the lexicographically smaller word
        cout << a << "\n" << b << "\n";
    }
    return 0;
}

/*
 * Beecrowd 3303 - "Big Word"
 *
 * Juquinha must avoid saying "palavroes" (big words). A word is a "palavrao"
 * when it has ten or more characters; any shorter word is a "palavrinha".
 * For each word given, report which category it falls into.
 *
 * Input : several test cases, one word per token, made only of lowercase
 *         letters, each of length at most 20. No count is given, so read
 *         until end of file.
 * Output: for each word print "palavrao" if its length is >= 10, otherwise
 *         "palavrinha", one answer per line.
 *
 * Approach  : read each whitespace-separated word and compare its length to
 *             the threshold 10. Reading with operator>> already splits on
 *             whitespace, so each extraction yields exactly one word.
 * Complexity: O(L) per word to read it, O(1) for the length test.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string w;
    // EOF-terminated: keep consuming words until extraction fails.
    while (cin >> w) {
        // Threshold is inclusive: exactly ten characters already counts as big.
        cout << (w.size() >= 10 ? "palavrao" : "palavrinha") << "\n";
    }
    return 0;
}

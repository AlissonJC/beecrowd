/*
 * Beecrowd 2765 - Coming Input and Output
 *
 * Read a sentence that contains a comma somewhere in the middle and print it as
 * two lines: the part before the comma, then the part after the comma. The comma
 * itself is dropped, but whatever follows it (typically a leading space) is kept
 * verbatim.
 *
 * Input : several test files, each one line: a phrase of up to 100 characters
 *         (may contain spaces) holding one comma. Read until end of file.
 * Output: two lines per test case -- the text before and after the comma.
 *
 * Approach: read the whole line with getline (it has spaces), locate the first
 *   comma, and split there: substr(0, pos) is the first part and substr(pos + 1)
 *   the second. No trimming, so the space that follows the comma stays attached
 *   to the second line, matching the samples.
 *
 * Complexity: O(line length) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();  // CRLF guard

        size_t pos = line.find(',');             // split at the first comma
        cout << line.substr(0, pos) << "\n";      // text before the comma
        // Everything after the comma, kept as-is (leading space included).
        cout << (pos == string::npos ? string() : line.substr(pos + 1)) << "\n";
    }
    return 0;
}

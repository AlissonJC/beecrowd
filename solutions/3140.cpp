/*
 * Beecrowd 3140 — Copying and Pasting Code
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Given an HTML file on stdin, print every line strictly between the
 *   "<body>" and "</body>" tag lines, exactly as it appeared in the
 *   input (preserving leading indentation). The tag lines themselves
 *   are NOT printed. Both tags are guaranteed to appear exactly once,
 *   and each occupies its own line containing nothing besides the tag
 *   and possibly some leading indent whitespace.
 *
 * Input:
 *   Multiple lines until EOF. No line exceeds 1000 characters or is
 *   blank.
 *
 * Output:
 *   The lines between "<body>" and "</body>", verbatim (same indent,
 *   same trailing characters), each followed by a newline.
 *
 * Approach:
 *   Stream line by line with a boolean "inside" flag. When the trimmed
 *   line equals "<body>" turn the flag on; when it equals "</body>"
 *   turn it off. While the flag is on, echo the ORIGINAL (untrimmed)
 *   line so the indent is preserved exactly. Trimming is only used for
 *   tag detection, never for the emitted text.
 *
 * Complexity:
 *   O(total characters), single pass.
 */

#include <iostream>
#include <string>
using namespace std;

// Return a copy of s with leading whitespace stripped (spaces and tabs)
// and any trailing CR or whitespace removed. Only used to identify the
// body tag lines -- the emitted output uses the original line untouched.
static string trim(const string& s) {
    size_t a = s.find_first_not_of(" \t");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r");
    return s.substr(a, b - a + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    bool inside = false;
    while (getline(cin, line)) {
        string t = trim(line);
        if (t == "<body>") {
            // Opening tag: enter copy-mode but do NOT print this line.
            inside = true;
        } else if (t == "</body>") {
            // Closing tag: exit copy-mode and skip this line as well.
            inside = false;
        } else if (inside) {
            // Echo the line verbatim so the original indentation
            // (and anything else on the line) is preserved exactly.
            cout << line << "\n";
        }
    }
    return 0;
}

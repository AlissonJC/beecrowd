/*
 * Beecrowd 1215 - Andy's First Dictionary
 * Platform: Beecrowd
 *
 * Problem restatement:
 *   List every distinct word in the input text, one per line. A word is a
 *   maximal run of letters (A-Z / a-z); single-letter words count. Comparison is
 *   case-insensitive, so words are emitted in lower case, sorted alphabetically.
 *
 * Input  : free text, up to 10000 lines of at most 200 chars, ended by EOF.
 * Output : the distinct words, lower-cased, in ascending alphabetical order, one
 *          per line. At most 5000 distinct words.
 *
 * Sample:
 *   "Ex(*$a#.mpl.e:" yields the words a, e, ex, mpl; "Disneyland"/"LEFT." etc.
 *   all fold to lower case and duplicates collapse.
 *
 * Approach:
 *   Scan character by character. Letters extend the current word (stored in
 *   lower case); any non-letter ends it. Each finished word is inserted into a
 *   std::set<string>, which keeps the words unique and sorted automatically, so
 *   a final left-to-right traversal prints exactly the required output.
 *
 * Complexity:
 *   O(C log W) for C input characters and W distinct words (each word insert is
 *   O(len * log W)); trivial for the given limits.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> words;
    string cur;
    int c;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            cur += (char)tolower(c);          // build the word in lower case
        } else if (!cur.empty()) {
            words.insert(cur);                // a non-letter ends the word
            cur.clear();
        }
    }
    if (!cur.empty()) words.insert(cur);      // flush a word ending exactly at EOF

    for (const string& w : words)
        printf("%s\n", w.c_str());
    return 0;
}

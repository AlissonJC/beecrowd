/*
 * Beecrowd 2635 - "Web Browser"
 *
 * An autocomplete feature: given a set of previously searched words, answer
 * queries of the form "how many stored words start with this string, and how
 * long is the longest of them?". A word that equals the query counts as well
 * (the query is a prefix of itself). If no word has the query as a prefix,
 * report -1.
 *
 * Input : several test cases until EOF. Per case:
 *           N                         (1 <= N <= 10^4) number of stored words
 *           N lines -> distinct words (nonempty, <= 100 lowercase letters)
 *           Q                         (1 <= Q <= 100)  number of queries
 *           Q lines -> query strings  (nonempty, <= 100 lowercase letters)
 * Output: per query -> "<count> <maxLength>", or "-1" if count is zero.
 *
 * Approach  : sort the words once. Every word sharing a prefix S sits in a
 *             contiguous block of the sorted order: the half-open range
 *             [S, S_hi), where S_hi is S with its last character incremented by
 *             one. Two binary searches give the block; its size is the count
 *             and a scan of the block gives the longest word.
 * Complexity: O(N log N * L) to sort and O(Q * (log N * L + block)) per test
 *             case, with L <= 100 the word length. Memory is just the N strings.
 *
 * Why incrementing the last char needs no carry: words with prefix S are
 * exactly the strings W with S <= W < S_hi. Bumping S's last char (e.g.
 * "marat" -> "marau") yields the smallest string greater than every string
 * that starts with S, so the range is exact. It even works when the last char
 * is 'z': 'z'+1 == '{', which is greater than any 'a'..'z', and since the words
 * only contain a-z this still bounds the block correctly.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // EOF-terminated: each test case starts by reading the word count.
    while (cin >> n) {
        vector<string> words(n);
        for (int i = 0; i < n; i++) cin >> words[i];

        // Sorting makes every prefix block contiguous so it can be binary-searched.
        sort(words.begin(), words.end());

        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;

            // Upper boundary of the prefix block (s is guaranteed nonempty).
            string s_hi = s;
            s_hi.back()++;            // 'marat' -> 'marau'; 'z' -> '{'

            // Block of words with prefix s = [lo, hi).
            auto lo = lower_bound(words.begin(), words.end(), s);
            auto hi = lower_bound(words.begin(), words.end(), s_hi);

            int count = (int)(hi - lo);
            if (count == 0) {
                // No stored word starts with this query.
                cout << -1 << "\n";
            } else {
                // Longest word among those sharing the prefix.
                int maxLen = 0;
                for (auto it = lo; it != hi; ++it)
                    maxLen = max(maxLen, (int)it->size());
                cout << count << " " << maxLen << "\n";
            }
        }
    }
    return 0;
}

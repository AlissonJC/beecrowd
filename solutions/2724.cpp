/*
 * Beecrowd 2724 - "Help Patatatitu"
 *
 * Each test case lists T "dangerous compound" chemical formulas and U experiment
 * formulas. An experiment is dangerous (must be aborted) when some dangerous
 * formula occurs inside it as a contiguous run of elements with matching symbols
 * AND matching proportions. So matching happens at the level of (element, count)
 * tokens, not raw characters:
 *   - ClF4 does NOT contain ClF3 - the count differs (F3 vs F4).
 *   - Mg2Fe does NOT contain Mg2F - the symbol differs (Fe vs F).
 *
 * A token is therefore: one uppercase letter, then any lowercase letters (the
 * rest of the symbol), then any digits (the count). Examples:
 *   "ClF3"  -> {"Cl","F3"}      "Mg2Fe" -> {"Mg2","Fe"}
 *   "C6H12F2" -> {"C6","H12","F2"}
 * Tokenize both the pattern and the experiment, then test whether the pattern's
 * token sequence appears as a contiguous block inside the experiment's.
 *
 * Input : line 1 -> N (0 < N < 10). Each test case: T (0 < T < 51), then T
 *         dangerous formulas; then U (0 < U < 51), then U experiment formulas.
 *         Every formula is a string up to 50 characters.
 * Output: per experiment -> "Abortar" if dangerous, else "Prossiga". Consecutive
 *         test cases are separated by a blank line.
 *
 * Approach  : tokenize formulas, then brute-force substring search at token level.
 * Complexity: O(U * T * Le * Lp) per test case with L the token counts (<= ~25);
 *             trivially within limits.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// Split a formula into element tokens "[A-Z][a-z]*[0-9]*". Any character before
// the first uppercase letter (e.g. a stray leading digit) is skipped, since a
// valid element - and thus any pattern - always begins with an uppercase symbol.
vector<string> tokenize(const string& s) {
    vector<string> tokens;
    int i = 0, n = (int)s.size();
    while (i < n) {
        if (isupper((unsigned char)s[i])) {
            int j = i + 1;
            while (j < n && islower((unsigned char)s[j])) j++;  // finish the symbol
            while (j < n && isdigit((unsigned char)s[j])) j++;  // attach the count
            tokens.push_back(s.substr(i, j - i));
            i = j;
        } else {
            i++;  // stray leading digit/lowercase: not part of any element
        }
    }
    return tokens;
}

// True when pat occurs as a contiguous block of tokens within exp.
bool containsPattern(const vector<string>& exp, const vector<string>& pat) {
    int e = (int)exp.size(), p = (int)pat.size();
    if (p > e) return false;
    for (int start = 0; start + p <= e; start++) {
        bool ok = true;
        for (int k = 0; k < p; k++)
            if (exp[start + k] != pat[k]) { ok = false; break; }
        if (ok) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int tc = 0; tc < n; tc++) {
        if (tc > 0) cout << "\n";   // blank line BETWEEN test cases (none before the first)

        int t;
        cin >> t;
        vector<vector<string>> patterns(t);
        for (int i = 0; i < t; i++) {
            string s;
            cin >> s;
            patterns[i] = tokenize(s);
        }

        int u;
        cin >> u;
        for (int i = 0; i < u; i++) {
            string s;
            cin >> s;
            vector<string> exp = tokenize(s);

            // Dangerous if ANY listed compound is embedded in this experiment.
            bool dangerous = false;
            for (int k = 0; k < t && !dangerous; k++)
                if (containsPattern(exp, patterns[k])) dangerous = true;

            // Portuguese verdicts from the statement - keep verbatim.
            cout << (dangerous ? "Abortar" : "Prossiga") << "\n";
        }
    }
    return 0;
}

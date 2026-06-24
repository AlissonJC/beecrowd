/*
 * Beecrowd 2852 — Messaging
 * Time limit: 1 s
 *
 * Read a lowercase keyword and N messages composed of lowercase
 * letters and spaces. For each message, apply a Vigenère cipher
 * (letter shift by the keyword letter) but ONLY to words whose first
 * letter is a consonant; words starting with a vowel are copied as-is.
 * The key index advances across encrypted letters globally -- it does
 * NOT reset at each new encrypted word, and it does NOT advance for
 * vowel-led words that get skipped. Spaces are preserved.
 *
 * Algorithm:
 *   - Walk the message left to right, slicing it into space-separated
 *     words and emitting the spaces verbatim.
 *   - If a word starts with a, e, i, o, or u, append it untouched.
 *   - Otherwise, for each letter c in the word, encrypted letter is
 *         'a' + (c - 'a' + key[keyIdx % keyLen] - 'a') mod 26
 *     and keyIdx is incremented exactly once per encrypted letter.
 *
 * Complexity:
 *   O(total message length) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string key;
    if (!(cin >> key)) return 0;
    int N;
    cin >> N;
    cin.ignore();

    auto isVowel = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    int K = (int)key.size();

    while (N-- > 0) {
        string msg;
        getline(cin, msg);

        string out;
        out.reserve(msg.size());
        int keyIdx = 0;   // global across all encrypted letters in this message

        int i = 0, n = (int)msg.size();
        while (i < n) {
            if (msg[i] == ' ') {
                out.push_back(' ');
                i++;
                continue;
            }
            // Collect the next whitespace-delimited word.
            int j = i;
            while (j < n && msg[j] != ' ') j++;

            if (isVowel(msg[i])) {
                // Vowel-led words are copied verbatim and do NOT advance the key.
                out.append(msg, i, j - i);
            } else {
                // Encrypt every letter of this word, advancing the key index.
                for (int k = i; k < j; k++) {
                    int shift = key[keyIdx % K] - 'a';
                    int enc   = (msg[k] - 'a' + shift) % 26;
                    out.push_back((char)('a' + enc));
                    keyIdx++;
                }
            }
            i = j;
        }
        cout << out << '\n';
    }
    return 0;
}

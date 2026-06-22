/*
 * Beecrowd 2502 — Deciphering the Encrypted Card
 *
 * A symmetric substitution cipher is given by two equal-length lines: the
 * character at position i of the first line is paired with the character at
 * position i of the second line, and the substitution swaps each pair both ways
 * (an involution). Each character appears only once across the two lines. Decode
 * N message lines with this key.
 *
 * Letters are matched case-insensitively, and the deciphered case follows the
 * source character: an uppercase letter yields an uppercase result, a lowercase
 * letter a lowercase result, and a non-letter (digit, symbol, space) that maps
 * to a letter yields a lowercase letter. A character not present in the cipher
 * is left unchanged.
 *
 * Input:
 *   Several test cases. Each begins with "C N" (0 < C < 21, 0 < N < 100). The
 *   next two lines are the C-character cipher (may contain spaces/punctuation).
 *   Then N lines (1..1000 chars) to decode. Read until EOF.
 *
 * Output:
 *   The decoded text for each line, then a blank line after each test case
 *   (including the last one).
 *
 * Approach:
 *   Build a 128-entry substitution table keyed by the cipher characters (letters
 *   normalized to uppercase). For each message character look up its normalized
 *   form; if present, emit the partner with the case rule above, else emit it
 *   unchanged.
 *
 * Complexity:
 *   O(total characters) per test case.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>

// Normalize a letter to uppercase for cipher matching; leave other chars as is.
static int norm(char ch) {
    unsigned char u = static_cast<unsigned char>(ch);
    return std::isalpha(u) ? std::toupper(u) : u;
}

// Remove a single trailing carriage return (from CRLF input); keep real spaces.
static void stripCR(std::string& s) {
    if (!s.empty() && s.back() == '\r') s.pop_back();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c, n;
    while (std::cin >> c >> n) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string l1, l2;
        std::getline(std::cin, l1);
        std::getline(std::cin, l2);
        stripCR(l1);
        stripCR(l2);

        // partner[x] = character x decodes to; -1 means "not in cipher". Keys
        // are normalized (letters uppercased) for case-insensitive matching.
        int partner[128];
        for (int i = 0; i < 128; ++i) partner[i] = -1;

        int pairs = std::min({c, (int)l1.size(), (int)l2.size()});
        for (int i = 0; i < pairs; ++i) {
            partner[norm(l1[i])] = static_cast<unsigned char>(l2[i]);
            partner[norm(l2[i])] = static_cast<unsigned char>(l1[i]);
        }

        for (int k = 0; k < n; ++k) {
            std::string text;
            std::getline(std::cin, text);
            stripCR(text);

            std::string out;
            out.reserve(text.size());
            for (char ch : text) {
                int rep = partner[norm(ch)];
                if (rep < 0) {
                    out += ch;                              // not in cipher
                } else if (std::isalpha(static_cast<unsigned char>(rep))) {
                    // Output case follows the source character.
                    bool up = std::isupper(static_cast<unsigned char>(ch));
                    out += static_cast<char>(up ? std::toupper(rep)
                                                : std::tolower(rep));
                } else {
                    out += static_cast<char>(rep);          // maps to digit/symbol
                }
            }
            std::cout << out << '\n';
        }

        std::cout << '\n';   // blank line after each test case
    }

    return 0;
}

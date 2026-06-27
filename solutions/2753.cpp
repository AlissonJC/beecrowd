/*
 * Beecrowd 2753 — Output 7
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Start from the integer 97 and count up by one for 26 values, ending at
 *   122. For each value print its decimal form, then " e ", then the ASCII
 *   character that has that code. Codes 97..122 are exactly the lowercase
 *   letters 'a'..'z', so the table pairs each number with its letter.
 *
 * Input:
 *   None.
 *
 * Output:
 *   26 lines, each "<n> e <c>", where n runs 97..122 and c is the
 *   character whose ASCII code is n (97 -> 'a', ..., 122 -> 'z').
 *
 * Approach:
 *   Loop n from 97 to 122 and print n as an integer and as a character.
 *   The "%c" conversion reinterprets the same integer as its ASCII glyph,
 *   so no explicit number-to-letter table is needed.
 *
 * Complexity:
 *   O(1) — a fixed 26-line table.
 */

#include <cstdio>

int main() {
    // 97..122 are the ASCII codes of 'a'..'z'. Print each code as a number
    // and, via %c, as the matching character.
    for (int n = 97; n <= 122; ++n) {
        printf("%d e %c\n", n, n);
    }

    return 0;
}

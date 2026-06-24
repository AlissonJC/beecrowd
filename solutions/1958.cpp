/*
 * Beecrowd 1958 — Scientific Notation
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Read one decimal number X (up to 110 characters, at most 6 decimal
 *   places) and print it in scientific notation with:
 *     - mantissa sign always shown,
 *     - mantissa rounded to exactly four decimal places (one digit
 *       before the dot, four after),
 *     - the literal 'E' between mantissa and exponent,
 *     - exponent sign always shown,
 *     - exponent written with at least two digits (more if needed).
 *
 * Input/output:
 *   stdin holds the number as plain text. Print the formatted result
 *   followed by a newline.
 *
 * Why a string-based approach:
 *   The number can have up to 110 characters, which far exceeds the
 *   ~17 significant digits a 64-bit double can keep. Parsing X as a
 *   double would lose the very digits the answer depends on, so we
 *   work directly on the digit string.
 *
 * Approach:
 *   1. Peel off an optional leading sign.
 *   2. Split the remaining string at the decimal point (if any) into
 *      an integer part and a fractional part; concatenate them into
 *      one digit string and remember how many digits were before the
 *      dot (intLen).
 *   3. Find the first non-zero digit, at index k. If everything is
 *      zero, the answer is "+0.0000E+00".
 *   4. The exponent is intLen - k - 1 (positive when k is in the
 *      integer part) or -(k - intLen + 1) (negative when k is in the
 *      fractional part).
 *   5. Take six significant digits starting at k (zero-padded if the
 *      number doesn't have enough). The sixth is the rounding digit.
 *      If it is >= '5', increment the fifth and propagate any carry;
 *      if the carry runs past the leading digit, the mantissa becomes
 *      1.0000 and the exponent grows by one.
 *   6. Print sign, leading digit, '.', four digits, 'E', exponent
 *      sign, then |exp| with width >= 2 (use "%02d" — wider exponents
 *      such as 100 still come out correctly).
 *
 * Complexity:
 *   O(L) where L <= 110 is the input length. Trivial.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;

    // Step 1 -- optional leading sign.
    char sign = '+';
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-') {
        sign = s[i];
        i++;
    }

    // Step 2 -- split at the decimal point.
    size_t dot = s.find('.', i);
    string intPart, fracPart;
    if (dot == string::npos) {
        intPart  = s.substr(i);
        fracPart = "";
    } else {
        intPart  = s.substr(i, dot - i);
        fracPart = s.substr(dot + 1);
    }
    string digits = intPart + fracPart;
    int intLen = (int)intPart.size();

    // Step 3 -- find the first non-zero digit.
    int k = -1;
    for (int j = 0; j < (int)digits.size(); j++) {
        if (digits[j] != '0') { k = j; break; }
    }

    // Zero special case -- preserve whatever sign the input carried.
    if (k == -1) {
        printf("%c0.0000E+00\n", sign);
        return 0;
    }

    // Step 4 -- exponent comes from k's position relative to the dot.
    int exp;
    if (k < intLen) {
        exp = intLen - k - 1;
    } else {
        exp = -(k - intLen + 1);
    }

    // Step 5 -- pick six significant digits (five for the mantissa, one
    // to decide rounding) and zero-pad if the original number doesn't
    // have enough digits to fill them.
    char sig[6] = {'0', '0', '0', '0', '0', '0'};
    for (int j = 0; j < 6; j++) {
        int idx = k + j;
        if (idx < (int)digits.size()) sig[j] = digits[idx];
    }

    // Half-up rounding on the sixth digit; propagate any carry. If the
    // carry escapes past sig[0] the mantissa is 10.0000 -- write it as
    // 1.0000 with an exponent that has grown by one.
    if (sig[5] >= '5') {
        int j = 4;
        while (j >= 0 && sig[j] == '9') {
            sig[j] = '0';
            j--;
        }
        if (j < 0) {
            sig[0] = '1';
            // sig[1..4] are already '0' from the carry loop.
            exp++;
        } else {
            sig[j]++;
        }
    }

    // Step 6 -- assemble the formatted output. "%02d" pads narrow
    // exponents to two digits and leaves wider ones (100, 110, ...)
    // untouched.
    char expSign = exp >= 0 ? '+' : '-';
    int expAbs   = abs(exp);
    printf("%c%c.%c%c%c%cE%c%02d\n",
           sign,
           sig[0],
           sig[1], sig[2], sig[3], sig[4],
           expSign,
           expAbs);
    return 0;
}

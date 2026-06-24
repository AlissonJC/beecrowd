/*
 * Beecrowd 3344 — Brute
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Let f(x) be the number of characters in x's English name, counting
 *   the space inside multi-word numbers (so f(100) = len("ONE HUNDRED") = 11).
 *   Read an integer x (1 <= x <= 100) and print f iterated 1000 times.
 *
 * Why this is easy:
 *   For x <= 100, one application of f drops the value to at most
 *   len("ONE HUNDRED") = 11, and then 4 is a fixed point (f(4) = 4
 *   because "FOUR" has four letters). Every trajectory converges to 4
 *   in well under ten iterations -- iterating 1000 times is overkill
 *   but matches the statement verbatim.
 *
 * Approach:
 *   Precompute the lengths of 0..19 ("ZERO".."NINETEEN") and of the
 *   tens (TWENTY, THIRTY, FORTY, FIFTY, SIXTY, SEVENTY, EIGHTY,
 *   NINETY). Compose composite numbers as "tens [space ones]" or
 *   "ones HUNDRED [space rest]" so the length function works for any
 *   value <= 999. Iterate f one thousand times.
 *
 * Complexity:
 *   O(1) -- a constant number of arithmetic ops and lookups.
 */

#include <bits/stdc++.h>
using namespace std;

// English-name lengths for 0..19. "ZERO"=4, "ONE"=3, ... "NINETEEN"=8.
static const int LEN_UNITS[20] = {
    4, 3, 3, 5, 4, 4, 3, 5, 5, 4,
    3, 6, 6, 8, 8, 7, 7, 9, 8, 8
};
// Lengths for the tens (index 2..9 = TWENTY..NINETY). 0,1 unused.
static const int LEN_TENS[10] = {
    0, 0, 6, 6, 5, 5, 5, 7, 6, 6
};

static int spelledLength(int x) {
    if (x < 20) return LEN_UNITS[x];
    if (x < 100) {
        int tens = x / 10;
        int ones = x % 10;
        int total = LEN_TENS[tens];
        // Add a space + the "ones" word only when needed (e.g. 21).
        if (ones > 0) total += 1 + LEN_UNITS[ones];
        return total;
    }
    // 100 .. 999 -- "X HUNDRED" optionally followed by " <rest>".
    int hundreds = x / 100;
    int rest     = x % 100;
    int total    = LEN_UNITS[hundreds] + 1 + 7; // "X" + space + "HUNDRED"
    if (rest > 0) total += 1 + spelledLength(rest);
    return total;
}

int main() {
    int x;
    scanf("%d", &x);
    // 1000 iterations of f. Converges to 4 almost immediately for any
    // x <= 100, but iterate the full count for correctness anyway.
    for (int i = 0; i < 1000; i++) x = spelledLength(x);
    printf("%d\n", x);
    return 0;
}

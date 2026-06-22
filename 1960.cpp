/*
 * Beecrowd 1960 — Roman Numerals for Page Numbers
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Convert a positive integer N (0 < N < 1000) to its uppercase Roman
 *   numeral representation. The relevant letters are I = 1, V = 5,
 *   X = 10, L = 50, C = 100, D = 500. M = 1000 is mentioned in the
 *   statement but never produced because N stays strictly under 1000.
 *
 * Input:
 *   A single integer N (0 < N < 1000).
 *
 * Output:
 *   N in Roman numerals, uppercase, on a single line.
 *
 * Approach:
 *   Greedy subtraction with a table that already includes the
 *   subtractive composites CM=900, CD=400, XC=90, XL=40, IX=9 and
 *   IV=4. Walking the table top-down and emitting the symbol while
 *   the remaining value still fits handles every case from 1 to 999
 *   in a single pass.
 *
 * Complexity:
 *   O(log N) symbol emissions; trivial.
 */

#include <cstdio>

int main() {
    // Value/symbol pairs sorted descending. The composites (900, 400,
    // 90, 40, 9, 4) sit alongside the additive ones so the greedy
    // sweep picks "CM" instead of "DCCCC" automatically.
    static const int  vals[]    = { 900, 500, 400, 100,  90,  50,  40,  10,   9,   5,   4,   1};
    static const char* syms[]   = {"CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    static const int  NPAIRS    = 12;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < NPAIRS; i++) {
        while (n >= vals[i]) {
            fputs(syms[i], stdout);
            n -= vals[i];
        }
    }
    putchar('\n');

    return 0;
}

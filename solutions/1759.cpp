/*
 * Beecrowd 1759 — Ho Ho Ho
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Print the word "Ho" exactly N times, with the occurrences separated
 *   by a single space and an exclamation mark immediately after the
 *   final "Ho" (no space before the "!").
 *
 * Input:
 *   A single integer N  (0 < N <= 10^6).
 *
 * Output:
 *   "Ho Ho Ho ... Ho!" with N "Ho" tokens, followed by a newline.
 *
 * Approach:
 *   One linear pass: print the first "Ho", then for each remaining
 *   occurrence print " Ho" (space + word). End with "!\n". This keeps
 *   the format exact (no trailing space) without an explicit if-check
 *   inside the loop.
 *
 * Complexity:
 *   O(N) writes for N up to 10^6. With buffered stdio the ~3 MB output
 *   is comfortable inside the 1 s budget.
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    // First token has no leading space; every subsequent token is
    // prefixed by exactly one space. This produces "Ho Ho ... Ho"
    // with no trailing space before the final "!".
    fputs("Ho", stdout);
    for (int i = 1; i < n; i++) {
        fputs(" Ho", stdout);
    }
    puts("!");

    return 0;
}

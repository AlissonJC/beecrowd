/*
 * Beecrowd 1564 — Brazil World Cup
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   The president receives N complaints about the World Cup per test
 *   case. If there are no complaints (N == 0), print "vai ter copa!"
 *   ("there will be a Cup!"). Otherwise -- per the joke that any
 *   complaint triggers hosting again -- print "vai ter duas!"
 *   ("there will be two!"). The output strings stay in Portuguese
 *   exactly as given in the statement.
 *
 * Input (multi-case, EOF-terminated):
 *   Each line contains a single integer N (0 <= N <= 100).
 *
 * Output (per case):
 *   "vai ter copa!"  when N == 0
 *   "vai ter duas!"  otherwise
 *
 * Approach:
 *   Read each N until EOF, pick the matching string, print it.
 *
 * Complexity:
 *   O(1) per test case. Trivial.
 */

#include <cstdio>

int main() {
    int n;
    // EOF-terminated: scanf returns 1 while a number was read, 0 on
    // malformed input, and EOF (negative) when the stream is exhausted.
    while (scanf("%d", &n) == 1) {
        // The two output strings are Portuguese idioms straight from
        // the problem statement -- do not translate or "fix" them.
        if (n == 0) {
            puts("vai ter copa!");
        } else {
            puts("vai ter duas!");
        }
    }
    return 0;
}

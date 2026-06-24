/*
 * Beecrowd 1865 — Mjolnir
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   In Norse mythology only Thor is worthy of lifting Mjolnir, the hammer
 *   of the thunder god, and the amount of force a challenger applies is
 *   irrelevant. Given a list of attempts (each a first name and a force
 *   in Newtons), print 'Y' for an attempt by Thor and 'N' for any other
 *   challenger. The sample is decisive: Thor with only 50 N succeeds,
 *   while Hulk with 5000 N fails -- the force input is a red herring.
 *
 * Input:
 *   Line 1: an integer C, the number of test cases (also given as a
 *           plain integer per the problem statement).
 *   Next C lines: a name (one word) and an integer N (1 <= N <= 25000),
 *           separated by a space.
 *
 * Output (per case):
 *   A single character on its own line: 'Y' if the name is exactly
 *   "Thor", 'N' otherwise.
 *
 * Approach:
 *   Read the count, then read C pairs and compare the name to "Thor".
 *   The integer is read but unused -- the lift outcome is name-based.
 *
 * Complexity:
 *   O(C) trivial pass.
 */

#include <cstdio>
#include <cstring>

int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        char name[64];
        int force;
        scanf("%s %d", name, &force);
        // Force is read to consume the token but plays no role in the
        // outcome -- only Thor is worthy, irrespective of how much
        // effort anyone else puts in.
        (void) force;
        puts(strcmp(name, "Thor") == 0 ? "Y" : "N");
    }
    return 0;
}

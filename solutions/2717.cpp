/*
 * Beecrowd 2717 — Elf Time
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   With N minutes left before the workday ends, elf Ed still has two
 *   gifts to make, taking A and B minutes respectively. Decide whether
 *   he can finish both before time runs out. He manages if the combined
 *   time A + B does not exceed N.
 *
 * Input:
 *   One or more test cases until end-of-file. Each case has an integer N
 *   (2 <= N <= 100), then two integers A and B (1 <= A, B <= 100).
 *
 * Output:
 *   For each case, "Farei hoje!" if A + B <= N, otherwise
 *   "Deixa para amanha!".
 *
 * Approach:
 *   Pure comparison: sum the two manufacturing times and check it against
 *   the available minutes. The boundary is inclusive (A + B == N still
 *   fits), as shown by the 10 + 10 vs 20 sample. Loop until EOF so any
 *   number of test cases is handled.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <cstdio>

int main() {
    int n, a, b;

    // Read test cases until end-of-file.
    while (scanf("%d %d %d", &n, &a, &b) == 3) {
        // Inclusive bound: finishing exactly at the deadline counts as
        // doing it today. Output strings are the exact ASCII (no accent)
        // forms shown in the problem's sample output.
        if (a + b <= n) printf("Farei hoje!\n");
        else            printf("Deixa para amanha!\n");
    }

    return 0;
}

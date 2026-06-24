/*
 * Beecrowd 2709 — The Coins of Robbie
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Robbie has a stack of M coins V_1, V_2, ..., V_M (V_M is the top
 *   of the stack). Gloria picks a "jump" N and they sum the coins
 *       V_M + V_{M - N} + V_{M - 2N} + ...
 *   stopping when the next 1-based index would drop below 1. If the
 *   total is prime, Gloria wins; otherwise she loses. For each test
 *   case print one of two fixed sentences accordingly.
 *
 * Input (multiple test cases, EOF-terminated):
 *   - Line 1: M  (2 <= M <= 20)
 *   - Next M lines: V_i  (1 <= V_i <= 500)
 *   - Last line: N  (1 <= N <= M)
 *
 * Output (per test case):
 *   - If the sum is prime:
 *       "You're a coastal aircraft, Robbie, a large silver aircraft."
 *   - Otherwise:
 *       "Bad boy! I'll hit you."
 *
 * Approach:
 *   The maximum possible sum is 20 * 500 = 10000, so a plain trial-
 *   division primality test up to sqrt(sum) is more than fast enough.
 *   Walk index from M downward in steps of N, accumulating V[idx],
 *   then decide which sentence to print.
 *
 * Complexity:
 *   O(M + sqrt(sum)) per test case -- bounded by ~120 operations.
 */

#include <bits/stdc++.h>
using namespace std;

// Trial division up to sqrt(n). sum <= 10000 so this is trivial.
static bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    int M;
    while (scanf("%d", &M) == 1) {
        vector<int> V(M + 1);
        for (int i = 1; i <= M; i++) {
            scanf("%d", &V[i]);
        }
        int N;
        scanf("%d", &N);

        // Sum V[M], V[M-N], V[M-2N], ... while the 1-based index is
        // still in range. With N >= 1 and M >= 2 the loop always runs
        // at least once.
        int sum = 0;
        for (int idx = M; idx >= 1; idx -= N) {
            sum += V[idx];
        }

        // Beecrowd's reference output uses the typographic right single
        // quotation mark (U+2019) instead of the ASCII apostrophe, so
        // the strings must be emitted byte-for-byte that way.
        if (isPrime(sum)) {
            puts("You\xe2\x80\x99re a coastal aircraft, Robbie, a large silver aircraft.");
        } else {
            puts("Bad boy! I\xe2\x80\x99ll hit you.");
        }
    }
    return 0;
}

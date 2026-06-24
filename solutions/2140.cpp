/*
 * Beecrowd 2140 — Two Bills
 *
 * A vendor can only give change as the sum of two bills of *different*
 * denominations, taken from {2, 5, 10, 20, 50, 100}. For each query with a buy
 * price N and a paid amount M, decide whether the change M - N can be formed
 * by exactly two distinct-denomination bills.
 *
 * Input:
 *   Pairs of integers N and M (N < M <= 10^4), one pair per line, until the
 *   terminating line "0 0".
 *
 * Output:
 *   "possible" if the change equals the sum of two different bills, otherwise
 *   "impossible".
 *
 * Approach:
 *   The change is M - N. Try every unordered pair of distinct denominations
 *   (15 pairs) and check whether any of them sums to the change. With only six
 *   bills the brute-force double loop is effectively constant time.
 *
 * Complexity:
 *   O(B^2) per query with B = 6 bills — constant time.
 */

#include <cstdio>

int main() {
    const int bills[] = {2, 5, 10, 20, 50, 100};
    const int B = 6;

    int n, m;
    // Read pairs until the sentinel "0 0".
    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
        int change = m - n;

        bool ok = false;
        // Combine every two DIFFERENT denominations (i < j) and test the sum.
        for (int i = 0; i < B && !ok; ++i)
            for (int j = i + 1; j < B && !ok; ++j)
                if (bills[i] + bills[j] == change)
                    ok = true;

        puts(ok ? "possible" : "impossible");
    }

    return 0;
}

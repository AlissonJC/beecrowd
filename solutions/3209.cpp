/*
 * Beecrowd 3209 — Electrical Outlets
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Roy's apartment has exactly one wall outlet. He owns K power strips,
 *   where the i-th strip provides O_i sockets but requires one socket to
 *   be powered. Find the maximum number of appliances that can run at
 *   the same time when all strips are chained off the single wall outlet.
 *
 *   Each strip is a net gain of (O_i - 1) sockets: it consumes one and
 *   exposes O_i. Starting with the wall socket and adding every strip
 *   gives the closed-form
 *       total = 1 + sum(O_i) - K.
 *   The condition O_i >= 2 guarantees every strip has positive net gain,
 *   so there is never a reason to leave a strip unplugged.
 *
 * Input:
 *   Line 1: N (1 <= N <= 20) -- number of test cases.
 *   Next N lines: each starts with K (1 <= K <= 10), followed by K
 *   integers O_1 ... O_K (2 <= O_i <= 10), separated by spaces.
 *
 * Output:
 *   One integer per line: the maximum number of appliances.
 *
 * Approach:
 *   Read K and accumulate the sum of socket counts; the answer is
 *   1 + sum - K.
 *
 * Complexity:
 *   O(K) per test case.
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int k;
        scanf("%d", &k);
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            int o;
            scanf("%d", &o);
            sum += o;
        }
        // Closed form: 1 wall outlet plus net gain (O_i - 1) per strip.
        printf("%lld\n", 1 + sum - k);
    }
    return 0;
}

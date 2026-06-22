/*
 * Beecrowd 2779 — Album of the Cup
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A sticker album has N numbered slots (1..N) that each need exactly
 *   one sticker. The buyer has acquired M stickers in random order; the
 *   same sticker may appear multiple times. Count how many distinct
 *   sticker numbers are still MISSING from the album.
 *
 * Input:
 *   Line 1: N (1 <= N <= 100) -- total slots / sticker types.
 *   Line 2: M (1 <= M <= 300) -- number of stickers already purchased.
 *   Next M lines: each contains one integer X (1 <= X <= N) -- a
 *   sticker that was bought.
 *
 * Output:
 *   A single integer: N minus the number of distinct sticker IDs in
 *   the M purchases.
 *
 * Approach:
 *   Mark each purchased sticker in a boolean array indexed 1..N. Then
 *   count slots whose flag is still false. With N <= 100 and M <= 300
 *   this is the simplest and fastest formulation.
 *
 * Complexity:
 *   O(N + M) time, O(N) space.
 */

#include <cstdio>
#include <cstring>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // owned[i] = true once sticker number i has been purchased at least
    // once. Duplicate purchases simply leave the flag set.
    bool owned[101] = {false};
    for (int k = 0; k < m; k++) {
        int x;
        scanf("%d", &x);
        owned[x] = true;
    }

    // Count slots that remain false -- those are the ones still
    // missing from the album.
    int missing = 0;
    for (int i = 1; i <= n; i++) {
        if (!owned[i]) missing++;
    }

    printf("%d\n", missing);
    return 0;
}

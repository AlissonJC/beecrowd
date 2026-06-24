/*
 * Beecrowd 1973 — Star Trek
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   N farms (Stars) are arranged in a line and start with X[i] sheep
 *   each. A thief starts at Star 1. When he passes Star i he steals
 *   one sheep (if any) and moves to Star i+1 if X[i] (before the
 *   theft) was odd, or to Star i-1 if it was even. The trek halts as
 *   soon as he tries to step off either end of the line. Print the
 *   number of distinct stars attacked (he stole at least one sheep
 *   from), and the total count of sheep he failed to steal.
 *
 * Constraints:
 *   1 <= N <= 10^6
 *   1 <= X[i] <= 10^6     (so sum(X) can reach ~10^12, use long long)
 *
 * Key observation (closed-form, no simulation):
 *   Parity controls direction. Stealing flips parity, so the direction
 *   at each star alternates between consecutive visits. Tracing the
 *   walk:
 *
 *     - Outbound: while every X[i] he meets is odd, he keeps going
 *       right, stealing one per farm. He stops moving right the first
 *       time he meets an even count.
 *
 *     - Turnaround: at the first even-count farm (call it i), he
 *       steals one and turns left. Every farm to his left (indices
 *       1..i-1) was originally odd, so after one theft those farms
 *       are now even. On the way back he therefore goes left at every
 *       single farm, monotonically, with no bouncing.
 *
 *     - Final step: at farm 1 his current X[1] = X[1]_initial - 1 is
 *       even, so he heads left into nothing and halts.
 *
 *   So the entire walk consists of i forward steals plus one extra
 *   steal at every j in [1, i-1] whose initial X[j] >= 3 (if X[j]_init
 *   was 1, the farm is empty by the time he gets back, so he just
 *   walks through without stealing).
 *
 *   Cases:
 *     a) No even count exists ............... attacked = N,  stolen = N
 *     b) First even at index 1 .............. attacked = 1,  stolen = 1
 *     c) First even at index i > 1 .......... attacked = i,
 *                                             stolen = i + #{j < i : X[j] >= 3}
 *
 *   Non-stolen sheep is sum(X) - stolen.
 *
 * Complexity:
 *   O(N) time, O(N) extra memory (just to store the array; everything
 *   else is a single linear scan).
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<long long> X(N + 1);
    long long sum = 0;
    int firstEven = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &X[i]);
        sum += X[i];
        if (firstEven == -1 && (X[i] % 2 == 0)) firstEven = i;
    }

    long long attacked, stolen;
    if (firstEven == -1) {
        // All counts odd -- thief walks right off the end after N steals.
        attacked = N;
        stolen   = N;
    } else if (firstEven == 1) {
        // First farm already even -- one steal then immediately exits left.
        attacked = 1;
        stolen   = 1;
    } else {
        // One steal each on the way out (1..firstEven) and one extra steal
        // on the way back at every farm in [1, firstEven-1] that still has
        // a sheep to give (its initial odd value was at least 3).
        attacked = firstEven;
        stolen   = firstEven;
        for (int j = 1; j < firstEven; j++) {
            if (X[j] >= 3) stolen++;
        }
    }

    long long nonStolen = sum - stolen;
    printf("%lld %lld\n", attacked, nonStolen);
    return 0;
}

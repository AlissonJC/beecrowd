/*
 * Beecrowd 3348 — Game of Spiders
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   In a circle of 2N spiders, positions 1..N hold harmless spiders and
 *   positions N+1..2N hold venomous (recluse) spiders. Starting from
 *   position 1, every K-th still-living spider is eliminated, repeated
 *   N times. Print any positive K (< 10^16) for which all N eliminated
 *   spiders are recluse. N is given, 1 <= N <= 19.
 *
 * Construction (no search needed):
 *   Let K be a multiple of every integer r in {1, 2, ..., 2N}. The
 *   smallest such K is L = lcm(1, 2, ..., 2N), and for N <= 19 we have
 *   L = lcm(1..38) = 5,342,931,457,063,200 < 10^16, which fits in a
 *   64-bit integer comfortably.
 *
 *   With K divisible by every r, at every step the modular offset
 *   K mod r is zero. Treating an offset of zero as "skip a full lap"
 *   means the counter walks once around the surviving spiders and
 *   lands on the position immediately BEFORE the previous kill (within
 *   the alive subset). Starting "before" position 1, the first kill is
 *   position 2N, the second is 2N-1, and so on down to N+1. Every kill
 *   sits in [N+1, 2N], i.e. is a recluse, so Merlin wins.
 *
 * Why this works:
 *   "Walking r alive positions when r spiders are alive" visits every
 *   surviving spider exactly once, ending at the one immediately
 *   preceding the current pointer in the live circle. After the first
 *   kill (position 2N), the pointer sits at 2N's slot; one full lap of
 *   the 2N-1 survivors ends at 2N-1 (the next-counterclockwise alive
 *   position). Inductively the i-th kill is at 2N-i+1, which is
 *   recluse for all i = 1..N.
 *
 * Complexity:
 *   O(N) -- compute the LCM with iterated gcd.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    // Build lcm(1..2N) progressively, dividing before multiplying to
    // keep the intermediate value small (and well below 2^63).
    long long lcm = 1;
    for (long long i = 2; i <= 2LL * N; i++) {
        lcm = lcm / __gcd(lcm, i) * i;
    }
    printf("%lld\n", lcm);
    return 0;
}

/*
 * Beecrowd 1541 — Building Houses
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Mr Pi wants to build a house of dimensions A x B square meters, but
 *   the local zoning rule allows the house to cover at most C percent of
 *   the land. The land must be square. Given A, B and C, print the side
 *   of the smallest such square land, TRUNCATED to an integer (per the
 *   problem statement -- even when the resulting square is slightly
 *   smaller than the strict mathematical requirement, e.g. 3 m for an
 *   ideal 3.163 m side).
 *
 *   Mathematically the constraint is
 *       A * B  <=  (C / 100) * L^2
 *   which rearranges to  L >= sqrt(A * B * 100 / C). The answer is
 *   floor(L), i.e., floor(sqrt(A * B * 100 / C)).
 *
 * Input (multi-case, terminated by a lone 0):
 *   Each test case is one line with three positive integers A, B, C
 *   (1 <= A, B, C <= 1000), space-separated. A single integer 0 on its
 *   own line marks the end of input.
 *
 * Output (per case):
 *   One integer on its own line -- the truncated land side.
 *
 * Approach:
 *   Treat the threshold purely in integer arithmetic to avoid losing
 *   precision near integer square boundaries: we want the largest L
 *   with  L^2 * C  <=  A * B * 100. Seed L with the floating-point
 *   sqrt, then do at most a couple of correction steps in each
 *   direction. With A, B, C <= 1000 the largest L^2 * C is 10^4 * 10^4
 *   * 10^3 = 10^11, well inside long long range.
 *
 * Complexity:
 *   O(1) per test case (constant correction loops). Trivial.
 */

#include <cstdio>
#include <cmath>

int main() {
    int A, B, C;
    // Read the first number of each case; a lone 0 terminates the stream.
    while (scanf("%d", &A) == 1 && A != 0) {
        scanf("%d %d", &B, &C);

        // target = A * B * 100 in integer form. Required L satisfies
        // L^2 * C <= target. With bounds at 1000 each, target stays
        // under 10^8, but L^2 * C can reach 10^11, so use long long.
        long long target = (long long) A * B * 100;

        // Initial guess from double sqrt; floor it via cast. Floating
        // point may be off by one in either direction near perfect
        // squares, so correct with two tight while loops below.
        long long L = (long long) std::sqrt((double) target / C);

        // Push L up while a larger candidate still fits.
        while ((L + 1) * (L + 1) * C <= target) {
            L++;
        }
        // Pull L down while it overshoots. L cannot go negative because
        // L = 0 trivially satisfies 0 * C <= target whenever target >= 0.
        while (L > 0 && L * L * C > target) {
            L--;
        }

        printf("%lld\n", L);
    }
    return 0;
}

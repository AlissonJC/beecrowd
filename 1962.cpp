/*
 * Beecrowd 1962 — A Long, Long Time Ago
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   For each integer T given, T is the number of years that have passed
 *   from a historical event until the reference year 2015 AD. Print the
 *   calendar year in which the event happened, tagged with "D.C."
 *   (Depois de Cristo = AD) or "A.C." (Antes de Cristo = BC) according
 *   to the Portuguese abbreviations the statement uses.
 *
 *   Key gotcha: there is no year zero. The year right before 1 AD is
 *   1 BC. So when 2015 - T becomes 0, that maps to 1 A.C. -- and more
 *   generally, when 2015 - T is k <= 0, the answer is (1 - k) A.C.
 *
 * Input:
 *   Line 1: N (1 <= N <= 100000).
 *   Next N lines: one non-negative integer T with 0 <= T < 2^31.
 *
 * Output (per case):
 *   "<year> D.C."  if the event lies in 1 AD or later
 *   "<year> A.C."  otherwise (year >= 1, no year zero)
 *
 * Approach:
 *   For each T compute year = 2015 - T using long long to avoid the
 *   signed-overflow boundary at 2^31. Branch on whether year is >= 1
 *   (AD) or <= 0 (BC, with the off-by-one shift 1 - year). Use plain
 *   stdio since the workload is at most 1e5 lines.
 *
 * Complexity:
 *   O(N) time, O(1) memory beyond I/O buffers.
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        long long T;
        scanf("%lld", &T);
        // 64-bit subtraction safely handles T up to 2^31 - 1.
        long long year = 2015 - T;
        if (year >= 1) {
            // 1 AD onwards.
            printf("%lld D.C.\n", year);
        } else {
            // year <= 0 covers both year-zero (which the calendar skips)
            // and any negative result; the BC year is (1 - year).
            printf("%lld A.C.\n", 1 - year);
        }
    }
    return 0;
}

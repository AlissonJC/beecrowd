/*
 * Beecrowd 1023 — Drought
 *
 * For each test case, a city has N properties. Property i has X residents and
 * total monthly consumption Y (cubic meters). For every city we must:
 *   1) Group residents by their per-person consumption floor(Y / X).
 *   2) Print the groups in ascending order of that per-person value, in the
 *      format "<total residents>-<consumption>".
 *   3) Print the average consumption per inhabitant of the whole city,
 *      truncated (NOT rounded) to two decimals.
 *
 * Input format:
 *   - Multiple test cases. Each starts with N (1 <= N <= 1e6).
 *   - The next N lines have X (1 <= X <= 10) and Y (1 <= Y <= 200).
 *   - Input ends with N = 0.
 *
 * Output format:
 *   - "Cidade# k:" with k = 1, 2, 3, ...
 *   - The groups separated by single spaces on one line.
 *   - "Consumo medio: A.BB m3." truncated to two decimals.
 *   - A blank line between two consecutive cases; none after the last.
 *
 * Approach:
 *   Per-person consumption is at most 200 (since Y <= 200, X >= 1), and the
 *   "rounding down" instruction means integer division. We keep a fixed
 *   bucket array cnt[0..200] indexed by floor(Y/X) accumulating the total
 *   number of residents that fall into each bucket. Sweeping 0..200 yields
 *   the groups already sorted ascending. The city average is the exact
 *   sum of all Y divided by the exact sum of all X, truncated to 2 decimals
 *   by computing (sumY * 100) / sumX with integer arithmetic.
 *
 * Complexity:
 *   Time  O(N + 201) per case — linear in the number of properties.
 *   Space O(1) extra (a 201-slot bucket array).
 *
 * Data sizes / overflow note:
 *   sumX can reach 1e6 * 10 = 1e7 (fits in int but use long long for safety).
 *   sumY can reach 1e6 * 200 = 2e8, and sumY * 100 reaches 2e10 — must use
 *   64-bit integers when computing the truncated average.
 */

#include <cstdio>

int main() {
    int n;
    int caseNum = 0;

    // We print a blank line BEFORE every case except the first, so the final
    // case ends cleanly with no trailing blank line.
    bool firstCase = true;

    while (scanf("%d", &n) == 1 && n != 0) {
        if (!firstCase) putchar('\n');
        firstCase = false;
        ++caseNum;

        // cnt[c] = total number of residents whose per-person consumption
        // (floor of Y/X) equals c. Range of c is [0, 200].
        int cnt[201] = {0};

        // 64-bit accumulators: sumY * 100 can reach 2e10, beyond 32-bit range.
        long long sumX = 0, sumY = 0;

        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);

            // Integer division equals floor(Y / X) for non-negative values,
            // which is exactly the "rounding down" required by the statement.
            cnt[y / x] += x;
            sumX += x;
            sumY += y;
        }

        printf("Cidade# %d:\n", caseNum);

        // Sweep buckets in ascending order. Only buckets with at least one
        // resident are printed. Groups are space-separated on a single line.
        bool firstGroup = true;
        for (int c = 0; c <= 200; ++c) {
            if (cnt[c] > 0) {
                if (!firstGroup) putchar(' ');
                printf("%d-%d", cnt[c], c);
                firstGroup = false;
            }
        }
        putchar('\n');

        // Truncated (not rounded) average to 2 decimals. We multiply first
        // to keep two extra digits of precision, then split integer / fractional.
        // Example: sumY=186, sumX=14 -> 18600/14 = 1328 -> "13.28".
        long long avgScaled = (sumY * 100) / sumX;

        // Output line uses the Portuguese label "Consumo medio" from the
        // problem statement — kept verbatim. Trailing period and "m3." too.
        printf("Consumo medio: %lld.%02lld m3.\n",
               avgScaled / 100, avgScaled % 100);
    }

    return 0;
}

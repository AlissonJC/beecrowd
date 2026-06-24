/*
 * Beecrowd 1090 — Set
 *
 * Each card has two characteristics: a NUMBER ("um", "dois", "tres" = 1, 2, 3
 * figures) and a FIGURE type ("circulo", "quadrado", "triangulo"). There are
 * 9 possible card types. Three cards form a Set when, FOR EACH of the two
 * characteristics, the three values are either all equal or all different.
 *
 * Given a multiset of N cards on the table, find the maximum number of
 * disjoint Sets that can be formed.
 *
 * Input format:
 *   - Multiple test cases. Each begins with an integer N (3 ≤ N ≤ 3 * 10^4).
 *   - The next N lines describe one card each: "<number-word> <figure-word>".
 *     number-word ∈ {"um", "dois", "tres"};
 *     figure-word ∈ {"circulo", "circulos", "quadrado", "quadrados",
 *                    "triangulo", "triangulos"} (singular/plural varies).
 *   - End of input: a line containing only "0".
 *
 * Output: one integer per test case — the maximum number of disjoint Sets.
 *
 * ------------------------------------------------------------------------
 *  THE MATH BEHIND IT
 * ------------------------------------------------------------------------
 *
 * Encode every card by an index 3*n + f where n,f ∈ {0,1,2}. The 9 indices
 * are exactly the points of the affine plane AG(2,3). The Set definition —
 * "in every coordinate, all-equal or all-different" — is precisely the
 * definition of a LINE in AG(2,3). AG(2,3) has 12 such lines, organized
 * into 4 parallel classes of 3 lines each:
 *   - same number, different figures (3 lines)         "horizontal"
 *   - different numbers, same figure  (3 lines)        "vertical"
 *   - direction (1, 1)                (3 lines)        "diagonal"
 *   - direction (1, 2)                (3 lines)        "anti-diagonal"
 *
 * Beyond these 12 line-shaped Sets, three identical cards also count as a
 * valid Set, giving 9 additional "triple-same" candidate Sets — one per
 * card type. Twenty-one candidate kinds in total.
 *
 * Variables of the optimization:
 *   s_c = number of triple-same Sets formed for card c        (s_c ≥ 0)
 *   x_l = number of line-Sets formed for line l               (x_l ≥ 0)
 *
 * Constraint per card c (cannot use more than we have):
 *   3 * s_c + Σ_{l ∋ c} x_l ≤ count[c].
 *
 * Define the residual (unused cards of type c):
 *   r_c = count[c] − 3 * s_c − Σ_{l ∋ c} x_l    (≥ 0).
 *
 * Summing the per-card identity over all 9 cards and using that every line
 * contributes 1 to exactly 3 cards:
 *   N = 3 * Σ_c s_c + 3 * Σ_l x_l + Σ_c r_c
 *     = 3 * (total Sets) + Σ_c r_c
 *   ⇒  total Sets = (N − Σ_c r_c) / 3.
 *
 * So MAXIMIZING the number of Sets is equivalent to MINIMIZING Σ r_c.
 * At an optimum r_c ∈ {0, 1, 2}: otherwise we could bump s_c by 1.
 *
 * ------------------------------------------------------------------------
 *  REDUCTION TO A 3^12 SEARCH
 * ------------------------------------------------------------------------
 *
 * The residual r_c depends on Σ_{l ∋ c} x_l only MODULO 3. Moreover, any
 * x_l ≥ 3 can be traded for (x_l − 3) plus +1 to s_c on each of the line's
 * three points — keeping the total Sets identical. So without loss of
 * generality we may restrict every x_l to {0, 1, 2}. Write y_l := x_l.
 *
 * Feasibility then becomes simply:
 *   Σ_{l ∋ c} y_l ≤ count[c]   for every card c.
 *
 * That leaves a brute-force search over {0,1,2}^12 = 3^12 = 531 441 tuples.
 * For each tuple we check the 9 feasibility inequalities and compute
 * Σ_c ((count[c] − Σ_{l ∋ c} y_l) mod 3), tracking the minimum.
 *
 * Complexity per test case: O(3^12 · 9) ≈ 5 · 10^6 ops — fast in C++.
 * Memory: a handful of small fixed-size arrays.
 */

#include <cstdio>
#include <climits>

/*
 * The 12 lines of AG(2,3), grouped by parallel class.
 * Each line lists the 3 card indices (= 3*n + f) it covers.
 *
 *   L0  L1  L2  : "horizontal" — same number, varying figure
 *   L3  L4  L5  : "vertical"   — same figure, varying number
 *   L6  L7  L8  : direction (1, 1) diagonals
 *   L9  L10 L11 : direction (1, 2) diagonals
 *
 * Within each parallel class the 3 lines partition the 9 cards, so every
 * card lies on exactly 4 lines (one per parallel class).
 */
static const int LINES_ARR[12][3] = {
    {0,1,2}, {3,4,5}, {6,7,8},
    {0,3,6}, {1,4,7}, {2,5,8},
    {0,4,8}, {1,5,6}, {2,3,7},
    {0,5,7}, {1,3,8}, {2,4,6}
};

int main() {
    /*
     * Build the reverse index: for each card c, list the 4 line indices
     * that contain c. Computed once outside the test-case loop.
     */
    int lines_through[9][4];
    {
        int nlt[9] = {0};
        for (int l = 0; l < 12; ++l)
            for (int j = 0; j < 3; ++j) {
                int c = LINES_ARR[l][j];
                lines_through[c][nlt[c]++] = l;
            }
    }

    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        // Count occurrences of each of the 9 card types.
        int count[9] = {0};
        for (int i = 0; i < n; ++i) {
            char w1[16], w2[16];
            scanf("%15s %15s", w1, w2);
            // Disambiguate by first letter — Portuguese keywords don't collide
            // within their own slot: number ∈ {"um","dois","tres"} (u, d, t),
            // figure ∈ {"circulo[s]","quadrado[s]","triangulo[s]"} (c, q, t).
            int num = (w1[0] == 'u') ? 0 : (w1[0] == 'd') ? 1 : 2;
            int fig = (w2[0] == 'c') ? 0 : (w2[0] == 'q') ? 1 : 2;
            ++count[3 * num + fig];
        }

        /*
         * Brute-force enumeration of y ∈ {0,1,2}^12 as a base-3 counter.
         * We process the all-zero assignment first (always feasible),
         * which guarantees best_r is set after the very first iteration.
         */
        int best_r = INT_MAX;
        int y[12] = {0};
        const int TOTAL = 531441;   // 3^12

        for (int t = 0; t < TOTAL; ++t) {
            bool feasible = true;
            int total_r = 0;
            for (int c = 0; c < 9; ++c) {
                int s = y[lines_through[c][0]] + y[lines_through[c][1]]
                      + y[lines_through[c][2]] + y[lines_through[c][3]];
                // If Σ y_l through c exceeds count[c], not enough cards exist
                // to realize this line-Set assignment — discard.
                if (s > count[c]) { feasible = false; break; }
                total_r += (count[c] - s) % 3;
            }
            if (feasible && total_r < best_r) {
                best_r = total_r;
                // Σ r_c = 0 is the absolute minimum; nothing better is possible.
                if (best_r == 0) break;
            }

            // Increment y as a little-endian base-3 counter.
            for (int l = 0; l < 12; ++l) {
                if (++y[l] < 3) break;
                y[l] = 0;
            }
        }

        // total Sets = (N − Σ r_c) / 3, which is always a non-negative integer
        // because N ≡ Σ r_c (mod 3) by construction.
        printf("%d\n", (n - best_r) / 3);
    }
    return 0;
}

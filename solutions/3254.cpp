/*
 * Beecrowd 3254 — Private Space (NCPC 2011)
 *
 * Groups go to the cinema and want privacy: groups in the same row must be
 * separated by at least one empty seat, except at the ends of the row. The
 * cinema has rows whose widths form the sequence X, X-1, X-2, ..., 1 (so
 * there are X rows total, summing to X(X+1)/2 seats). The widest row may
 * not exceed 12 seats. Find the smallest X such that every group can be
 * seated; if no X in [1..12] works, print "impossible".
 *
 * Input:
 *   Line 1: n  (1 ≤ n ≤ 12) — size of the largest group present.
 *   Line 2: N_1 N_2 ... N_n  where N_i = number of groups of i persons.
 *
 * Output:
 *   A single integer X — the smallest valid widest-row width — or the
 *   lowercase word "impossible".
 *
 * Reduction.
 *   A row of R seats holding k groups whose sizes sum to s is valid iff
 *       s + (k - 1) ≤ R,
 *   which rewrites as
 *       sum(g_i + 1) ≤ R + 1.
 *   So treating each group of size g as a virtual item of size g + 1 and
 *   each row of R seats as a virtual bin of capacity R + 1 turns the
 *   problem into ordinary bin packing.
 *
 * Approach.
 *   Try X = max(largest_group, 1), then X+1, ..., up to 12. For each X run
 *   a row-by-row backtracking from the widest row (X) down to the narrowest
 *   (1). At each row we enumerate every multiset of remaining groups that
 *   fits in that row, then recurse on the next-smaller row. The subproblem
 *   only depends on (current_row, remaining_counts), so we memoise on that
 *   key — this is what kills the exponential blow-up that arises when one
 *   packs item-by-item with many identical groups.
 *
 *   Three pre-filters skip X values that are clearly hopeless without ever
 *   entering the search:
 *     1. Total people > X(X+1)/2 — not enough physical seats.
 *     2. Total virtual size > (X+1)(X+2)/2 - 1 — not enough virtual cap.
 *     3. For any size g, N_g exceeds the maximum number of size-g groups
 *        that X rows can host: sum_{r=1..X} floor((r+1)/(g+1)).
 *
 * Complexity.
 *   Bin packing is NP-hard in general, but with at most 12 rows, group
 *   sizes ≤ 12, and total virtual capacity ≤ 90, the memoised row-by-row
 *   search visits very few unique (row, counts) states on every realistic
 *   input and finishes well within the 1-second limit.
 */

#include <bits/stdc++.h>
using namespace std;

// Ncount[g] = original number of groups of size g (read from input).
// counts[g] = currently remaining groups of size g during the search.
static int Ncount[13];
static int counts[13];

// Memoise on (current row index, counts[1..12]) — 14 bytes total. Each
// count fits in a byte because the largest feasible value is 42 (the maximum
// number of size-1 groups across all 12 rows).
static unordered_map<string, bool> memo;

static inline string encodeState(int row) {
    string s(14, '\0');
    s[0] = static_cast<char>(static_cast<unsigned char>(row));
    for (int g = 1; g <= 12; g++) {
        s[g] = static_cast<char>(static_cast<unsigned char>(counts[g]));
    }
    return s;
}

static bool fillRow(int row);

// Decide how many of each remaining group size to place in the current row.
// Iterate sizes from largest (12) down to smallest (1). For each size g we
// place k items (0 ≤ k ≤ maxK), then recurse to the next size; once every
// size has been considered we descend to the next row. Iterating k from
// maxK downwards is a greedy ordering — for feasible inputs we find a
// packing quickly without changing correctness for infeasible inputs.
static bool tryFill(int row, int g, int virtualLeft) {
    if (g < 1) {
        return fillRow(row - 1);
    }
    // Each size-g item costs (g + 1) virtual units, so at most
    // virtualLeft / (g + 1) items of this size fit alongside whatever has
    // already been placed in the row.
    int maxK = min(counts[g], virtualLeft / (g + 1));
    for (int k = maxK; k >= 0; k--) {
        counts[g] -= k;
        if (tryFill(row, g - 1, virtualLeft - k * (g + 1))) {
            counts[g] += k;
            return true;
        }
        counts[g] += k;
    }
    return false;
}

// Attempt to fit all remaining groups into rows of capacities row, row-1, ..., 1.
// Memoised: the same (row, counts) pair is only explored once across the
// whole search, which prevents the per-item permutation blow-up.
static bool fillRow(int row) {
    if (row == 0) {
        for (int g = 1; g <= 12; g++) {
            if (counts[g] > 0) return false;
        }
        return true;
    }
    string key = encodeState(row);
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;

    // Row r holds groups whose virtual sizes sum to at most r + 1.
    bool result = tryFill(row, 12, row + 1);
    memo[key] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int largest = 0;
    long long totalReal = 0, totalGroups = 0;
    for (int i = 1; i <= n; i++) {
        long long Ni;
        cin >> Ni;
        // The judge does not bound N_i. The largest feasible count of any
        // single size for X = 12 is 42; anything beyond that guarantees
        // infeasibility, so we clamp to keep arithmetic tidy. (We still
        // detect this via the pre-checks below.)
        if (Ni > 100) Ni = 100;
        Ncount[i] = static_cast<int>(Ni);
        if (Ni > 0) largest = i;
        totalReal += Ni * i;
        totalGroups += Ni;
    }

    // Groups larger than 12 can never fit any row (rows top out at 12 seats).
    // Total virtual capacity across all 12 rows is 90, total real seats is 78
    // — exceeding either bound is immediately impossible.
    if (largest > 12 || totalReal + totalGroups > 90 || totalReal > 78) {
        cout << "impossible\n";
        return 0;
    }

    int minX = max(1, largest);
    for (int X = minX; X <= 12; X++) {
        // Physical seat capacity check.
        if (totalReal > (long long)X * (X + 1) / 2) continue;
        // Virtual capacity check (people + groups ≤ (X+1)(X+2)/2 - 1).
        if (totalReal + totalGroups > (long long)(X + 1) * (X + 2) / 2 - 1) continue;
        // Per-size capacity check: for each size g, sum over rows of the
        // maximum number of size-g groups a single row can host is an
        // upper bound on how many can be placed in total. This catches
        // pathological "many identical small groups" inputs without ever
        // entering the search.
        bool perSizeOK = true;
        for (int g = 1; g <= 12 && perSizeOK; g++) {
            if (Ncount[g] == 0) continue;
            long long maxFit = 0;
            for (int r = 1; r <= X; r++) maxFit += (r + 1) / (g + 1);
            if (Ncount[g] > maxFit) perSizeOK = false;
        }
        if (!perSizeOK) continue;

        // Reset working state and the memo for this X, then search.
        for (int g = 1; g <= 12; g++) counts[g] = Ncount[g];
        memo.clear();
        if (fillRow(X)) {
            cout << X << "\n";
            return 0;
        }
    }

    cout << "impossible\n";
    return 0;
}

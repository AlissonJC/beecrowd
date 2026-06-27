/*
 * Beecrowd 3204 - Honeycomb Walk
 *
 * A bee larva sits in one hexagonal cell of a honeycomb. Each step it moves to
 * one of the six adjacent cells. Count how many distinct walks of exactly n
 * steps bring it back to its starting cell.
 *
 * The centers of the honeycomb's hexagonal cells form a triangular lattice in
 * which every cell has six neighbors. In axial coordinates those neighbors are
 * (+1,0), (-1,0), (0,+1), (0,-1), (+1,-1) and (-1,+1) -- three pairs of
 * opposite directions. A length-n closed walk is a sequence of n such moves
 * summing to (0,0), so the count is the number of n-step walks from the origin
 * that end at the origin.
 *
 * Input : first line is the number of test cases; each case is one integer n
 *         (1 <= n <= 14). Under that bound the answer is below 2^31.
 * Output: for each case, one line with the number of closed walks of length n.
 *
 * Approach: Dynamic programming over board positions. Spread a counter from the
 * origin one step at a time; after k steps, the value sitting on the origin is
 * exactly the number of length-k closed walks. Precompute these for all k up to
 * 14 in a single sweep, then answer each query in O(1).
 *
 * Complexity: precompute O(MAX_N * grid) = O(14 * 29^2 * 6); O(1) per query.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int MAX_N = 14;
    const int OFF = MAX_N;            // shift so the origin sits at index OFF
    const int D = 2 * MAX_N + 1;      // grid side length (covers |coord| <= 14)

    // Six axial neighbor offsets of a hexagonal cell.
    const int dq[6] = {+1, -1, 0, 0, +1, -1};
    const int dr[6] = {0, 0, +1, -1, -1, +1};

    static long long cur[D][D], nxt[D][D];
    long long f[MAX_N + 1];

    // Step 0: the bee is at the origin in exactly one (empty) way.
    for (int i = 0; i < D; ++i)
        for (int j = 0; j < D; ++j)
            cur[i][j] = 0;
    cur[OFF][OFF] = 1;
    f[0] = 1;

    for (int step = 1; step <= MAX_N; ++step) {
        for (int i = 0; i < D; ++i)
            for (int j = 0; j < D; ++j)
                nxt[i][j] = 0;

        // Push each cell's walk-count into its six neighbors.
        for (int q = 0; q < D; ++q) {
            for (int r = 0; r < D; ++r) {
                if (cur[q][r] == 0) continue;
                for (int d = 0; d < 6; ++d) {
                    int nq = q + dq[d], nr = r + dr[d];
                    if (nq >= 0 && nq < D && nr >= 0 && nr < D)
                        nxt[nq][nr] += cur[q][r];
                }
            }
        }

        for (int i = 0; i < D; ++i)
            for (int j = 0; j < D; ++j)
                cur[i][j] = nxt[i][j];

        // Walks of length `step` that returned to the starting cell.
        f[step] = cur[OFF][OFF];
    }

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << f[n] << "\n";
    }

    return 0;
}

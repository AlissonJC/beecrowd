/*
 * Beecrowd 1827 - Square Array IV
 *
 * For each odd integer N read (5 <= N <= 101) print an N x N grid built from five
 * overlapping regions: the outer area is 0, an inner square is 1, the main
 * diagonal is 2, the secondary diagonal is 3, and the central element is 4.
 *
 * The inner square of 1s starts at index s = N / 3 (integer division) and, by the
 * symmetry of the figure, ends at N - 1 - s, spanning [s, N-1-s] in both axes. For
 * N = 5 that square is rows/cols 1..3; for N = 11 it is rows/cols 3..7.
 *
 * Input:  several odd integers N, one per line, until EOF.
 * Output: for each N the N x N grid (rows of digits, no separators), followed by a
 *         blank line after every test case.
 *
 * Precedence is the crux. A cell may satisfy several rules at once, and the
 * samples fix the order: the inner square wins over the diagonals (e.g. for N = 11
 * cell (3,3) lies on the main diagonal yet prints 1, not 2). So each cell is
 * resolved top-down as:
 *     1) the exact center (N/2, N/2)            -> 4
 *     2) inside the inner square [s, N-1-s]^2   -> 1
 *     3) on the main diagonal      (i == j)     -> 2   (only reachable outside
 *     4) on the secondary diagonal (i+j == N-1) -> 3    the inner square)
 *     5) everything else                        -> 0
 * Because N is odd the two diagonals meet only at the center, which rule 1 already
 * handles, so the 2-before-3 order never actually matters.
 *
 * Approach: a direct double loop applying the precedence above; no matrix storage.
 *
 * Complexity: O(N^2) per test case, O(1) extra space.
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // EOF-terminated input.
    while (cin >> n) {
        int s = n / 3;          // inner square's starting index (per the obs)
        int lo = s;             // inner square spans [lo, hi] on both axes
        int hi = n - 1 - s;     // symmetric upper bound
        int c = n / 2;          // center index (n is odd, so this is exact)

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch;
                if (i == c && j == c)
                    ch = '4';                                   // central element
                else if (i >= lo && i <= hi && j >= lo && j <= hi)
                    ch = '1';                                   // inner square wins
                else if (i == j)                                // over the diagonals
                    ch = '2';                                   // main diagonal (outer)
                else if (i + j == n - 1)
                    ch = '3';                                   // secondary diagonal
                else
                    ch = '0';                                   // outer area
                cout << ch;
            }
            cout << '\n';
        }
        // A blank line follows every test case, including the last one.
        cout << '\n';
    }
    return 0;
}

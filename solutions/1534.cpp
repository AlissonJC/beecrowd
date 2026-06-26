/*
 * Beecrowd 1534 - Array 123
 *
 * For each integer N read (3 <= N < 70) print an N x N grid filled with the
 * digits 1, 2 and 3 following the pattern shown in the examples: the main
 * diagonal carries 1s, the anti-diagonal carries 2s, and every other cell
 * carries 3. For example, N = 4 produces
 *     1332
 *     3123
 *     3213
 *     2331
 *
 * Input:  many test cases, one integer N per line, until EOF.
 * Output: for each N, the N x N grid; each row is N digits with no separators,
 *         and no blank line is printed between consecutive grids.
 *
 * Key detail: when N is odd the central cell (N/2, N/2) lies on BOTH diagonals.
 * The samples show that cell as 2 (see N = 7, whose middle row is 3332333), so
 * the anti-diagonal test must be evaluated before the main-diagonal test - the
 * 2 wins over the 1 on the shared cell.
 *
 * Approach: a direct double loop. For each cell decide its digit by checking the
 * anti-diagonal (i + j == N - 1) first, then the main diagonal (i == j), then
 * defaulting to 3.
 *
 * Complexity: O(N^2) per test case, O(1) extra space.
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // EOF-terminated input: keep reading orders until the stream runs out.
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                if (i + j == n - 1)       // anti-diagonal -> 2 (checked first so
                    c = '2';              // it wins on the odd-N center cell)
                else if (i == j)          // main diagonal -> 1
                    c = '1';
                else                      // everything else -> 3
                    c = '3';
                cout << c;
            }
            cout << '\n';
        }
        // No blank line between grids: the next grid follows immediately.
    }
    return 0;
}

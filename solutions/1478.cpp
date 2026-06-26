/*
 * Beecrowd 1478 - Square Matrix II
 *
 * Read several integers N (0 <= N <= 100), each the order of a square matrix,
 * and print each matrix following the pattern shown in the examples. Input ends
 * at N = 0 (the terminator is not printed).
 *
 * The pattern: the value at cell (i, j) is |i - j| + 1. The main diagonal is all
 * 1s and the values increase by one for every step away from that diagonal, e.g.
 *     1 2 3
 *     2 1 2
 *     3 2 1
 *
 * Input:  a sequence of integers, one per line, terminated by 0.
 * Output: for each N, the N x N matrix. Each value is right-justified in a field
 *         of width 3, consecutive values are separated by a single space, and no
 *         space follows the last value of a row. A blank line is printed after
 *         each matrix.
 *
 * Constraints: N <= 100, so the largest value is |99 - 0| + 1 = 100, which has
 * three digits and fits exactly in the width-3 field. A 32-bit int suffices.
 *
 * Approach: a direct double loop computing |i - j| + 1 for every cell. The only
 * subtlety is the spacing: emit the separating space *before* every element
 * except the first, which guarantees no trailing space at the end of a row.
 *
 * Complexity: O(N^2) per matrix, O(1) extra space.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Sentinel-terminated input: stop as soon as N = 0 is read.
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Separator goes before each element except the first, so the
                // row never ends with a trailing space.
                if (j > 0)
                    cout << ' ';
                // Width-3, right-justified field per the output specification.
                cout << setw(3) << (abs(i - j) + 1);
            }
            cout << '\n';
        }
        // A blank line is required after every matrix.
        cout << '\n';
    }
    return 0;
}

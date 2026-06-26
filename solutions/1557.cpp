/*
 * Beecrowd 1557 - Square Matrix III
 *
 * Read several integers N (0 <= N <= 15), each the order of a square matrix, and
 * print each matrix following the pattern in the examples. Input ends at N = 0
 * (the terminator is not printed).
 *
 * The pattern: the value at cell (i, j) is 2^(i + j). The top-left cell is 1 and
 * every step to the right or down doubles the value, e.g. for N = 3:
 *     1  2  4
 *     2  4  8
 *     4  8 16
 *
 * Input:  a sequence of integers, one per line, terminated by 0.
 * Output: for each N, the N x N matrix. Every value is right-justified in a field
 *         of width T, where T is the number of digits of the largest value in the
 *         matrix (the bottom-right cell, 2^(2N-2)). Consecutive values are
 *         separated by a single space, no space follows the last value of a row,
 *         and a blank line is printed after each matrix.
 *
 * Constraints: N <= 15, so the largest value is 2^(2*14) = 2^28 = 268435456,
 * which fits in a 32-bit int; long long is used purely as a safety margin.
 *
 * Approach: for each matrix, the biggest entry is the bottom-right corner, so the
 * field width T is the digit count of 2^(2(N-1)). Then a direct double loop emits
 * 2^(i+j) (computed with a bit shift) right-justified in width T. The separating
 * space is printed before every element except the first to avoid a trailing
 * space.
 *
 * Complexity: O(N^2) per matrix, O(1) extra space.
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Sentinel-terminated input: stop as soon as N = 0 is read.
    while (cin >> n && n != 0) {
        // Largest value sits in the bottom-right corner: 2^((n-1)+(n-1)).
        // Its digit count is the common field width T for the whole matrix.
        long long biggest = 1LL << (2 * (n - 1));
        int T = (int)to_string(biggest).size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Separator before every element except the first -> no trailing
                // space at the end of the row.
                if (j > 0)
                    cout << ' ';
                // Value 2^(i+j) right-justified in the width-T field.
                cout << setw(T) << (1LL << (i + j));
            }
            cout << '\n';
        }
        // A blank line is required after every matrix.
        cout << '\n';
    }
    return 0;
}

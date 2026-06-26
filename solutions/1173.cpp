/*
 * Beecrowd 1173 - Array fill I
 *
 * Read an integer V and fill an array N[10] such that the first position holds
 * V and every subsequent position holds double the previous one. For V = 1 the
 * array is 1, 2, 4, 8, 16, ... Print every position of the array.
 *
 * Input:  a single integer V (V < 50).
 * Output: for each position i (0..9) print a line "N[i] = X" where X is the
 *         value stored at that position.
 *
 * Approach: keep a running value starting at V and double it after printing
 * each of the 10 positions. No real array storage is needed since each value
 * is produced and printed in sequence. Values stay tiny (at most 49 * 2^9 =
 * 25088 in magnitude), so a 32-bit int holds them comfortably.
 *
 * Complexity: O(10) time, O(1) extra space.
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int value;
    cin >> value;

    for (int i = 0; i < 10; i++) {
        // Exact output format from the statement: "N[i] = X" with single
        // spaces around the '=' sign.
        cout << "N[" << i << "] = " << value << '\n';

        // Each next position stores double the current value.
        value *= 2;
    }
    return 0;
}

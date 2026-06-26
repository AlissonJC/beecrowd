/*
 * Beecrowd 1177 - Array Fill II
 *
 * Read an integer T and fill a vector N[1000] with the numbers 0 to T-1
 * repeated over and over. For T = 3 the array cycles 0, 1, 2, 0, 1, 2, ...
 * across all 1000 positions. Print every position of the array.
 *
 * Input:  a single integer T (2 <= T <= 50).
 * Output: for each position i (0..999) print a line "N[i] = x" where x is the
 *         value stored at that position.
 *
 * Approach: the value at position i is simply i mod T, since taking i modulo T
 * produces the repeating cycle 0, 1, ..., T-1. Print each of the 1000 positions
 * directly without building an array.
 *
 * Complexity: O(1000) time, O(1) extra space.
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < 1000; i++) {
        // i mod t yields the repeating pattern 0, 1, ..., t-1.
        // Exact output format from the statement: "N[i] = x".
        cout << "N[" << i << "] = " << i % t << '\n';
    }
    return 0;
}

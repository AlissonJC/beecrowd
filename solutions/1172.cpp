/*
 * Beecrowd 1172 - Array Replacement I
 *
 * Read an array X with 10 integers. Every element that is null (zero) or
 * negative must be replaced by 1; positive elements stay unchanged. Then print
 * every position of the array.
 *
 * Input:  10 integers, one per line, each possibly positive or negative.
 * Output: for each position i (0..9) print a line "X[i] = x" where x is the
 *         value stored at that position after the replacement.
 *
 * Approach: a single linear pass over the 10 values. While reading each value,
 * clamp anything <= 0 up to 1, then print it in the required format. No array
 * actually needs to be stored, since each value is processed and printed
 * immediately, but the problem is phrased in terms of an array X[10].
 *
 * Complexity: O(10) time, O(1) extra space.
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;

        // "null or negative" means anything <= 0 becomes 1; positives stay.
        if (x <= 0)
            x = 1;

        // Exact output format from the statement: "X[i] = x" with single
        // spaces around the '=' sign.
        cout << "X[" << i << "] = " << x << '\n';
    }
    return 0;
}

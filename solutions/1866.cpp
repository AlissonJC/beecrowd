/*
 * Beecrowd 1866 - Bill
 *
 * Evaluate the alternating sum S = 1 - 1 + 1 - 1 + 1 - 1 + ... using exactly N
 * terms, where the signs alternate starting with +1. Each consecutive pair
 * (+1 - 1) cancels to 0, so the whole sum collapses to: 0 when N is even and 1
 * when N is odd. Therefore S is simply the parity of N, i.e. N % 2.
 *
 * Input : an integer C, the number of test cases. Each test case is a single
 *         integer N (1 <= N <= 1000), the number of terms in the sum.
 * Output: for each test case, the value of S on its own line.
 *
 * Approach: print N % 2 for every test case. No need to build the sum.
 * Complexity: O(C) time, O(1) space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;                 // number of test cases
    while (c--) {
        int n;
        cin >> n;
        // Pairs (+1 -1) cancel; only an odd count leaves a leftover +1.
        cout << (n % 2) << "\n";
    }

    return 0;
}

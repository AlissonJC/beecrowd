/*
 * Beecrowd 2867 - Digits
 *
 * For each pair (N, M), report how many decimal digits N^M has.
 *
 * Input : C test cases; each a line with N and M (1 <= N, M <= 100).
 * Output: the number of digits of N^M, one per test case.
 *
 * Approach: N^M can be as large as 100^100 = 10^200 (201 digits), so the
 *   floor(M*log10(N)) + 1 formula is unsafe -- at exact powers of ten (e.g.
 *   100^100) floating error can flip the floor. Instead compute the powers
 *   exactly with simple big-number multiplication. Since N and M only range up to
 *   100, precompute the digit count of N^M for every pair once (each N built
 *   incrementally by repeated multiplication) and answer each query in O(1).
 *
 * Complexity: O(100 * 100 * digits) ~ 2e6 precomputation, O(1) per query.
 */

#include <bits/stdc++.h>
using namespace std;

static int digitsOf[101][101];   // digitsOf[n][m] = number of digits of n^m

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 1; n <= 100; ++n) {
        vector<int> num = {1};                       // n^0, least significant digit first
        for (int m = 1; m <= 100; ++m) {
            int carry = 0;                           // multiply the big number by n
            for (size_t j = 0; j < num.size(); ++j) {
                int p = num[j] * n + carry;
                num[j] = p % 10;
                carry = p / 10;
            }
            while (carry) { num.push_back(carry % 10); carry /= 10; }
            digitsOf[n][m] = (int)num.size();         // n^m now built
        }
    }

    int c;
    if (!(cin >> c)) return 0;
    while (c--) {
        int n, m;
        cin >> n >> m;
        cout << digitsOf[n][m] << "\n";
    }
    return 0;
}

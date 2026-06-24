/*
 * Beecrowd 2846 - Fibonot
 *
 * The Fibonot sequence is the positive integers that are NOT Fibonacci numbers,
 * listed in ascending order: 4, 6, 7, 9, 10, 11, 12, 14, 15, ... Given K, output
 * the K-th Fibonot number.
 *
 * Input : a single integer K (1 <= K <= 1e5). (Read until EOF to be safe.)
 * Output: the K-th term of the Fibonot sequence.
 *
 * Approach: Fibonacci numbers are very sparse (only ~25 below 1e5), so the K-th
 *   non-Fibonacci number is at most about 1e5 + 25. Mark every Fibonacci value in
 *   a boolean table, then sweep the positive integers once collecting the first
 *   1e5 that are not marked. Each query is then an O(1) array lookup.
 *
 * Complexity: O(1e5) precomputation, O(1) per query.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int LIM = 200000;                       // safely above the largest answer
    vector<bool> isFib(LIM + 1, false);
    isFib[1] = true;
    for (long long a = 1, b = 2; a <= LIM; ) {    // mark 1,2,3,5,8,... up to LIM
        isFib[(int)a] = true;
        long long c = a + b; a = b; b = c;
    }

    // First 1e5 non-Fibonacci numbers, in order.
    vector<int> fibonot;
    fibonot.reserve(100000);
    for (int i = 1; (int)fibonot.size() < 100000; ++i)
        if (!isFib[i]) fibonot.push_back(i);

    int k;
    while (cin >> k) cout << fibonot[k - 1] << "\n";
    return 0;
}

/*
 * Beecrowd 3076 - History Exercise
 *
 * Given a year, report which century it belongs to. Century 1 spans years
 * 1..100, century 2 spans 101..200, and so on.
 *
 * Input : several test cases, one integer N per line (1 <= N <= 1e9), until EOF.
 * Output: the century of each year, one per line.
 *
 * Approach: the century of year N is ceil(N / 100), computed with integer math
 *   as (N + 99) / 100.
 *
 * Complexity: O(1) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n)
        cout << (n + 99) / 100 << "\n";       // ceil(N / 100)
    return 0;
}

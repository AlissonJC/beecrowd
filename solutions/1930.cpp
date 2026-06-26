/*
 * Beecrowd 1930 - Electrical Outlet
 *
 * A hotel room has a single wall power outlet. The team has four power strips,
 * the i-th having Ti sockets. Plugging a strip into an available socket consumes
 * one socket but provides Ti new ones, so the net gain of a strip is (Ti - 1).
 * Find the maximum number of devices that can be powered at the same time.
 *
 * Input : one line with four integers T1 T2 T3 T4 (2 <= Ti <= 6).
 * Output: a single integer, the maximum number of simultaneously powered devices.
 *
 * Approach: start with 1 free socket (the wall). Each strip adds (Ti - 1) free
 * sockets, and since Ti >= 2 every strip yields a strictly positive gain, so it
 * is always worth connecting all four. The final number of free sockets equals
 * 1 + sum(Ti - 1) = (T1 + T2 + T3 + T4) - 3, which is the answer.
 *
 * Complexity: O(1) time and space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t1, t2, t3, t4;
    cin >> t1 >> t2 >> t3 >> t4;

    // Wall socket (1) plus each strip's net contribution (Ti - 1), four strips:
    // 1 + (T1-1)+(T2-1)+(T3-1)+(T4-1) = sum - 3.
    cout << (t1 + t2 + t3 + t4 - 3) << "\n";

    return 0;
}

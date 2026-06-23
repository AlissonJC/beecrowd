/*
 * Beecrowd 2845 - Party at the North Pole
 *
 * The host leprechaun H writes the identifiers of every leprechaun whose number
 * is smaller than H and coprime to H (i.e. all of H's totatives). Given that
 * list, recover H.
 *
 * Input : N (1 <= N <= 1e4); then N integers A_i (1 <= A_i <= 1e5), the listed
 *         identifiers (all coprime to H and less than H).
 * Output: the host's number H.
 *
 * Approach: H-1 is always coprime to H (gcd(H-1, H) = 1), so it is the largest
 *   number smaller than H that is coprime to it. Therefore the largest value in
 *   the list is exactly H-1, and the answer is max(A_i) + 1.
 *
 * Complexity: O(N) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mx = max(mx, x);     // largest totative listed = H - 1
        }
        cout << mx + 1 << "\n";  // hence H
    }
    return 0;
}

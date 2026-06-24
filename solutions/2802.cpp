/*
 * Beecrowd 2802 - Dividing Circles
 *
 * Put N points on a circle and draw every chord between pairs of points, with no
 * three chords meeting at a single interior point. Determine how many regions
 * these chords cut the disk into.
 *
 * Input : a single integer N (1 <= N <= 1000).
 * Output: the number of regions of the circle.
 *
 * Approach: by Euler's formula for the planar graph of points and chord
 *   crossings, the count of regions is the well-known closed form
 *       R(N) = 1 + C(N,2) + C(N,4),
 *   where C(N,2) counts the chords and C(N,4) counts the interior crossings
 *   (each crossing comes from a unique set of 4 points). Just evaluate it. The
 *   first five values 1,2,4,8,16 look like powers of two but R(6)=31 already
 *   breaks that pattern, which is exactly what the formula gives.
 *
 * Overflow: C(1000,4) ~ 4.1e10 exceeds 32 bits, so compute with long long.
 *
 * Complexity: O(1).
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    while (cin >> n) {
        ll chords    = (n >= 2) ? n * (n - 1) / 2 : 0;                       // C(N,2)
        ll crossings = (n >= 4) ? n * (n - 1) * (n - 2) * (n - 3) / 24 : 0;  // C(N,4)
        cout << (1 + chords + crossings) << "\n";
    }
    return 0;
}

/*
 * Beecrowd 3235 - Luggage
 *
 * Pieces of luggage ride a straight belt at a constant speed v and drop, one by
 * one, onto a circular belt of length L that moves at 1 m/s. Once a bag lands it
 * also moves at 1 m/s, so the relative positions of any two bags on the circular
 * belt are frozen the moment the later one lands. Two bags collide if they ever
 * sit within one meter of each other (circular distance < 1). Given the bag
 * positions x_i on the straight belt, find the maximum v in [0.1, 10] that keeps
 * every pair at circular distance >= 1, or report "no fika" if none exists.
 *
 * Input : "N L" (1 <= N <= L <= 1000), then N unique positions x_i (0 <= x_i <=
 *         1000, two decimals). Read until end of file.
 * Output: the maximum speed (absolute error <= 1e-9 accepted) or "no fika".
 *
 * Model
 * -----
 * Bag i reaches the drop point at a time proportional to x_i / v, and the belt
 * coordinate where it lands is that time taken mod L. So for a pair (i, j) the
 * circular separation is (D / v) mod L with D = |x_i - x_j|. No collision means
 * (D / v) mod L lies in [1, L - 1], i.e. D / v must stay at least 1 away from
 * every multiple of L (and be >= 1).
 *
 * As a function of v this is allowed exactly when D / v is in some closed band
 * [kL + 1, (k+1)L - 1]; the gaps (kL - 1, kL + 1) are forbidden, which in v are
 * the open intervals (D/(kL+1), D/(kL-1)). The k = 0 gap forces v <= D, so the
 * overall cap is hi = min(D_min, 10); above hi the closest pair already collides.
 *
 * Answer = largest v <= hi outside every forbidden band: hi itself if hi is not
 * covered, otherwise the left edge of the maximal union of forbidden bands that
 * contains hi (that left edge is an allowed boundary D/(kL+1)). If that edge
 * drops below 0.1 the whole legal range is blocked -> "no fika".
 *
 * Bands are bounded by N <= L: each pair spawns ~10D/L of them, summing to a few
 * million, so generate, sort, and merge. The guarantee that [v - 1e-9, v] is
 * also valid means the optimum is never a zero-width pinch, so a plain strict
 * overlap test merges correctly.
 *
 * Complexity: O(B log B) per case with B = total bands (a few million worst).
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long L;
    while (cin >> N >> L) {
        // Read positions in centimeters so the two-decimal values stay exact.
        vector<long long> x(N);
        for (int i = 0; i < N; ++i) {
            double t;
            cin >> t;
            x[i] = llround(t * 100.0);
        }

        // A single bag never collides with anything: any speed works, take 10.
        if (N == 1) {
            printf("%.12g\n", 10.0);
            continue;
        }

        // Minimum pairwise distance = smallest gap between sorted positions.
        vector<long long> xs(x);
        sort(xs.begin(), xs.end());
        long long DminCm = LLONG_MAX;
        for (int i = 1; i < N; ++i) DminCm = min(DminCm, xs[i] - xs[i - 1]);

        double hi = min(DminCm / 100.0, 10.0);   // upper cap on the speed
        // If even the closest pair forbids every legal speed, give up early.
        if (hi < 0.1 - 1e-12) {
            printf("no fika\n");
            continue;
        }

        // Generate every forbidden band that reaches into (0.1, hi).
        vector<pair<double, double>> bands;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double D = llabs(x[i] - x[j]) / 100.0;
                for (long long k = 1;; ++k) {
                    double he = D / (double)(k * L - 1);   // band right end
                    if (he <= 0.1) break;                  // smaller k cover (0.1,hi]
                    double lo = D / (double)(k * L + 1);   // band left end
                    if (lo < hi) bands.push_back({lo, he}); // ignore bands fully above hi
                }
            }
        }

        // Merge bands and locate the maximal covered chain that contains hi.
        sort(bands.begin(), bands.end());
        bool hiCovered = false;
        double chainLeft = 0.0;
        bool have = false;
        double curLo = 0.0, curHi = 0.0;
        for (auto &b : bands) {
            if (!have) {
                curLo = b.first; curHi = b.second; have = true;
            } else if (b.first < curHi) {           // strict overlap -> extend chain
                if (b.second > curHi) curHi = b.second;
            } else {                                 // gap -> close current chain
                if (curLo < hi && hi < curHi) { hiCovered = true; chainLeft = curLo; }
                curLo = b.first; curHi = b.second;
            }
        }
        if (have && curLo < hi && hi < curHi) { hiCovered = true; chainLeft = curLo; }

        // Beecrowd compares the output text tightly: it expects the reference
        // formatting of 12 significant digits with trailing zeros stripped
        // (e.g. "0.344444444444", "0.2", "2"), i.e. printf's %g, not %f.
        if (!hiCovered) {
            printf("%.12g\n", hi);                  // hi itself is collision-free
        } else if (chainLeft >= 0.1 - 1e-12) {
            printf("%.12g\n", chainLeft);           // top of the allowed band below hi
        } else {
            printf("no fika\n");                    // legal range entirely blocked
        }
    }
    return 0;
}

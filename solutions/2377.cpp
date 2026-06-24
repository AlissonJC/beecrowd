/*
 * Beecrowd 2377 - "Pedagio" (Toll)
 * OBI 2010, Phase 1, Level 1
 *
 * A driver travels a highway of length L kilometers. The trip has two costs:
 *   1. A per-kilometer cost K, charged for every kilometer of the road -> L * K.
 *   2. A toll fee P, paid at each toll booth. Booths are equally spaced every
 *      D kilometers, starting at kilometer D (positions D, 2D, 3D, ...). The
 *      start of the road has no booth, but the END counts if it lands exactly
 *      on a booth. Example from the statement: L = 111, D = 37 -> booths at
 *      37, 74 and 111, so 3 tolls are paid.
 *
 * Therefore the number of booths passed is floor(L / D). For positive integers
 * this is exactly C++ integer division (L / D): it floors, it includes a booth
 * sitting on the final kilometer, and it yields 0 when D > L (no tolls at all).
 *
 * Input : line 1 -> L D   (1 <= L, D <= 10^4)  length and spacing between tolls
 *         line 2 -> K P   (1 <= K, P <= 10^4)  cost per km and price of a toll
 * Output: a single integer, the total trip cost, followed by a newline.
 *
 * Approach  : closed-form arithmetic, total = L*K + (L/D)*P.
 * Complexity: O(1) time, O(1) space.
 *
 * Note on types: the maximum total is about 10^4*10^4 + 10^4*10^4 = 2*10^8,
 * which already fits in a 32-bit int; long long is used here purely as a safe
 * default for any product/sum so overflow can never be a concern.
 */

#include <iostream>
using namespace std;

int main() {
    long long L, D, K, P;
    // The two lines are read with the same stream extractions: >> skips any
    // whitespace (spaces and the newline between the lines) automatically.
    cin >> L >> D >> K >> P;

    // Cost of driving every kilometer of the road.
    long long distanceCost = L * K;

    // Number of toll booths passed = floor(L / D). Integer division handles the
    // endpoint booth (e.g. 111/37 = 3) and the "no booths" case (e.g. 20/70 = 0).
    long long tollCost = (L / D) * P;

    // Single integer answer; trailing '\n' avoids Presentation Error on Beecrowd.
    cout << (distanceCost + tollCost) << "\n";
    return 0;
}

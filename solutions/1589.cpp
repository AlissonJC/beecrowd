/*
 * Beecrowd 1589 - Bob Conduit
 *
 * Two circular cables have radii R1 and R2. We must find the smallest radius of
 * a circular conduit (a third circle) that circumscribes both cables.
 *
 * Input:  the first line holds T, the number of test cases (T <= 10000). Each of
 *         the following T lines holds two positive integers R1 and R2; the
 *         problem guarantees every value fits in a 32-bit integer.
 * Output: for each test case, the smallest conduit radius on its own line.
 *
 * Geometry: to minimize the enclosing circle, lay the two cables side by side
 * along one diameter of the conduit - externally tangent to each other and each
 * internally tangent to the conduit at opposite ends. The conduit diameter is
 * then 2*R1 + 2*R2, so its radius is simply R1 + R2. This is optimal because two
 * non-overlapping circles cannot be packed tighter than mutual tangency, and any
 * non-collinear arrangement only enlarges the enclosing circle.
 *
 * Approach: read each pair and print R1 + R2.
 *
 * Complexity: O(T) time, O(1) space.
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        // Use 64-bit accumulation as a safety margin even though the statement
        // guarantees the result fits in a 32-bit integer.
        long long r1, r2;
        cin >> r1 >> r2;

        // Smallest circumscribing radius: the two cables tangent along a diameter.
        cout << (r1 + r2) << '\n';
    }
    return 0;
}

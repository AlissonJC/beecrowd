/*
 * Beecrowd 1150 - "Exceeding Z"
 *
 * Read an integer X. Then keep reading values Z until one is strictly
 * greater than X (every Z <= X is discarded). Starting at X and adding the
 * next consecutive integers (X, X+1, X+2, ...), count the minimum amount of
 * terms whose running sum strictly exceeds that valid Z, and print it.
 *
 * Example from the statement: X = 21, the first valid Z is 30. The sum
 * 21 + 22 = 43 already passes 30, so the answer is 2.
 *
 * Input : X on the first line, then one Z per line; ignore Z <= X and read
 *         again until Z > X. Values may be positive or negative.
 * Output: a single line with the count of summed integers.
 *
 * Approach: straightforward simulation. There is no closed form needed -
 * keep adding consecutive integers and stop the moment the partial sum
 * passes Z. Because the terms eventually grow without bound, the loop is
 * guaranteed to terminate even when X is negative (where the partial sum
 * first dips lower before climbing back up).
 *
 * Complexity: O(k) where k is the answer; trivial space. The running sum is
 * kept in a 64-bit integer because it can climb far beyond the 32-bit range
 * before exceeding Z.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, z;
    cin >> x;

    // Read Z as many times as needed: only a value strictly greater than X
    // satisfies the specification; anything <= X is ignored.
    cin >> z;
    while (z <= x) cin >> z;

    // Add consecutive integers starting from X until the sum passes Z.
    long long sum = 0;
    long long term = x;
    int count = 0;
    while (sum <= z) {
        sum += term;   // include the current consecutive integer
        ++term;        // advance to the next integer in the sequence
        ++count;       // one more number was needed
    }

    cout << count << "\n";
    return 0;
}

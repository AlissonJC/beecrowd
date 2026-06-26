/*
 * Beecrowd 1153 - "Simple Factorial"
 *
 * Read a single integer N and print its factorial,
 * N! = N * (N-1) * (N-2) * ... * 1.
 *
 * Input : one integer N, with 0 < N < 13.
 * Output: a single line containing N!.
 *         e.g. N = 4  ->  24
 *
 * Approach: direct iterative product from 1 up to N. With N < 13 the largest
 * result is 12! = 479001600, which still fits in a 32-bit int; a 64-bit
 * accumulator is used anyway as a safe default for products.
 *
 * Complexity: O(N) multiplications, O(1) space.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Multiply every integer from 1 through N to build the factorial.
    long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }

    cout << fact << "\n";
    return 0;
}

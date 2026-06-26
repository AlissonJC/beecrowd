/*
 * Beecrowd 2146 - "Password"
 *
 * Mr. Amnesio writes a number on paper and recovers his password from it via a
 * fixed (forgotten) formula. The task is to reproduce that formula given only
 * the worked examples. Inspecting the samples shows every password is simply
 * the paper number minus one:
 *     1234 -> 1233, 2000 -> 1999, 1001 -> 1000, 9999 -> 9998
 * so the formula is password = N - 1.
 *
 * Input : many test cases, one integer N per line (1001 <= N <= 9999),
 *         terminated by end of file.
 * Output: for each N, print N - 1 on its own line.
 *
 * Approach  : read until EOF and print the predecessor of each number.
 * Complexity: O(1) per test case.
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // EOF-terminated input: loop while an integer can still be read.
    while (cin >> n) {
        // Password is one less than the number on paper (formula from samples).
        cout << n - 1 << "\n";
    }
    return 0;
}

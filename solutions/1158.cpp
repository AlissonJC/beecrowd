/*
 * Beecrowd 1158 - Sum of Consecutive Odd Numbers III
 *
 * For each test case we are given two integers X and Y. We must add up Y
 * consecutive odd numbers, starting at the first odd number that is >= X
 * (X itself counts when X is already odd). For example X=4, Y=5 yields
 * 5 + 7 + 9 + 11 + 13 = 45, and X=7, Y=4 yields 7 + 9 + 11 + 13 = 40.
 *
 * Input:  first line N, the number of test cases; then N lines each with X and Y.
 * Output: one line per test case with the requested sum.
 *
 * Approach: find the first odd term `start` (X if X is odd, otherwise X+1).
 * The Y terms form an arithmetic progression start, start+2, ..., start+2(Y-1).
 * Its sum is Y*start + 2*(0+1+...+(Y-1)) = Y*(start + Y - 1). Closed form, so
 * each test case is answered in O(1) without looping over the Y terms.
 *
 * Complexity: O(N) total, O(1) memory. We use 64-bit integers because the sum
 * Y*(start + Y - 1) can exceed the 32-bit range when X and Y are large.
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        long long x, y;
        cin >> x >> y;

        // First odd number at or after X: keep X when it is already odd,
        // otherwise step up by one to the next odd value.
        long long start = (x % 2 != 0) ? x : x + 1;

        // Sum of the Y-term arithmetic progression with common difference 2.
        long long sum = y * (start + y - 1);

        cout << sum << '\n';
    }
    return 0;
}

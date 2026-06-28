/*
 * Beecrowd 1071 - Sum of Consecutive Odd Numbers I
 *
 * Read two integers X and Y and print the sum of all odd values strictly
 * between them. The two endpoints themselves are excluded, and the order of X
 * and Y is not guaranteed (X may be larger or smaller than Y).
 *
 * Input : two integers X and Y.
 * Output: a single integer, the sum of the odd numbers strictly between them.
 *
 * The "strictly between" reading is fixed by the samples: for 6 and -5 the odds
 * are {-3,-1,1,3,5} summing to 5 (the endpoint -5 is NOT counted, which would
 * make it 0); for 15 and 12 only 13 qualifies (15 is excluded, so not 28).
 *
 * Approach: Normalize to lo = min(X,Y), hi = max(X,Y), then scan the open
 * interval (lo, hi) and add every odd number. In C++ a number is odd exactly
 * when n % 2 != 0, which also holds for negatives (e.g. -3 % 2 == -1).
 *
 * Complexity: O(hi - lo) time, O(1) space. The accumulator is 64-bit so partial
 * sums never overflow, even though the final result is stated to fit in an int.
 */

#include <iostream>
#include <algorithm>

int main() {
    int x, y;
    std::cin >> x >> y;

    // Work from the smaller to the larger value so the input order is irrelevant.
    int lo = std::min(x, y);
    int hi = std::max(x, y);

    long long sum = 0;
    // Open interval (lo, hi): start one past lo and stop one before hi.
    for (int i = lo + 1; i < hi; ++i) {
        // n % 2 != 0 detects odd numbers for both positive and negative n.
        if (i % 2 != 0) {
            sum += i;
        }
    }

    std::cout << sum << "\n";
    return 0;
}

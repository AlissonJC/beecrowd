/*
 * Beecrowd 1028 - Collectable Cards
 *
 * Two players hold F1 and F2 cards and must split them into stacks all of the
 * same size, as large as possible for both players. A common stack size has to
 * divide both F1 and F2, so the largest possible stack is exactly gcd(F1, F2).
 *
 * Input : first line N (1 <= N <= 3000) test cases; then N lines each with two
 *         integers F1 and F2 (1 <= F1, F2 <= 1000).
 * Output: the maximum common stack size (gcd) for each test case, one per line.
 *
 * Complexity: O(log(min(F1, F2))) per test case for the gcd.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        int f1, f2;
        if (scanf("%d %d", &f1, &f2) != 2) break;
        printf("%d\n", __gcd(f1, f2));   // largest stack dividing both hands
    }
    return 0;
}

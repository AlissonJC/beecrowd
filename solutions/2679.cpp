/*
 * Beecrowd 2679 — Even Successor
 *
 * Given a number X, print the smallest even number strictly greater than X.
 *
 * Input:
 *   A single integer X with 0 < X < 10^7.
 *
 * Output:
 *   A single line with the smallest even number greater than X.
 *
 * Approach:
 *   Round X down to the nearest even value (X - X % 2), then add 2. This is
 *   the first even number strictly above X regardless of X's parity:
 *     - X odd : X - 1 + 2 = X + 1
 *     - X even: X - 0 + 2 = X + 2
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <cstdio>

int main() {
    int x;
    if (scanf("%d", &x) != 1) return 0;  // guard against malformed/empty input

    // Step down to the nearest even number <= X, then move up by 2 to land on
    // the first even value strictly greater than X.
    int answer = x - (x % 2) + 2;

    printf("%d\n", answer);
    return 0;
}

/*
 * Beecrowd 1019 - Time Conversion
 *
 * Read a duration given in seconds and express it as hours:minutes:seconds.
 *
 * Input : a single integer N, the duration in seconds.
 * Output: the duration formatted as "h:m:s" (hours, minutes and seconds
 *         separated by colons), followed by a trailing newline. The components
 *         are NOT zero-padded -- the sample prints "0:9:16", not "00:09:16".
 *
 * Approach: standard base-60 decomposition. There are 3600 seconds in an hour
 *           and 60 in a minute, so the hours are N / 3600; the leftover seconds
 *           N % 3600 split into (that / 60) minutes and (that % 60) seconds.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int hours = n / 3600;            // whole hours
    int rest = n % 3600;             // seconds left after removing the hours
    int minutes = rest / 60;         // whole minutes in the remainder
    int seconds = rest % 60;         // leftover seconds

    // Print with plain %d (no leading zeros) to match the sample format.
    printf("%d:%d:%d\n", hours, minutes, seconds);
    return 0;
}

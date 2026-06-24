/*
 * Beecrowd 2003 — Sunday Morning
 *
 * Bino and his friend Cino agree to meet at the Parangaba bus terminal at
 * 8:00 every Sunday. Bino wakes up at a given time H and then needs between
 * 30 and 60 minutes to travel to the terminal. We must report the *maximum*
 * delay: how many minutes after 8:00 Bino arrives in the worst case, which
 * happens when the trip takes the longest possible time, 60 minutes.
 *
 * Input:
 *   Multiple test cases until EOF. Each line holds a wake-up time H in the
 *   "h:mm" format, with 5:00 <= H <= 9:00.
 *
 * Output:
 *   For each case, print "Atraso maximo: X" where X is the maximum delay in
 *   minutes. If even the slowest trip still gets Bino to the terminal by
 *   8:00, there is no delay and X is 0.
 *
 * Approach:
 *   Convert H to minutes-since-midnight, add the worst-case travel of 60
 *   minutes, and compare against 8:00 (= 480 minutes). The delay is the
 *   non-negative difference: max(0, H + 60 - 480).
 *
 * Complexity:
 *   O(1) time and space per test case.
 */

#include <cstdio>
#include <algorithm>

int main() {
    int h, m;

    // Read "h:mm" pairs until EOF. scanf returns the count of items matched,
    // so it yields 2 on a well-formed line and stops (!= 2) when input ends.
    while (scanf("%d:%d", &h, &m) == 2) {
        int wake = h * 60 + m;          // wake-up time in minutes since midnight
        int latestArrival = wake + 60;  // worst-case trip takes the full 60 min

        // Meeting is at 8:00 = 480 minutes. A negative difference means Bino
        // still arrives on time even in the worst case, so clamp it to 0.
        int delay = std::max(0, latestArrival - 480);

        // Output text is Portuguese per the statement — keep it verbatim.
        printf("Atraso maximo: %d\n", delay);
    }

    return 0;
}

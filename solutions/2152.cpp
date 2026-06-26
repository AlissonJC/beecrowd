/*
 * Beecrowd 2152 - "Pepe, I Already Took the Candle!"
 *
 * A door-sensor log stores each event as three integers: the hour, the minute,
 * and a flag. Convert each raw record into a human-readable line stating the
 * time and whether the door opened or closed.
 *
 * Input : line 1 -> T, the number of records. Then T lines, each with three
 *         integers H M O: hour, minute, and the door flag (0 = closed, any
 *         non-zero value = opened).
 * Output: per record -> "HH:MM - <phrase>", where HH and MM are padded to two
 *         digits (e.g. 0 5 -> "00:05") and <phrase> is the Portuguese
 *         "A porta abriu!" when the door opened or "A porta fechou!" when it
 *         closed. The phrases are printed verbatim, exclamation mark included.
 *
 * Approach  : read each record and print it with two-digit, zero-padded time;
 *             pick the phrase from the flag (0 -> closed, else opened).
 * Complexity: O(T) time, O(1) space.
 */

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int h, m, o;
        cin >> h >> m >> o;

        // %02d zero-pads hour/minute to two digits so 0:5 prints as "00:05".
        // Flag 0 means the door closed ("fechou"); any other value means it
        // opened ("abriu"). Phrases stay in Portuguese exactly as required.
        const char *phrase = (o == 0) ? "A porta fechou!" : "A porta abriu!";
        printf("%02d:%02d - %s\n", h, m, phrase);
    }
    return 0;
}

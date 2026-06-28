/*
 * Beecrowd 1046 - Game Time
 *
 * Read the start and end hour of a game (whole hours, 0..23). The game may
 * start on one day and finish on the next, with a maximum duration of 24 hours.
 * Print how long it lasted as "O JOGO DUROU X HORA(S)".
 *
 * Input : two integers, the start hour and the end hour, on one line.
 * Output: "O JOGO DUROU X HORA(S)" where X is the duration in hours.
 *         The message is in Portuguese and uppercase, exactly as the sample.
 *
 * Approach: The naive difference end - start is correct only when the game ends
 * later the same day. If it is zero or negative, the game crossed midnight, so
 * add 24 to wrap into the next day. Using "<= 0" (not "< 0") is deliberate: when
 * start == end the game ran a full day, which must report 24, not 0.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    int start, end;
    scanf("%d %d", &start, &end);

    int duration = end - start;
    // Non-positive difference means the game finished on the following day
    // (start == end is the full-24h case, handled by the "<= 0" condition).
    if (duration <= 0) {
        duration += 24;
    }

    // Portuguese, uppercase message reproduced verbatim from the statement.
    printf("O JOGO DUROU %d HORA(S)\n", duration);
    return 0;
}

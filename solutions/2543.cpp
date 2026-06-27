/*
 * Beecrowd 2543 — UFPR Gaming
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A web page publishes gameplay videos. Each video lists its author's
 *   university ID and a flag for the game: 0 for Contra-Strike (CS), 1
 *   for Liga de Legendas (LOL). Given your own ID, count how many
 *   published videos are of YOU playing Contra-Strike, i.e. authored by
 *   your ID and flagged as CS.
 *
 * Input:
 *   Several test cases until end-of-file. Each test case starts with a
 *   line "N I": N (1 <= N <= 10^4) gameplays and I (1000 <= I <= 9999)
 *   your university ID. The next N lines each have "i j" with i the
 *   author's ID (1000 <= i <= 9999) and j in {0, 1} (0 = CS, 1 = LOL).
 *
 * Output:
 *   For each test case, one line with the count of videos where i == I
 *   and j == 0.
 *
 * Approach:
 *   Straight linear scan. For every video in a test case, increment a
 *   counter when the author matches your ID and the game flag marks CS.
 *   Loop over test cases until scanf can no longer read the header (EOF).
 *
 * Complexity:
 *   O(N) per test case, O(1) extra space.
 */

#include <cstdio>

int main() {
    int n, myId;

    // EOF-terminated: keep going while a "N I" header can be read.
    while (scanf("%d %d", &n, &myId) == 2) {
        int csVideos = 0;  // reset the counter for each test case

        for (int k = 0; k < n; k++) {
            int author, game;
            scanf("%d %d", &author, &game);

            // Count only when the video is authored by you (author == myId)
            // AND it is a Contra-Strike video (game flag == 0).
            if (author == myId && game == 0) csVideos++;
        }

        printf("%d\n", csVideos);
    }

    return 0;
}

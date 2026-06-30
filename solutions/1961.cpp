/*
 * Beecrowd 1961 - Jumping Frog
 *
 * A frog crosses a row of pipes from the leftmost to the rightmost, hopping from
 * each pipe to the next. It survives a hop only when the height difference to the
 * next pipe is at most its jump height P: if the next pipe is too high it hits
 * the pipe, and if it is too low it does not survive the fall. So the stage is
 * beatable exactly when EVERY pair of consecutive pipes differs in height by at
 * most P.
 *
 * Input : line 1 - two integers P and N (1 <= P <= 5, 2 <= N <= 100), the jump
 *         height and the number of pipes. Line 2 - N pipe heights (each <= 10),
 *         left to right.
 * Output: "YOU WIN" if the frog can reach the last pipe, otherwise "GAME OVER".
 *
 * Approach: scan the heights once, comparing each pipe with the previous one. If
 *           any absolute consecutive difference exceeds P the stage is lost. All
 *           N heights are always read (even after a failure is detected) so the
 *           input is fully consumed. The outer read loop simply lets the program
 *           handle one or several stages until end of input.
 *
 * Complexity: O(N) time per stage, O(1) space.
 */
#include <iostream>
#include <cstdlib>  // std::abs for int

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int p, n;
    while (std::cin >> p >> n) {
        int prev;
        std::cin >> prev;

        bool win = true;
        for (int i = 1; i < n; ++i) {
            int cur;
            std::cin >> cur;  // read every height to keep the stream aligned
            if (std::abs(cur - prev) > p) win = false;  // a hop the frog can't make
            prev = cur;
        }

        // Output strings are fixed by the statement - do not alter casing/spacing.
        std::cout << (win ? "YOU WIN" : "GAME OVER") << '\n';
    }

    return 0;
}

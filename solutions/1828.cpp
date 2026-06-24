/*
 * Beecrowd 1828 — Bazinga!
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Sheldon and Raj play the rock-paper-scissors-lizard-Spock variant.
 *   For each round, given Sheldon's and Raj's choices (in Portuguese:
 *   pedra, papel, tesoura, lagarto, Spock), print Sheldon's reaction:
 *       "Bazinga!"        if Sheldon's shape beats Raj's
 *       "Raj trapaceou!"  if Raj's shape beats Sheldon's
 *       "De novo!"        on a tie
 *   The full set of winning pairs (X beats Y) is:
 *       scissors > paper        Spock > scissors
 *       paper > rock            scissors > lizard
 *       rock > lizard           lizard > paper
 *       lizard > Spock          paper > Spock
 *                               Spock > rock
 *                               rock > scissors
 *
 * Input:
 *   Line 1: T (T <= 100).
 *   Next T lines: Sheldon's and Raj's choices separated by a space.
 *
 * Output (per case):
 *   "Caso #t: R" where t is the 1-indexed case number and R is the
 *   Portuguese reaction string above (kept verbatim, do not translate).
 *
 * Approach:
 *   Encode each shape 0..4 and build a 5x5 lookup table beats[x][y].
 *   For each round, compare; tie if equal, otherwise consult the table.
 *
 * Complexity:
 *   O(T) with constant work per case.
 */

#include <cstdio>
#include <cstring>

static int code(const char* s) {
    if (strcmp(s, "pedra") == 0)   return 0;  // rock
    if (strcmp(s, "papel") == 0)   return 1;  // paper
    if (strcmp(s, "tesoura") == 0) return 2;  // scissors
    if (strcmp(s, "lagarto") == 0) return 3;  // lizard
    return 4;                                 // Spock (only remaining option)
}

int main() {
    // beats[x][y] = 1 iff shape x wins against shape y.
    // Each shape beats exactly two others and loses to the other two.
    static int beats[5][5] = {0};
    static const int wins[10][2] = {
        {0, 2}, {0, 3},  // rock beats scissors, lizard
        {1, 0}, {1, 4},  // paper beats rock, Spock
        {2, 1}, {2, 3},  // scissors beats paper, lizard
        {3, 1}, {3, 4},  // lizard beats paper, Spock
        {4, 0}, {4, 2},  // Spock beats rock, scissors
    };
    for (int i = 0; i < 10; i++) beats[wins[i][0]][wins[i][1]] = 1;

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        char s[16], r[16];
        scanf("%s %s", s, r);
        int sc = code(s), rc = code(r);

        // Output strings stay in Portuguese as written in the problem.
        const char* reaction;
        if (sc == rc)              reaction = "De novo!";
        else if (beats[sc][rc])    reaction = "Bazinga!";
        else                       reaction = "Raj trapaceou!";

        printf("Caso #%d: %s\n", i, reaction);
    }
    return 0;
}

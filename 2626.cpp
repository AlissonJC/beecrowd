/*
 * Beecrowd 2626 - "JB6 Team"
 *
 * Three friends - Dodo, Leo and Pepper, in this order - play a single round of
 * rock-paper-scissors (Portuguese moves: "pedra" = rock, "papel" = paper,
 * "tesoura" = scissors). Determine the winner of today's session.
 *
 * Beats relation: pedra > tesoura, tesoura > papel, papel > pedra.
 *
 * With THREE players a single winner exists only when exactly two distinct
 * moves appear AND the winning move is played by exactly one person, who then
 * beats the other two. Every other configuration is a tie:
 *   - all three moves equal      (nobody beats anybody),
 *   - all three moves distinct   (pedra/papel/tesoura form a cycle),
 *   - two distinct moves but the winning one is played by two people
 *     (two winners is not a single winner).
 *
 * Input : several test cases until EOF; each line has three moves a b c
 *         (Dodo, Leo, Pepper).
 * Output: one fixed message per case identifying the winner, or the tie message.
 *
 * Approach  : locate the lone move (the one differing from the matching pair).
 *             If that single player's move beats the pair's move, the lone
 *             player wins; otherwise the round is a tie.
 * Complexity: O(1) per test case.
 */

#include <iostream>
#include <string>
using namespace std;

// True when move x beats move y in rock-paper-scissors.
bool beats(const string& x, const string& y) {
    return (x == "pedra"   && y == "tesoura") ||
           (x == "tesoura" && y == "papel")   ||
           (x == "papel"   && y == "pedra");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Fixed result messages, copied verbatim from the statement - do not
    // translate or alter punctuation (Beecrowd compares the text exactly).
    const string WIN_DODO   = "Os atributos dos monstros vao ser inteligencia, sabedoria...";
    const string WIN_LEO    = "Iron Maiden's gonna get you, no matter how far!";
    const string WIN_PEPPER = "Urano perdeu algo muito precioso...";
    const string TIE        = "Putz vei, o Leo ta demorando muito pra jogar...";

    string a, b, c;  // moves of Dodo, Leo, Pepper respectively
    while (cin >> a >> b >> c) {
        if (a == b && b == c) {
            // All identical -> nobody beats anybody.
            cout << TIE << "\n";
        } else if (a == b) {
            // Dodo and Leo share a move; Pepper is the lone player.
            cout << (beats(c, a) ? WIN_PEPPER : TIE) << "\n";
        } else if (a == c) {
            // Dodo and Pepper share a move; Leo is the lone player.
            cout << (beats(b, a) ? WIN_LEO : TIE) << "\n";
        } else if (b == c) {
            // Leo and Pepper share a move; Dodo is the lone player.
            cout << (beats(a, b) ? WIN_DODO : TIE) << "\n";
        } else {
            // Three different moves -> rock/paper/scissors cycle -> tie.
            cout << TIE << "\n";
        }
    }
    return 0;
}

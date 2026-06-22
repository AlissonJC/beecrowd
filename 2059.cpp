/*
 * Beecrowd 2059 — Odd, Even or Cheating
 *
 * Two players play "odd or even". Player 1 picks a parity (even or odd) and
 * both players pick a positive integer; in the plain game Player 1 wins when
 * the sum's parity matches the parity Player 1 chose, otherwise Player 2 wins.
 * Two extra moves can override the plain game:
 *   - Player 1 may cheat (r).
 *   - Player 2 may accuse Player 1 of cheating (a).
 * Flag resolution:
 *   - cheated and accused   (r=1, a=1) -> Player 2 wins
 *   - cheated, not accused  (r=1, a=0) -> Player 1 wins
 *   - not cheated, accused  (r=0, a=1) -> Player 1 wins
 *   - neither               (r=0, a=0) -> play the plain game
 *
 * Input:
 *   One line with 5 integers: p j1 j2 r a, with 0 <= p,r,a <= 1 and
 *   1 <= j1,j2 <= 100. p=1 means Player 1 chose even, p=0 means odd. j1 and j2
 *   are the numbers chosen by Player 1 and Player 2; r=1 iff Player 1 cheated;
 *   a=1 iff Player 2 accused.
 *
 * Output:
 *   "Jogador 1 ganha!" or "Jogador 2 ganha!".
 *
 * Approach:
 *   Resolve the cheat/accusation flags first: if either flag is set the plain
 *   game is skipped and Player 1 wins unless BOTH flags are set (then Player 2
 *   wins). If neither is set, decide by parity — Player 1 wins when the sum's
 *   parity equals the parity Player 1 picked.
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <cstdio>

int main() {
    int p, j1, j2, r, a;
    if (scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a) != 5) return 0;

    bool player1Wins;

    if (r || a) {
        // A special flag is set, so the plain game does not apply. Player 2
        // only wins when Player 1 cheated AND was accused.
        player1Wins = !(r == 1 && a == 1);
    } else {
        // Plain game. sumParity: 0 = even sum, 1 = odd sum.
        int sumParity = (j1 + j2) % 2;
        // p == 1 -> Player 1 chose even (wins on even sum, sumParity 0).
        // p == 0 -> Player 1 chose odd  (wins on odd sum,  sumParity 1).
        player1Wins = (p == 1) ? (sumParity == 0) : (sumParity == 1);
    }

    puts(player1Wins ? "Jogador 1 ganha!" : "Jogador 2 ganha!");
    return 0;
}

/*
 * Beecrowd 2770 — Board Size
 *
 * Multiple test cases (EOF-terminated). Each starts with the board
 * dimensions X, Y and a count M of requests; then M pairs (Xi, Yi)
 * describe the requested PCB dimensions. A PCB fits if it can be
 * placed in either of the two orientations -- the board can be
 * thought of as un-oriented. Print "Sim" if the circuit fits and
 * "Nao" otherwise.
 */

#include <cstdio>

int main() {
    int X, Y, M;
    while (scanf("%d %d %d", &X, &Y, &M) == 3) {
        for (int i = 0; i < M; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            bool fits = (x <= X && y <= Y) || (x <= Y && y <= X);
            puts(fits ? "Sim" : "Nao");
        }
    }
    return 0;
}

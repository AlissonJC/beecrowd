/*
 * Beecrowd 2493 — Jogo do Operador (Operation Game)
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Multiple test cases (EOF-terminated). Each test case has:
 *     - An integer T (2 <= T <= 50): number of expressions AND number
 *       of players.
 *     - T expressions in the form "X Y=Z" (0 <= X,Y <= 10^3,
 *       -10^3 <= Z <= 10^6). The missing operator is one of '+', '-',
 *       '*'; the player can also answer 'I' for "Impossible" when none
 *       of those three works.
 *     - T player lines "Name E R", giving the chosen expression index
 *       E (1..T) and the picked answer R ('+', '-', '*', or 'I').
 *
 *   For each test case print:
 *     - "You Shall All Pass!"  if everybody answered acceptably,
 *     - "None Shall Pass!"     if nobody answered acceptably,
 *     - else the names of all players whose answer was wrong, sorted
 *       lexicographically and separated by spaces.
 *
 * Approach:
 *   For each expression i precompute the set of operators that
 *   actually validate it: insert '+' if X+Y == Z, '-' if X-Y == Z,
 *   '*' if X*Y == Z. If the set ends up empty the only acceptable
 *   answer is 'I', so insert 'I'. (When at least one of +, -, * works
 *   the answer 'I' is wrong -- "Impossible" is only a fallback the
 *   player picks when no operator fits.) For each player just look up
 *   their answer in the corresponding expression's set.
 *
 * Complexity:
 *   O(T log T) per test case (the sort of failure names). With T <= 50
 *   and names <= 50 chars this is trivial.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    while (scanf("%d", &T) == 1) {
        // valid[i] holds the operators that make expression i correct.
        vector<string> valid(T + 1);

        for (int i = 1; i <= T; i++) {
            long long x, y, z;
            // The expression is printed as "X Y=Z" without a space
            // around the '=' sign, so consume it explicitly here.
            scanf("%lld %lld=%lld", &x, &y, &z);

            string ops;
            if (x + y == z) ops.push_back('+');
            if (x - y == z) ops.push_back('-');
            if (x * y == z) ops.push_back('*');
            // "Impossible" is the right answer only when no operator
            // works; otherwise it is just a wrong guess.
            if (ops.empty()) ops.push_back('I');
            valid[i] = ops;
        }

        vector<string> failures;
        for (int i = 0; i < T; i++) {
            char name[64], r[8];
            int e;
            scanf("%63s %d %7s", name, &e, r);
            char answer = r[0];
            if (valid[e].find(answer) == string::npos) {
                failures.emplace_back(name);
            }
        }

        sort(failures.begin(), failures.end());

        if (failures.empty()) {
            puts("You Shall All Pass!");
        } else if ((int)failures.size() == T) {
            puts("None Shall Pass!");
        } else {
            // Space-separated, single trailing newline.
            for (size_t i = 0; i < failures.size(); i++) {
                if (i) putchar(' ');
                fputs(failures[i].c_str(), stdout);
            }
            putchar('\n');
        }
    }
    return 0;
}

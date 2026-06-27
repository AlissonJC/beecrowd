/*
 * Beecrowd 3255 - Prime Time
 *
 * Three players -- Odd, Even and Ingmariay (in that fixed cyclic turn order,
 * though who starts varies per round) -- play with a natural number. On a turn
 * the current value v is transformed into either v + 1 or v / q for some prime
 * q dividing v, and the acting player "claims" the resulting number. A player's
 * score for the round is the smallest number they ever claimed, or the round's
 * starting number if they never got to claim anything. Each player only ever
 * minimizes their OWN score; when several moves give that same own-score, the
 * lowest resulting number is chosen. The day's score per player is the sum over
 * all rounds (which is what we report).
 *
 * Reaching 1 ends the round, and 1 is only reachable from a prime (p / p = 1);
 * since 1 is the best possible score, the player whose turn starts on a prime
 * always takes it to 1 and the round ends there.
 *
 * solve(v, p) returns, as a triple indexed by player, the minimum number each
 * player claims from this position until the round ends (INF = no further
 * claim):
 *   - v prime  : player p divides to 1, so its claim is 1; the others claim
 *     nothing more here.
 *   - v composite: for every move to v' (v + 1 and v / q for each distinct prime
 *     factor q), player p claims v', so its result entry is min(v', child[p]);
 *     p selects the move minimizing ITS OWN entry, breaking ties by the smallest
 *     v'. (A player's whole-round minimum is rebuilt by these nested minimums,
 *     so carrying each player's running minimum in the state is unnecessary --
 *     it never changes the result.)
 * At the top level a player still at INF never claimed and instead scores the
 * starting number. A starting number of 1 is the special case where the game is
 * already at 1: nobody claims, so every player scores the starting number, 1.
 *
 * Input : first line n (1 <= n <= 1000). Each of the next n lines is the start
 *         player's initial ('O', 'E' or 'I'), a space, and the starting number
 *         in [1, 10000].
 * Output: one line with the day totals for Odd, Even and Ingmariay.
 *
 * Bounds: the +1 move only climbs until the next prime (which ends the game),
 * so all reachable values stay in [2, nextprime(10000) = 10007]. Memoizing on
 * (v, p) gives ~3 * 10^4 states shared across all rounds; the value graph is
 * acyclic, so the recursion terminates.
 *
 * Complexity: O(MAXV) states, O(distinct prime factors) each; O(1) per query.
 */

#include <iostream>

const int MAXV = 10200;   // covers nextprime(10000) = 10007 with margin
const int INF = 1000000000;

int spf[MAXV];            // smallest prime factor; spf[v] == v marks a prime
int memo[MAXV][3][3];     // memo[v][p] = triple of per-player minimum claims
char done[MAXV][3];       // memoization flag

// Sieve of smallest prime factors so distinct prime divisors are cheap to list.
void sieve() {
    for (int i = 2; i < MAXV; ++i)
        if (spf[i] == 0)
            for (int j = i; j < MAXV; j += i)
                if (spf[j] == 0) spf[j] = i;
}

// Fill out[0..2] with solve(v, p): the minimum each player claims from here on.
void solve(int v, int p, int out[3]) {
    if (done[v][p]) {
        for (int i = 0; i < 3; ++i) out[i] = memo[v][p][i];
        return;
    }

    int res[3] = {INF, INF, INF};

    if (spf[v] == v) {
        // v is prime: player p divides it to 1 and the round ends here.
        res[p] = 1;
    } else {
        // v is composite: try every legal move and let p pick the one that
        // minimizes p's own resulting claim, ties broken by the smallest value.
        int bestScore = INF, bestVal = INF;

        auto consider = [&](int vNext) {
            int child[3];
            solve(vNext, (p + 1) % 3, child);
            int outc[3] = {child[0], child[1], child[2]};
            // p claims vNext now; its score is the lower of that and its future.
            outc[p] = vNext < child[p] ? vNext : child[p];
            if (outc[p] < bestScore || (outc[p] == bestScore && vNext < bestVal)) {
                bestScore = outc[p];
                bestVal = vNext;
                for (int i = 0; i < 3; ++i) res[i] = outc[i];
            }
        };

        consider(v + 1);                       // add 1
        int x = v;
        while (x > 1) {                        // divide by each distinct prime
            int q = spf[x];
            consider(v / q);
            while (x % q == 0) x /= q;
        }
    }

    for (int i = 0; i < 3; ++i) { memo[v][p][i] = res[i]; out[i] = res[i]; }
    done[v][p] = 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    int n;
    std::cin >> n;

    long long total[3] = {0, 0, 0};

    while (n--) {
        char c;
        int start;
        std::cin >> c >> start;
        int p = (c == 'O') ? 0 : (c == 'E') ? 1 : 2;  // starting player index

        if (start == 1) {
            // Game already at 1: nobody claims, so each player scores the
            // starting number (1) by the no-claim rule.
            total[0] += 1; total[1] += 1; total[2] += 1;
            continue;
        }

        int sc[3];
        solve(start, p, sc);
        for (int i = 0; i < 3; ++i)
            total[i] += (sc[i] == INF) ? start : sc[i];  // no claim -> start number
    }

    std::cout << total[0] << " " << total[1] << " " << total[2] << "\n";
    return 0;
}

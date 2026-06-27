/*
 * Beecrowd 3250 - Elevator Trouble
 *
 * A building has f floors (1-indexed). An elevator starts at floor s and has
 * only two buttons: UP moves it u floors up, DOWN moves it d floors down. A
 * press that would leave the building (above floor f or below floor 1) does
 * nothing. Find the minimum number of presses to reach the goal floor g, or
 * report that it is impossible.
 *
 * Each floor is a node; from floor x there are at most two moves, x + u (if it
 * stays <= f) and x - d (if it stays >= 1). Every press costs 1, so the fewest
 * presses is the shortest path in this unweighted graph -> breadth-first search
 * from s, reading off the distance to g.
 *
 * Input : one line with f s g u d (1 <= s, g <= f <= 1000000, 0 <= u, d <=
 *         1000000).
 * Output: the minimum number of presses, or "use the stairs" if g is
 *         unreachable.
 *
 * Approach: BFS over floors 1..f from s. A u or d equal to 0 makes that button
 * a self-loop, which the visited array harmlessly ignores.
 *
 * Complexity: O(f) time and space.
 */

#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long f, s, g, u, d;
    // The statement gives a single line, but looping costs nothing and also
    // handles any trailing case gracefully.
    while (std::cin >> f >> s >> g >> u >> d) {
        std::vector<int> dist(f + 1, -1);  // -1 = not yet reached
        std::queue<long long> q;
        dist[s] = 0;
        q.push(s);

        while (!q.empty()) {
            long long x = q.front();
            q.pop();
            if (x == g) break;  // first time g is dequeued we have its shortest distance

            // UP: only valid if it does not exceed the top floor.
            long long up = x + u;
            if (up <= f && dist[up] == -1) {
                dist[up] = dist[x] + 1;
                q.push(up);
            }
            // DOWN: only valid if it does not drop below floor 1.
            long long down = x - d;
            if (down >= 1 && dist[down] == -1) {
                dist[down] = dist[x] + 1;
                q.push(down);
            }
        }

        if (dist[g] == -1)
            std::cout << "use the stairs\n";
        else
            std::cout << dist[g] << "\n";
    }

    return 0;
}

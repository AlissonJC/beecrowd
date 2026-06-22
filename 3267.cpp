/*
 * Beecrowd 3267 — Cliff Walk
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   A coastal grid of W x H squares (each 10 m x 10 m) is given with
 *   per-square heights in millimetres. The tide level (metres) at time
 *   t (hours since last high tide) is
 *       v(t) = 0.5 * a * (cos(t * 2*pi/12) + 1)
 *   so v(0) = a (high), v(6) = 0 (low), v(12) = a. A square's surface
 *   stops being submerged when the tide level drops to its height, but
 *   the rock then needs ONE FULL HOUR of drying before it is safe to
 *   walk on. Once the rising tide reaches the square's height again the
 *   square is unsafe immediately. Charlotte may step between two
 *   neighbouring squares (N/S/E/W) iff the absolute height difference
 *   is at most 1 m, the step takes m seconds, and BOTH squares are in
 *   their walkable window for the entire step. Waiting on a walkable
 *   square is free. Charlotte starts and finishes at her home (X, Y)
 *   and is away at most one tide cycle (12 h). Print the maximum
 *   Euclidean distance (in metres) between her home and any square she
 *   can reach and safely return from.
 *
 * Per-cell walkable window:
 *   For a square of height z (millimetres), let
 *       T1 = (6/pi) * acos(2 z / a_mm - 1)
 *   be the moment of the falling tide at which the water level equals
 *   z. The walkable window is
 *       [dry(z), wet(z)] = [T1 + 1, 12 - T1].
 *   Squares whose height strictly exceeds the tide amplitude are
 *   always walkable; sentinel values dry = -2, wet = 14 keep the
 *   comparisons one-sided.
 *
 *   Note: the dry-side endpoint is offset by +1 hour (the drying
 *   period), which makes the window asymmetric around t = 6. A simple
 *   "earliest arrival <= 6" mirror argument therefore does NOT capture
 *   feasibility of the return trip -- we must compute the latest legal
 *   departure separately.
 *
 * Approach:
 *   1. Forward Dijkstra from home at t = 0 producing
 *        enterT[c] = earliest moment Charlotte can be standing on c.
 *      Edge relaxation c -> c':
 *        start  = max(enterT[c], dry[c'])
 *        finish = start + m_hours
 *        feasible iff finish <= wet[c'].
 *   2. Backward Dijkstra from home at t = 12 producing
 *        leaveT[c] = latest moment Charlotte can be standing on c and
 *                    still walk home by t = 12.
 *      Edge relaxation c -> c' (backwards in time):
 *        finish = min(leaveT[c], wet[c'])
 *        start  = finish - m_hours
 *        feasible iff start >= dry[c'].
 *   3. A square c is "reachable AND returnable" iff enterT[c] <= leaveT[c].
 *      Print 10 * max Euclidean (grid-units) distance over such squares.
 *
 * Input:
 *   Line 1: a m  (floats: tide amplitude in metres, step time in seconds)
 *   Line 2: W H X Y  (1 <= W,H <= 200; 0 <= X < W; 0 <= Y < H)
 *   Next H lines: W integers per line, the heights in millimetres
 *                 (0 .. 20000). First number on first line is (0, 0).
 *
 * Output:
 *   The maximum Euclidean distance from home, printed with eight
 *   decimals.
 *
 * Complexity:
 *   Two Dijkstras over at most 4 * W * H edges with W * H <= 40000
 *   cells: O((WH) log (WH)) -- well below the 1 s budget.
 */

#include <bits/stdc++.h>
using namespace std;

static const int MAXD = 205;
static const int CLIMB_MAX = 1000;       // 1 metre, in millimetres
static const double DRYING_HOURS = 1.0;  // rocks dry for 1 h after exposure

static int W, H, Hx, Hy;
static double a_mm, m_hours;
static int z[MAXD][MAXD];
static double dryT[MAXD][MAXD];   // earliest moment cell is walkable
static double wetT[MAXD][MAXD];   // latest moment cell is walkable
static double enterT[MAXD][MAXD]; // earliest arrival from home
static double leaveT[MAXD][MAXD]; // latest legal "still here" time

static const int dxs[4] = {1, -1, 0, 0};
static const int dys[4] = {0, 0, 1, -1};

struct Node {
    int x, y;
    double t;
};

int main() {
    double a_m, m_s;
    scanf("%lf %lf", &a_m, &m_s);
    a_mm    = a_m * 1000.0;      // amplitude in millimetres
    m_hours = m_s / 3600.0;      // step time in hours

    scanf("%d %d %d %d", &W, &H, &Hx, &Hy);

    // Read the grid and compute per-cell walkable windows.
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            scanf("%d", &z[y][x]);
            if (z[y][x] <= a_mm) {
                // Falling-tide moment when water level equals z.
                double t = acos(2.0 * z[y][x] / a_mm - 1.0) * 6.0 / M_PI;
                dryT[y][x] = t + DRYING_HOURS;
                wetT[y][x] = 12.0 - t;
            } else {
                // Cell stays above the tide -- always walkable.
                dryT[y][x] = -2.0;
                wetT[y][x] = 14.0;
            }
            enterT[y][x] = 12.0;  // "no valid arrival known yet"
            leaveT[y][x] = 0.0;   // "no valid departure known yet"
        }
    }
    enterT[Hy][Hx] = 0.0;
    leaveT[Hy][Hx] = 12.0;

    // Forward Dijkstra -- earliest time Charlotte can be on each cell.
    {
        auto cmp = [](const Node& p, const Node& q) { return p.t > q.t; };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push({Hx, Hy, 0.0});
        while (!pq.empty()) {
            Node p = pq.top();
            pq.pop();
            if (p.t > enterT[p.y][p.x] + 1e-15) continue;
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dxs[i];
                int ny = p.y + dys[i];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                if (abs(z[p.y][p.x] - z[ny][nx]) > CLIMB_MAX) continue;
                // Wait at p until the destination is dry, then walk.
                double start  = max(p.t, dryT[ny][nx]);
                double finish = start + m_hours;
                if (finish > wetT[ny][nx]) continue;
                if (finish < enterT[ny][nx]) {
                    enterT[ny][nx] = finish;
                    pq.push({nx, ny, finish});
                }
            }
        }
    }

    // Backward Dijkstra -- latest time Charlotte can still leave each
    // cell and reach home by t = 12. The recurrence is the time-reverse
    // of the forward one; for the move c -> c' starting at "start" and
    // ending at "finish", the destination cell's wetT bounds finish.
    {
        auto cmp = [](const Node& p, const Node& q) { return p.t < q.t; };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push({Hx, Hy, 12.0});
        while (!pq.empty()) {
            Node p = pq.top();
            pq.pop();
            if (p.t < leaveT[p.y][p.x] - 1e-15) continue;
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dxs[i];
                int ny = p.y + dys[i];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                if (abs(z[p.y][p.x] - z[ny][nx]) > CLIMB_MAX) continue;
                // Walk arrives at p by the latest "finish" and starts
                // at the matching "start". The destination is the cell
                // we are computing leaveT for, hence its dry/wet
                // window is what bounds start.
                double finish = min(p.t, wetT[ny][nx]);
                double start  = finish - m_hours;
                if (start < dryT[ny][nx]) continue;
                if (start > leaveT[ny][nx]) {
                    leaveT[ny][nx] = start;
                    pq.push({nx, ny, start});
                }
            }
        }
    }

    // A cell is safely visitable iff the earliest arrival is no later
    // than the latest legal "still here" time.
    double best = 0.0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (enterT[y][x] <= leaveT[y][x]) {
                double dx = x - Hx;
                double dy = y - Hy;
                double dist = sqrt(dx * dx + dy * dy);
                if (dist > best) best = dist;
            }
        }
    }
    printf("%.8f\n", best * 10.0);
    return 0;
}

/*
 * Beecrowd 3258 — Boiling Vegetables
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   N pieces of vegetable have integer weights W_1..W_N (W_i < 10^6,
 *   N <= 1000). A "cut" splits one piece of weight w into two pieces
 *   of weights a and w - a (any 0 < a < w). Given a threshold
 *   0.5 < T < 1, return the minimum number of cuts needed so the
 *   ratio between the smallest and largest resulting piece is strictly
 *   above T. The answer is guaranteed to be < 500, and the optimum for
 *   T equals the optimum for T + 0.0001 (no numeric boundary issues).
 *
 * Modelling:
 *   Suppose piece i is cut into k_i sub-pieces; that costs k_i - 1
 *   cuts. With even cuts every sub-piece of piece i weighs W_i / k_i,
 *   which is optimal for the min/max ratio. So the question becomes:
 *   choose integers k_i >= 1 minimising sum(k_i - 1) such that
 *       min_i (W_i / k_i)  >  T * max_i (W_i / k_i).
 *
 * Sweep idea:
 *   Let M = max_i (W_i / k_i). Decreasing M can only force some k_i
 *   to grow; that increases the cut count and decreases that piece's
 *   ratio. The "events" at which a particular k_i transitions from
 *   k to k+1 happen exactly when M crosses W_i / k from above. So
 *   sort all events (W_i / k for i in 1..N, k = 1, 2, ...) in
 *   descending order of M and process them; group events sharing the
 *   same M before re-checking feasibility (otherwise we would
 *   inspect a transient k-configuration that does not correspond to
 *   any real M). Stop the first time the ratio condition holds.
 *
 * Implementation:
 *   Keep a max-heap of (W_i, divisor d, piece i, new_k) where the
 *   ordering key is W_i / d (compared via cross-multiplication to
 *   stay exact). Initially every piece has its first event with
 *   d = 1 (the transition k_i: 1 -> 2). When we apply an event we
 *   push the piece's next event (d <- new_k). Because the answer is
 *   bounded by 500 cuts, only at most ~500 events are ever popped.
 *
 * Complexity:
 *   O((C + N) log N) where C <= 500 is the answer, plus O(N) per
 *   feasibility check (constant number of checks bounded by C).
 *   Comfortably under 1 s for N <= 1000.
 */

#include <bits/stdc++.h>
using namespace std;

struct Event {
    long long num;   // W_i
    long long den;   // current k_i (the divisor that gives this event's M)
    int piece;
    int new_k;       // the k_i to assign after the event fires
};

struct EventCmp {
    bool operator()(const Event& a, const Event& b) const {
        // Max-heap by num/den, compared exactly with cross-multiplication.
        return a.num * b.den < b.num * a.den;
    }
};

int main() {
    double T;
    int N;
    scanf("%lf %d", &T, &N);

    vector<long long> W(N);
    for (int i = 0; i < N; i++) scanf("%lld", &W[i]);

    vector<int> k(N, 1);
    vector<double> r(N);
    for (int i = 0; i < N; i++) r[i] = (double)W[i];

    auto feasible = [&]() {
        double pmin = r[0], pmax = r[0];
        for (int i = 1; i < N; i++) {
            if (r[i] < pmin) pmin = r[i];
            if (r[i] > pmax) pmax = r[i];
        }
        return pmin > T * pmax;
    };

    // The trivial case: the original ratio already exceeds T.
    if (feasible()) {
        puts("0");
        return 0;
    }

    priority_queue<Event, vector<Event>, EventCmp> pq;
    for (int i = 0; i < N; i++) pq.push({W[i], 1, i, 2});

    while (!pq.empty()) {
        // Pop ALL events sharing the current top's M value -- otherwise
        // the intermediate state would correspond to k_i values that
        // are inconsistent with any single value of M.
        Event head = pq.top();
        vector<Event> batch;
        while (!pq.empty()) {
            const Event& cur = pq.top();
            if (cur.num * head.den != head.num * cur.den) break;
            batch.push_back(cur);
            pq.pop();
        }
        for (auto& e : batch) {
            k[e.piece] = e.new_k;
            r[e.piece] = (double)W[e.piece] / e.new_k;
            // Next event for this piece: transitions new_k -> new_k+1
            // when M drops below W_i / new_k.
            pq.push({W[e.piece], (long long)e.new_k, e.piece, e.new_k + 1});
        }
        if (feasible()) {
            int cuts = 0;
            for (int j = 0; j < N; j++) cuts += k[j] - 1;
            printf("%d\n", cuts);
            return 0;
        }
    }

    // The statement guarantees an answer below 500, so we never reach
    // here in valid inputs.
    return 0;
}

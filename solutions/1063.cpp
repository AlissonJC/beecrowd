/*
 * Beecrowd 1063 - Rails Again... Tracing Movements
 * Platform: Beecrowd
 *
 * Problem restatement:
 *   Wagons arrive from direction A in a given order and must leave toward B in a
 *   desired order, using a single dead-end track (a STACK) at the station. Each
 *   wagon is one lowercase letter a..z (so at most 26, all distinct). Output the
 *   sequence of moves that realizes the desired order: 'I' = insert (push the
 *   next arriving wagon into the station), 'R' = remove (pop the top wagon out to
 *   B). If the desired order cannot be produced, print the moves done so far
 *   followed by "Impossible".
 *
 * Input  : many test cases. Each is three lines: N (number of wagons), the input
 *          (arrival) sequence of N letters, and the desired output sequence of N
 *          letters. A line with just 0 ends the input.
 * Output : one line per test case. The I/R move string if achievable; otherwise
 *          the partial move string followed by " Impossible".
 *
 * Sample:
 *   in "e t d a", out "d a t e" -> "IIIRIRRR"
 *   in "o s t a p", out "p a t o s" -> "IIIIIRRR Impossible"
 *
 * Approach (greedy stack simulation, recording the moves):
 *   Walk the desired output. For each target, keep pushing the next arriving
 *   wagon (emit 'I') until the stack top equals the target, then pop it (emit
 *   'R'). If the arrivals run out before the top matches, the order is
 *   impossible: stop and append "Impossible" to whatever was emitted. A wagon
 *   must already be on the stack before any wagon placed on top of it can leave,
 *   so pushing exactly up to the target is the only feasible move.
 *
 * Complexity:
 *   O(N) per test case (each wagon is pushed and popped at most once). N <= 26.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        vector<char> arr(n), want(n);
        for (int i = 0; i < n; ++i) scanf(" %c", &arr[i]);   // arrival order
        for (int i = 0; i < n; ++i) scanf(" %c", &want[i]);  // desired exit order

        vector<char> st;
        string moves;
        int idx = 0;            // next arriving wagon to insert
        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            // Insert arrivals until the wanted wagon sits on top.
            while (st.empty() || st.back() != want[i]) {
                if (idx >= n) { ok = false; break; }
                st.push_back(arr[idx++]);
                moves += 'I';
            }
            if (!ok) break;
            st.pop_back();      // remove the matching wagon to B
            moves += 'R';
        }

        if (ok) printf("%s\n", moves.c_str());
        else    printf("%s Impossible\n", moves.c_str());    // partial moves + word
    }
    return 0;
}

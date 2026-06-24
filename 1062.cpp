/*
 * Beecrowd 1062 - Rails
 * Platform: Beecrowd
 *
 * Problem restatement:
 *   Coaches arrive from direction A numbered 1,2,...,N in increasing order. The
 *   dead-end station is a single track that behaves like a STACK: a coach can be
 *   pushed in (leaving A) and later popped out (to B), LIFO. Given a desired
 *   exit order a_1..a_N at B, decide whether it can be produced.
 *
 * Input  : blocks. A block starts with N; then one or more lines, each a
 *          permutation of 1..N; the block ends with a line "0". The whole input
 *          ends with a block whose N = 0.
 * Output : "Yes"/"No" per permutation line. After each block, one blank line.
 *          The final (N = 0) block produces no output and no blank line.
 *
 * Sample:
 *   5 4 3 2 1 -> Yes ; 1 2 3 4 5 -> Yes ; 5 4 1 2 3 -> No ; 1 3 2 5 4 6 -> Yes
 *
 * Approach (classic stack-permutation check):
 *   Walk the required exit sequence. Keep a stack and a counter `next` = the
 *   smallest coach not yet entered. For each target a[i], keep pushing coaches
 *   (next, next+1, ...) until the stack top equals a[i]; then pop it. If we run
 *   out of coaches before the top matches, the order is impossible. This is
 *   greedy-optimal: a coach must be on the stack before its successor can leave,
 *   so pushing exactly up to the target is the only sensible move.
 *
 * Complexity:
 *   O(N) per permutation (each coach is pushed and popped once). N <= 1000.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {     // n == 0 -> last block, stop
        int first;
        // Read permutations until the lone "0" that ends this block.
        while (scanf("%d", &first) == 1 && first != 0) {
            vector<int> a(n);
            a[0] = first;
            for (int i = 1; i < n; ++i) scanf("%d", &a[i]);

            stack<int> st;
            int next = 1;                        // next coach to enter from A
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                // Bring coaches in until the wanted one is on top.
                while (next <= n && (st.empty() || st.top() != a[i]))
                    st.push(next++);
                if (!st.empty() && st.top() == a[i])
                    st.pop();                    // send it out to B
                else { ok = false; break; }      // impossible
            }
            printf(ok ? "Yes\n" : "No\n");
        }
        printf("\n");                            // blank line after each block
    }
    return 0;
}

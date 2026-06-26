/*
 * Beecrowd 1933 - Tri-du
 *
 * In this Truco-inspired game a player holds three cards valued 1..13 (suits
 * ignored). Hand ranking: a Three of a Kind beats any Pair; a higher Three of a
 * Kind beats a lower one; a higher Pair beats a lower one. The player already
 * holds two cards A and B and must choose the value of the third card that
 * maximizes the probability of winning.
 *
 * Input : one line with two integers A and B (1 <= A,B <= 13).
 * Output: a single integer, the best value to choose for the third card.
 *
 * Approach: two cases that both reduce to max(A, B).
 *   - If A == B, a pair is already held; the only way to upgrade to a Three of a
 *     Kind (which beats every pair) is to draw that same value. max(A,B) = A.
 *   - If A != B, only a pair can be formed, and the higher pair wins, so draw
 *     the larger of the two values, i.e. max(A,B).
 * Hence printing max(A, B) is optimal in every case.
 *
 * Complexity: O(1) time and space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    // max(A,B): completes the highest pair when A != B, and completes the three
    // of a kind (the value itself) when A == B.
    cout << max(a, b) << "\n";

    return 0;
}

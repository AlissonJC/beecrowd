/*
 * Beecrowd 3494 — Palavras transformadas (Transformed Words)
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Given two lowercase words S and T of equal length (3 <= |S| <= 1e4),
 *   compute the minimum cost to turn T into S where each position can
 *   be changed independently. The cost at position i is the shortest
 *   distance from T[i] to S[i] on the circular alphabet -- so 'a' and
 *   'z' are 1 apart, not 25. Output the total cost.
 *
 * Approach:
 *   For each i, let d = |S[i] - T[i]|. The circular distance is
 *   min(d, 26 - d). Sum these across all positions. Linear scan, trivial.
 *
 * Complexity:
 *   O(|S|).
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    if (!(cin >> s >> t)) return 0;
    long long total = 0;
    for (size_t i = 0; i < s.size(); i++) {
        int d = abs(s[i] - t[i]);
        // Circular alphabet: going the "long way around" costs 26 - d.
        total += min(d, 26 - d);
    }
    cout << total << "\n";
    return 0;
}

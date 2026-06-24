/*
 * Beecrowd 3039 - Santa's Toys
 *
 * For children who didn't send a letter, Santa gives a default gift: a toy car
 * to each boy and a doll to each girl. Count how many of each are needed.
 *
 * Input : N (0 < N <= 1000); then N lines "name S" where S is 'M' (boy) or 'F'
 *         (girl). (Read until EOF to be safe.)
 * Output: two lines -- "<boys> carrinhos" then "<girls> bonecas".
 *
 * Approach: tally the boys and the girls while reading, then print the two
 *   counts with their Portuguese gift words.
 *
 * Complexity: O(N) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int boys = 0, girls = 0;
        for (int i = 0; i < n; ++i) {
            string name;
            char s;
            cin >> name >> s;
            if (s == 'M') ++boys;       // boy -> toy car
            else          ++girls;      // 'F' -> doll
        }
        cout << boys  << " carrinhos\n";
        cout << girls << " bonecas\n";
    }
    return 0;
}

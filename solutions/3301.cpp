/*
 * Beecrowd 3301 - Middle Nephew
 *
 * Uncle Patinhas has three nephews: Huguinho, Zezinho and Luisinho. For each
 * test case we are given three integer ages H, Z and L (in that order) and must
 * print the name of the MIDDLE nephew, i.e. the one who is neither the youngest
 * nor the oldest. The name is printed in lowercase.
 *
 * Input : several test cases, each with three integers H Z L, until EOF.
 * Output: for each case, the middle nephew's name on its own line.
 *
 * Approach: the middle nephew is simply the one whose age is the median of the
 * three. A value `a` is the median when it lies between the other two ages,
 * inclusive: min(b, c) <= a <= max(b, c). The ages are distinct, so exactly one
 * of the three satisfies this and we test them in order H, Z, L.
 *
 * Complexity: O(1) time and O(1) space per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, Z, L;
    // EOF-terminated loop: keep reading triples until the stream runs out.
    while (cin >> H >> Z >> L) {
        if (H >= min(Z, L) && H <= max(Z, L))
            cout << "huguinho\n";        // H is the median age
        else if (Z >= min(H, L) && Z <= max(H, L))
            cout << "zezinho\n";         // Z is the median age
        else
            cout << "luisinho\n";        // by elimination, L is the median
    }

    return 0;
}

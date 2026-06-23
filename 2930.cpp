/*
 * Beecrowd 2930 - Final Thesis of Christmas Depression
 *
 * A student delivers her thesis on day E against a deadline D. Decide the
 * outcome: if it is late it is impossible; if it is comfortably early it is fine;
 * if it is close to the deadline it needs two extra days of corrections, after
 * which it is only presented in time if it still lands before Christmas Eve (24).
 *
 * Input : several test cases (EOF), each with E and D (0 < E, D < 25).
 * Output: the verdict messages (Portuguese, verbatim) for each test case.
 *
 * Approach: straightforward branching. Delivered after the deadline (E > D) is
 *   impossible. Delivered at least 3 days before the deadline is fine. Otherwise
 *   it is "close": print the warning, add 2 correction days to the delivery day,
 *   and check whether E + 2 is still before day 24.
 *
 * Complexity: O(1) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int e, d;
    while (cin >> e >> d) {
        // Output strings are the exact Portuguese messages required.
        if (e > d) {
            cout << "Eu odeio a professora!\n";          // delivered after the deadline
        } else if (d - e >= 3) {
            cout << "Muito bem! Apresenta antes do Natal!\n";   // safely early
        } else {
            cout << "Parece o trabalho do meu filho!\n";  // close to the deadline
            if (e + 2 < 24) cout << "TCC Apresentado!\n";       // +2 days still before the 24th
            else            cout << "Fail! Entao eh nataaaaal!\n";
        }
    }
    return 0;
}

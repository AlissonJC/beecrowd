/*
 * Beecrowd 2813 - Avoiding Rain
 *
 * Rafael commutes once a day. If it rains on the way TO work he carries an
 * umbrella from home and leaves it at the office; if it rains on the way HOME he
 * carries one from the office and leaves it at home. He pre-stocks some umbrellas
 * at home and some at the office. Given the forecast for each day (morning and
 * evening, "sol" = dry, "chuva" = rain), find the minimum number to store at home
 * (C) and at the office (E) so he never gets wet.
 *
 * Input : several test cases (EOF). Each begins with N (1 <= N <= 1000), then N
 *         lines "SD SN" -- the morning and evening forecasts.
 * Output: per test case, "C E".
 *
 * Approach: simulate the umbrella counts at home and office starting empty. On a
 *   rainy trip, move one umbrella across; if the source has none, that umbrella
 *   had to be part of the initial stock, so increment the corresponding buy
 *   counter. Buying only when forced is optimal, since each forced shortage
 *   demands exactly one more umbrella at that location.
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
        int home = 0, office = 0;   // umbrellas currently available at each place
        int buyHome = 0, buyOffice = 0;
        for (int i = 0; i < n; ++i) {
            string sd, sn;
            cin >> sd >> sn;
            if (sd == "chuva") {                 // rain on the way to work: home -> office
                if (home > 0) --home; else ++buyHome;
                ++office;
            }
            if (sn == "chuva") {                 // rain on the way home: office -> home
                if (office > 0) --office; else ++buyOffice;
                ++home;
            }
        }
        cout << buyHome << " " << buyOffice << "\n";
    }
    return 0;
}

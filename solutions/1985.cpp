/*
 * Beecrowd 1985 - MacPRONALTS
 *
 * A cashier must total a purchase from a fixed menu of five products:
 *   1001 -> R$ 1.50   1002 -> R$ 2.50   1003 -> R$ 3.50
 *   1004 -> R$ 4.50   1005 -> R$ 5.50
 * so the unit price of a product equals (code - 1000) + 0.50 reais. Given the
 * products bought and how many of each, print the grand total.
 *
 * Input : an integer p (1 <= p <= 5), the number of distinct products bought.
 *         Then p lines, each "code quantity" with 1 <= quantity <= 500.
 * Output: the total amount with exactly two decimal places.
 *
 * Approach: accumulate the total in integer CENTS to avoid any floating-point
 * rounding (the judge compares output as text). A product's price in cents is
 * (code - 1000) * 100 + 50; multiply by its quantity and sum. Finally print the
 * whole-reais part, a dot, and the two-digit cents part (zero-padded).
 *
 * Complexity: O(p) time, O(1) space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    cin >> p;

    long long totalCents = 0;
    for (int i = 0; i < p; i++) {
        int code, qty;
        cin >> code >> qty;
        // Unit price in cents: 1001->150, 1002->250, ..., 1005->550.
        long long priceCents = (long long)(code - 1000) * 100 + 50;
        totalCents += priceCents * qty;
    }

    // Print as reais.cents using pure integer formatting (no floating point),
    // padding the cents to two digits so e.g. 0 -> "00" and 50 -> "50".
    cout << totalCents / 100 << '.'
         << setw(2) << setfill('0') << totalCents % 100 << "\n";

    return 0;
}

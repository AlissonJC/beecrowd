/*
 * Beecrowd 2670 - "Coffee Machine"
 * Maratona de Programacao da SBC / ACM-ICPC 2017.
 *
 * A building has 3 floors with A1, A2, A3 employees respectively. Place one
 * espresso machine on a single floor F. Every employee walks from their floor
 * to F and back once a day, spending 1 minute per floor climbed or descended,
 * i.e. 2 * |floor - F| minutes round trip. Choose F to minimize the grand total
 * of minutes across all employees.
 *
 * Cost of placing the machine on floor F:  sum over floors i of  A_i * 2*|i-F|.
 * With only 3 floors, just evaluate F = 1, 2, 3 and take the smallest cost.
 *
 * Input : three integers A1, A2, A3 (0 <= Ai <= 1000), one per line.
 * Output: a single integer, the minimum total number of minutes.
 *
 * Approach  : brute force over the 3 possible machine floors; O(1) overall.
 * Complexity: O(1) time and space (a fixed 3x3 amount of work).
 *
 * Type note: the largest possible total is at an extreme floor, A2*2 + A3*4 <=
 * 2000 + 4000 = 6000, far inside 32-bit int range, so int cannot overflow here.
 */

#include <iostream>
#include <cstdlib>   // std::abs for ints
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[3];
    // Read defensively in an EOF loop: behaves the same for the single stated
    // case, but also copes if the test data stacks several cases back to back.
    while (cin >> a[0] >> a[1] >> a[2]) {
        int best = -1;  // -1 marks "no candidate evaluated yet"

        // Try the machine on each floor f (0-indexed; only the gap |i-f| matters).
        for (int f = 0; f < 3; f++) {
            int total = 0;
            for (int i = 0; i < 3; i++)
                // a[i] people each make a 2*|i-f|-minute round trip to floor f.
                total += a[i] * 2 * abs(i - f);

            if (best == -1 || total < best)
                best = total;
        }

        cout << best << "\n";
    }
    return 0;
}

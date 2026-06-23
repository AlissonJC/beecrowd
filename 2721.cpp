/*
 * Beecrowd 2721 - "Indecision of Reindeers"
 *
 * Nine reindeer each make some snowballs; all are pooled together and then
 * handed out one by one, cyclically, always in the fixed order
 *   Dasher, Dancer, Prancer, Vixen, Comet, Cupid, Donner, Blitzen, Rudolph.
 * Whoever receives the very last snowball leads the sled. Given how many each
 * reindeer made, print the winner.
 *
 * Only the TOTAL number of snowballs matters: snowball number `total` is the
 * last one, and in a 9-way round-robin it lands on the reindeer at position
 * (total mod 9), counting 1..9; a remainder of 0 means the cycle ended exactly
 * on the 9th reindeer (Rudolph).
 *
 * Input : a line with 9 integers A_i (1 <= A_i <= 10^4).
 * Output: a single line with the winning reindeer's name.
 *
 * Approach  : sum the 9 counts, take total mod 9, index the order table.
 * Complexity: O(1) time and space.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Snowball distribution order (index 0 = 1st to receive).
    const string names[9] = {
        "Dasher", "Dancer", "Prancer", "Vixen", "Comet",
        "Cupid",  "Donner", "Blitzen", "Rudolph"
    };

    int a;
    // Defensive EOF loop: one iteration for the single stated case, but also
    // safe if the test data happens to stack several lines of 9 integers.
    while (cin >> a) {
        int total = a;                       // first of the nine counts
        for (int i = 1; i < 9; i++) {
            cin >> a;
            total += a;                      // total <= 9*10^4, no overflow
        }

        // Position of the last snowball in the 9-way cycle; 0 maps to the 9th.
        int pos = total % 9;
        if (pos == 0) pos = 9;

        cout << names[pos - 1] << "\n";
    }
    return 0;
}

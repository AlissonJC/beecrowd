/*
 * Beecrowd 3214 - Soda Surpler
 *
 * Tim starts the day with E empty soda bottles and finds F more in the street.
 * Whenever he has at least C empty bottles he trades C of them for one new soda;
 * drinking it leaves him one fresh empty bottle. He keeps buying until he can no
 * longer afford a soda. Count how many sodas he drinks.
 *
 * Input : non-negative integers  E F C  per line (E < 1000, F < 1000,
 *         1 < C < 2000), repeated until end of file.
 * Output: the number of sodas drunk, one line per case.
 *
 * Approach: he begins with E + F empties (the source of a bottle is irrelevant).
 *   Each purchase removes C bottles and returns 1 (the drained one), a net loss
 *   of C - 1, so simulate while the stock is at least C. Bounds are tiny
 *   (< 2000 empties), so the direct loop is instant; the equivalent closed form
 *   is (E + F - 1) / (C - 1) whenever E + F >= 1.
 *
 * Complexity: O((E + F) / (C - 1)) per case, at most a couple thousand steps.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int E, F, C;
    // EOF-terminated read: works whether the judge sends one line or many.
    while (std::cin >> E >> F >> C) {
        int bottles = E + F;        // every empty counts, no matter where it came from
        int sodas = 0;
        while (bottles >= C) {      // can still afford a soda?
            bottles -= C;           // trade C empties for one soda
            bottles += 1;           // drinking it yields one new empty
            ++sodas;
        }
        std::cout << sodas << "\n";
    }
    return 0;
}

/*
 * Beecrowd 1066 - Even, Odd, Positive and Negative
 *
 * Read five integer values and count, across all of them, how many are
 * even, how many are odd, how many are strictly positive and how many are
 * strictly negative. Zero is even, but it is neither positive nor negative,
 * so it lands only in the "even" bucket and the four totals need not sum
 * to five.
 *
 * Input : five integers, one per line.
 * Output: four lines, each "<count> valor(es) <category>" using the exact
 *         Portuguese labels required by the judge.
 *
 * Approach: a single pass over the five inputs incrementing four counters.
 * Evenness is tested with v % 2 == 0; this is correct for negatives too,
 * because an even negative number still has remainder 0 (e.g. -4 % 2 == 0,
 * while -5 % 2 == -1 which is != 0, i.e. odd).
 *
 * Complexity: O(1) time and space - exactly five reads.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int even = 0, odd = 0, positive = 0, negative = 0;

    // The statement guarantees exactly five values.
    for (int i = 0; i < 5; ++i) {
        int v;
        std::cin >> v;

        if (v % 2 == 0) ++even;      // 0 counts as even
        else            ++odd;

        if (v > 0)      ++positive;  // strictly positive: 0 excluded
        else if (v < 0) ++negative;  // strictly negative: 0 excluded
    }

    // Portuguese output labels are required verbatim by the judge.
    std::cout << even     << " valor(es) par(es)\n";
    std::cout << odd      << " valor(es) impar(es)\n";
    std::cout << positive << " valor(es) positivo(s)\n";
    std::cout << negative << " valor(es) negativo(s)\n";

    return 0;
}

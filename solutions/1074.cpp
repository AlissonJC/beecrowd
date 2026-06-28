/*
 * Beecrowd 1074 - Even or Odd
 *
 * Read N test cases; for each integer X print, on one line, whether it is odd
 * or even AND whether it is positive or negative. Zero is a special case:
 * although zero is even, the program must print only "NULL".
 *
 * Input : first line N (N < 10000); then N integers X, each -10^7 < X < 10^7.
 * Output: per value, one of "EVEN POSITIVE", "ODD POSITIVE", "EVEN NEGATIVE",
 *         "ODD NEGATIVE", or "NULL" for zero. Uppercase, single space between
 *         the two words.
 *
 * Approach: For each value, handle zero first (print "NULL"). Otherwise combine
 * two independent classifications: parity from X % 2 (non-zero remainder means
 * odd, which also works for negatives in C++, e.g. -5 % 2 == -1) and sign from
 * X > 0. All values fit in a 32-bit int, so no wide types are needed.
 *
 * Complexity: O(N) time, O(1) space.
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int x;
        std::cin >> x;

        if (x == 0) {
            // Per the statement, zero is reported as "NULL" only -- not "EVEN".
            std::cout << "NULL\n";
        } else {
            // Parity: non-zero remainder (incl. negatives) means odd.
            const char* parity = (x % 2 != 0) ? "ODD" : "EVEN";
            // Sign: strictly greater than zero is positive (zero already handled).
            const char* sign = (x > 0) ? "POSITIVE" : "NEGATIVE";
            std::cout << parity << " " << sign << "\n";
        }
    }

    return 0;
}

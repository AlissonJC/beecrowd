/*
 * Beecrowd 1052 - Month
 *
 * Read an integer from 1 to 12 and print the corresponding month of the year
 * in English, with the first letter capitalized.
 *
 * Input : a single integer N, 1 <= N <= 12.
 * Output: the English name of month N (e.g. 4 -> "April").
 *
 * Approach: A direct index lookup. Store the twelve month names in order and
 * print the one at position N-1 (the table is 0-based, the months are 1-based).
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    // Month names in calendar order; index 0 holds January, so month N maps to
    // names[N - 1].
    static const char* names[12] = {
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"
    };

    int n;
    std::cin >> n;

    // Shift from the 1-based month number to the 0-based array index.
    std::cout << names[n - 1] << "\n";

    return 0;
}

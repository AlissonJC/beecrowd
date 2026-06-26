/*
 * Beecrowd 1154 - "Ages"
 *
 * Read an undetermined number of ages and compute their average. Reading
 * stops at the first negative value, which is a sentinel and is NOT part of
 * the group (it does not enter the calculation).
 *
 * Input : a sequence of integers, one per line; a negative value ends input.
 * Output: the average age printed with exactly two digits after the decimal
 *         point, e.g. (34 + 56 + 44 + 23) / 4 = 39.25.
 *
 * Approach: single streaming pass. Keep a running total and a counter; for
 * each value that is non-negative, add it and bump the counter. The first
 * negative read breaks the loop without being counted. Print sum / count as
 * a real number so the fractional part survives.
 *
 * Complexity: O(k) over the k ages read, O(1) space.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sum = 0;   // total of all valid ages (wide type as a safe default)
    int count = 0;       // how many ages were actually read

    int age;
    // Read until a negative sentinel appears (or input ends). The negative
    // value is consumed by the condition and never added to the totals.
    while (cin >> age && age >= 0) {
        sum += age;
        ++count;
    }

    // Divide as floating point so the average keeps its decimals, and print
    // with two decimal places per the required output format.
    double average = static_cast<double>(sum) / count;
    printf("%.2f\n", average);

    return 0;
}

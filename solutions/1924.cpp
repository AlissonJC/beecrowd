/*
 * Beecrowd 1924 - Vitoria and Her Indecision
 *
 * Vitoria is undecided among several bachelor courses. The task description is a
 * joke: no matter which courses appear in the list, the correct choice is always
 * Computer Science. So the program ignores the actual list and always prints the
 * single answer "Ciencia da Computacao" (Portuguese, without accentuation, as
 * required by the statement).
 *
 * Input : an integer n (1 <= n <= 2000), then n lines each with a course name S
 *         (1 <= |S| <= 100). The contents are irrelevant to the answer.
 * Output: the fixed line "Ciencia da Computacao".
 *
 * Approach: constant output. The input does not affect the result, so there is
 * nothing to read or compute.
 * Complexity: O(1) time and space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    // The answer never depends on the input — Computer Science always wins.
    // String is intentionally accent-free per the problem's output rule.
    cout << "Ciencia da Computacao\n";
    return 0;
}

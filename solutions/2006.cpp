/*
 * Beecrowd 2006 - Identifying Tea
 *
 * A tea-tasting show: the real tea type is T (1..4) and five contestants each
 * guess a type. Count how many contestants guessed correctly, i.e. how many of
 * the five answers equal T.
 *
 * Input : first line an integer T (1 <= T <= 4); second line five integers
 *         A B C D E (1 <= each <= 4), the contestants' answers.
 * Output: a single integer, the number of correct guesses.
 *
 * Approach: read T, then read the five answers and increment a counter whenever
 * an answer matches T.
 * Complexity: O(1) time and space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;                 // the correct tea type

    int correct = 0;
    for (int i = 0; i < 5; i++) {
        int guess;
        cin >> guess;
        if (guess == t) correct++;   // this contestant got it right
    }

    cout << correct << "\n";
    return 0;
}

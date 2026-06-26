/*
 * Beecrowd 3302 - Correct Answer
 *
 * For each test case we are given a number N (the number of questions) followed
 * by N values, one per line. The task is simply to echo each value back as the
 * answer to its question, formatted as: the word "resposta", a space, the
 * question number, a colon, a space and the value.
 *
 * Input : several test cases until EOF. Each case is an integer N, then N lines
 *         each holding the value seen for that question.
 * Output: for every question, a line "resposta <i>: <value>", where i runs from
 *         1 to N and RESTARTS at 1 for each new test case.
 *
 * Approach: read N, then read N tokens and print them with a 1-based index that
 * resets per test case. Values are read as strings so any textual form is echoed
 * verbatim (e.g. leading zeros are preserved). Repeat until the stream ends.
 *
 * Complexity: O(total number of questions) time, O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // EOF-terminated outer loop: one iteration per test case.
    while (cin >> n) {
        // Question index restarts at 1 for each test case.
        for (int i = 1; i <= n; i++) {
            string answer;
            cin >> answer;                 // echo the value exactly as read
            // Output keeps the Portuguese word "resposta" required by the judge.
            cout << "resposta " << i << ": " << answer << "\n";
        }
    }

    return 0;
}

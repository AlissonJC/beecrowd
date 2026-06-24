/*
 * Beecrowd 2554 - "Pizza Before BH"
 *
 * A group of N people wants to meet for pizza. There are D candidate dates,
 * given in chronological order (earliest first). For each date we know, per
 * person, whether they can show up (1) or not (0). The meeting can happen on a
 * date only if ALL N people can attend it. Print the earliest such date; if no
 * date works for everyone, print the fallback message.
 *
 * Input : several test cases until EOF. Each case:
 *           line 1 -> N D            (1 <= N, D <= 50)
 *           next D lines -> a date token "day/month/year" followed by N flags
 *                           p1..pN, each 0 or 1. Dates are in increasing order.
 * Output: per case -> the earliest date (printed exactly as read) on which all
 *           N flags are 1, or "Pizza antes de FdI" if none qualifies.
 *
 * Approach  : because dates already arrive earliest-first, the FIRST line whose
 *             flags sum to N is the answer. Scan the D lines once, remember the
 *             first qualifying date, but keep consuming every remaining line so
 *             the stream stays aligned for the next test case.
 * Complexity: O(N * D) per test case, O(1) extra space.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    // EOF-terminated: the loop stops when extraction of N and D fails.
    while (cin >> n >> d) {
        bool found = false;     // whether some date already satisfied everyone
        string answer;          // the earliest qualifying date (printed verbatim)

        for (int i = 0; i < d; i++) {
            string date;        // read as a single token: it has no inner spaces
            cin >> date;

            // Count how many of the N people can attend this date.
            int present = 0;
            for (int j = 0; j < n; j++) {
                int p;
                cin >> p;
                present += p;
            }

            // Record only the FIRST all-attend date (earliest, since input is
            // chronological). Do NOT break: the remaining D-i-1 lines still
            // have to be consumed to keep the next test case aligned.
            if (present == n && !found) {
                found = true;
                answer = date;
            }
        }

        if (found)
            cout << answer << "\n";
        else
            // Verbatim Portuguese fallback ("FdI" = Festa de Integracao); do not translate.
            cout << "Pizza antes de FdI\n";
    }
    return 0;
}

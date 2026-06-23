/*
 * Beecrowd 2727 - "Secret Code"
 *
 * A cipher maps each letter to dots: 'a' -> ".", 'b' -> "..", 'c' -> "...".
 * Longer letters are written as several dot-groups separated by spaces, where
 * every group but the last stands for a full triple (three dots) and the LAST
 * group carries the remainder (1, 2 or 3 dots). So the decoded value is
 *
 *     value = 3 * (number_of_groups - 1) + (dots in the last group)
 *
 * and the letter is 'a' + value - 1. Examples (canonical form):
 *     "... ."         -> 3*1 + 1 = 4  -> 'd'
 *     "... ... .."    -> 3*2 + 2 = 8  -> 'h'
 *     "... ... ... ... ..." -> 3*4 + 3 = 15 -> 'o'
 *
 * Note it is NOT the total dot count: only the count of groups and the size of
 * the last group matter. The leading groups define how many full triples there
 * are regardless of how many dots they actually contain (e.g. ".. .. .. .." has
 * 4 groups ending in 2 -> 3*3 + 2 = 11 -> 'k', even though it holds only 8 dots).
 *
 * Input : several test cases until EOF. Each: N (N <= 50), then N dot-code lines.
 * Output: the decoded letters, one per line.
 *
 * Approach  : split each line into space-separated groups, take the group count
 *             and the last group's length, then apply the formula above.
 * Complexity: O(total input length).
 *
 * I/O note: a code line contains spaces, so it must be read with getline; the
 * groups are then split off with a stringstream.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // EOF-terminated stream of test cases; each starts with the letter count N.
    while (cin >> n) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // past N's line

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);

            // Walk the space-separated dot-groups, tracking how many there are
            // and the size of the last one.
            istringstream ss(line);
            string group;
            int groups = 0, lastLen = 0;
            while (ss >> group) {
                groups++;
                lastLen = (int)group.size();
            }

            // Leading groups are full triples; the last group is the remainder.
            int value = 3 * (groups - 1) + lastLen;
            cout << static_cast<char>('a' + value - 1) << "\n";
        }
    }
    return 0;
}

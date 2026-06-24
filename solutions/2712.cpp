/*
 * Beecrowd 2712 - "Vehicular Restriction"
 *
 * Sao Paulo's rodizio forbids a car from circulating on a given weekday based
 * on the LAST digit of its plate. Given several strings, validate each against
 * the official plate pattern "AAA-9999" and, if valid, print the restriction
 * day implied by the final digit; otherwise print FAILURE.
 *
 * Last digit -> day:
 *   1,2 -> MONDAY     3,4 -> TUESDAY    5,6 -> WEDNESDAY
 *   7,8 -> THURSDAY   9,0 -> FRIDAY
 *
 * Valid pattern (exactly 8 characters):
 *   index 0,1,2 -> uppercase letter [A-Z]
 *   index 3     -> hyphen '-'
 *   index 4,5,6,7 -> digit [0-9]
 *
 * Input : line 1 -> N (1 <= N < 1000); then N lines, each a string of length
 *         up to 100 to be analyzed.
 * Output: per line -> the weekday in uppercase, or FAILURE for a malformed plate.
 *
 * Approach  : validate the fixed-position pattern, then map the last digit to a
 *             weekday with a 10-entry lookup table. O(length) per test.
 * Complexity: O(N * S) time, O(1) extra space.
 *
 * I/O note: tests are read with getline, NOT with >>. A malformed plate may
 * contain a space (e.g. "ABC 1234"); reading whole lines keeps each test on one
 * record so such a string is judged FAILURE instead of desynchronizing input.
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// True only for an exact "AAA-9999" plate: 3 uppercase letters, hyphen, 4 digits.
bool validPlate(const string& s) {
    if (s.size() != 8) return false;
    for (int i = 0; i < 3; i++)
        if (s[i] < 'A' || s[i] > 'Z') return false;
    if (s[3] != '-') return false;
    for (int i = 4; i < 8; i++)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Last-digit -> weekday table (index 0..9). 0 and 9 both fall on Friday.
    const string day[10] = {
        "FRIDAY",    "MONDAY",  "MONDAY",  "TUESDAY",   "TUESDAY",
        "WEDNESDAY", "WEDNESDAY", "THURSDAY", "THURSDAY", "FRIDAY"
    };

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // drop rest of the count line

    string s;
    for (int t = 0; t < n; t++) {
        getline(cin, s);
        if (!s.empty() && s.back() == '\r') s.pop_back();  // defensive CRLF strip

        if (!validPlate(s)) {
            cout << "FAILURE\n";
        } else {
            int lastDigit = s[7] - '0';   // s[7] is the rightmost plate digit
            cout << day[lastDigit] << "\n";
        }
    }
    return 0;
}

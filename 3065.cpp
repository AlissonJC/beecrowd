/*
 * Beecrowd 3065 - Calculando (Calculating)
 *
 * Act as a simple calculator that only adds and subtracts. Each test set gives an
 * arithmetic expression with m operands and evaluates it left to right.
 *
 * Input : several test sets. Each begins with m (1 <= m <= 100); the next line is
 *         the expression "X1 s1 X2 ... s(m-1) Xm" with no spaces, operands in
 *         [0,100] and operators '+'/'-'. Input ends at m = 0.
 * Output: for each set, three lines -- "Teste n" (n from 1), the result, and a
 *         blank line.
 *
 * Approach: only '+' and '-' appear, so there is no precedence to worry about --
 *   scan the string, read the first number, then repeatedly read an operator and
 *   the next number, applying it to a running total. m itself is not needed for
 *   parsing (the string already delimits the operands), only to detect the end.
 *
 * Complexity: O(length of expression) per test set.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, caseNum = 1;
    while (cin >> m && m != 0) {
        string s;
        cin >> s;                            // the expression, one space-free token

        int i = 0;
        auto parseNum = [&]() {
            int v = 0;
            while (i < (int)s.size() && isdigit((unsigned char)s[i]))
                v = v * 10 + (s[i++] - '0');
            return v;
        };

        int result = parseNum();             // first operand
        while (i < (int)s.size()) {
            char op = s[i++];                // '+' or '-'
            int v = parseNum();
            if (op == '+') result += v;
            else           result -= v;
        }

        cout << "Teste " << caseNum++ << "\n";
        cout << result << "\n\n";            // result, then the required blank line
    }
    return 0;
}

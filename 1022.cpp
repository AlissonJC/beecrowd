/*
 * Beecrowd 1022 - "TDA Rational" (Abstract Data Type: Rational number)
 *
 * Read N expressions, each combining two fractions with one operator, and for
 * every expression print the raw resulting fraction, then "=", then the same
 * fraction reduced to lowest terms. Each line has the shape
 *
 *     N1 / D1  op  N2 / D2          op is one of  +  -  *  /
 *
 * with every token separated by a single blank space.
 *
 * The four arithmetic rules are taken verbatim from the statement, with
 * (N1, D1) the first fraction and (N2, D2) the second:
 *     +  ->  (N1*D2 + N2*D1) / (D1*D2)
 *     -  ->  (N1*D2 - N2*D1) / (D1*D2)
 *     *  ->  (N1*N2)         / (D1*D2)
 *     /  ->  (N1*D2)         / (N2*D1)   (dividing fraction 1 by fraction 2)
 *
 * Input : line 1 -> N            (1 <= N <= 10^4) number of test cases
 *         next N lines           each: N1 / D1 op N2 / D2, the four numbers
 *                                positive integers in [1, 1000]
 * Output: per case -> "num/den = rnum/rden\n"  (note the spaces around '=').
 *
 * Approach  : apply the formula for the given operator, print the raw result,
 *             then divide numerator and denominator by their gcd to reduce.
 * Complexity: O(N) overall, O(1) and O(log V) for the gcd per line.
 *
 * Parsing note: the operator is read as the single char sitting BETWEEN the
 * two fractions. This also resolves the tricky division line "1 / 2 / 3 / 4":
 * the middle slash is the operator, so the same read order handles every case.
 *
 * Sign note: only subtraction can make the numerator negative; the denominator
 * is always a product of positive numbers, hence always positive. The sign
 * therefore stays on the numerator and is printed directly (e.g. -2/8 = -1/4).
 */

#include <iostream>
using namespace std;

// Euclidean gcd on magnitudes so it works for a negative numerator too.
// gcd(0, d) returns d, which reduces 0/d to 0/1 - the canonical zero fraction.
long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n1, d1, n2, d2;
        char s1, op, s2;  // s1, s2 absorb the '/' chars; op is the real operator

        // ">>" skips the spaces between tokens, so a char extraction grabs
        // exactly the next non-space symbol: the two slashes and the operator.
        cin >> n1 >> s1 >> d1 >> op >> n2 >> s2 >> d2;

        // den stays positive in every branch; num carries any sign.
        long long num = 0, den = 1;
        switch (op) {
            case '+': num = n1 * d2 + n2 * d1; den = d1 * d2; break;
            case '-': num = n1 * d2 - n2 * d1; den = d1 * d2; break;
            case '*': num = n1 * n2;           den = d1 * d2; break;
            case '/': num = n1 * d2;           den = n2 * d1; break;
        }

        // Reduce by the gcd. den >= 1 always, so g >= 1 and the divisions below
        // are well defined; exact division keeps the sign correct (-2/2 = -1).
        long long g = gcd(num, den);

        // Raw fraction, then "=", then the reduced fraction (same if already reduced).
        cout << num << '/' << den << " = " << num / g << '/' << den / g << '\n';
    }
    return 0;
}

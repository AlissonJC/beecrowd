/*
 * Beecrowd 2761 — Input and Output of Various Types
 * Time limit: 1 s
 *
 * Read one line containing an integer A, a single-precision real B,
 * a character C, and a phrase D (up to 50 chars, possibly containing
 * spaces). Output three lines:
 *   1. The four values concatenated with no separator.
 *   2. The four values separated by 8 spaces ("tabulation").
 *   3. The four values separated by 10 spaces.
 *
 * Notes:
 *   - The problem specifies single-precision real for B (i.e. 32-bit
 *     float). Printing with "%.6f" reproduces the sample rounding
 *     behaviour: 123.141568 stored as float becomes 123.141571 etc.
 *   - The phrase D may contain whitespace, so it has to be read with
 *     a format that stops only at newline ("%[^\\n]").
 */

#include <cstdio>

int main() {
    int a;
    float b;
    char c;
    char d[128];

    // The leading space before %c skips the whitespace left in the
    // buffer by %f. Reading d with " %[^\\n]" then consumes the
    // single space between C and the phrase and grabs the rest.
    scanf("%d %f %c", &a, &b, &c);
    scanf(" %[^\n]", d);

    // Line 1: everything concatenated, no separators at all.
    printf("%d%.6f%c%s\n", a, b, c, d);
    // Line 2: TAB character between fields ("tabulation" in the statement).
    printf("%d\t%.6f\t%c\t%s\n", a, b, c, d);
    // Line 3: each field right-aligned in a 10-character column, no
    // explicit separator between them ("with exactly 10 spaces" = each
    // value padded to a width of 10).
    printf("%10d%10.6f%10c%10s\n", a, b, c, d);

    return 0;
}

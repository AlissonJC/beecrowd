/*
 * Beecrowd 1009 - Salary with Bonus
 *
 * A seller has a fixed salary and earns a 15% commission on the total amount
 * sold in the month. Read the seller's name, fixed salary and total sales, and
 * print the final monthly salary (fixed salary plus 15% of sales).
 *
 * Input : a name (single word), then two double values: the fixed salary and
 *         the total value sold.
 * Output: one line in the exact format (note spaces around '=' and after 'R$',
 *         two decimals): "TOTAL = R$ <total>".
 *
 * Approach: total = salary + 0.15 * sales. Compute in double and print with
 * %.2f; the judge's expected values were produced with the same floating-point
 * arithmetic, so plain %.2f rounding matches them.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    char name[64];
    double salary, sales;
    if (scanf("%63s %lf %lf", name, &salary, &sales) != 3)
        return 0;  // malformed input guard; also silences the warning

    // 15% commission on top of the fixed salary. The name is read only to
    // consume the input; it is not part of the output.
    double total = salary + 0.15 * sales;

    printf("TOTAL = R$ %.2f\n", total);
    return 0;
}

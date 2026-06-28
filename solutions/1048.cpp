/*
 * Beecrowd 1048 - Salary Increase
 *
 * Read an employee's salary and apply a readjustment whose rate depends on the
 * salary bracket:
 *     salary <=  400.00 -> 15%
 *     salary <=  800.00 -> 12%
 *     salary <= 1200.00 -> 10%
 *     salary <= 2000.00 ->  7%
 *     salary >  2000.00 ->  4%
 * Print the new salary, the money gained, and the percentage applied.
 *
 * Input : one floating-point number with two decimals (the current salary).
 * Output: three Portuguese lines (printed verbatim):
 *     "Novo salario: <new>"      -> new salary, two decimals
 *     "Reajuste ganho: <raise>"  -> money gained, two decimals
 *     "Em percentual: <p> %"     -> integer percentage, a space, then '%'
 *
 * Approach: A simple bracket lookup chooses the integer percentage. Because the
 * input has exactly two decimals and every bracket boundary ends in ".00"
 * (values exactly representable in double), the "<=" chain assigns boundary
 * salaries to the correct (lower) bracket without any floating-point ambiguity:
 * e.g. 400.00 stays at 15% while 400.01 moves up to 12%.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    double salary;
    scanf("%lf", &salary);

    // Choose the percentage by bracket. The first matching upper bound wins,
    // so the cheaper brackets must be tested first.
    int percent;
    if (salary <= 400.00) {
        percent = 15;
    } else if (salary <= 800.00) {
        percent = 12;
    } else if (salary <= 1200.00) {
        percent = 10;
    } else if (salary <= 2000.00) {
        percent = 7;
    } else {
        percent = 4;
    }

    // Money gained from the raise and the resulting salary. Keep the raise
    // unrounded; printf's %.2f handles the two-decimal rounding for display
    // (e.g. 800.01 * 0.10 = 80.001 -> "80.00", new salary -> "880.01").
    double raise = salary * percent / 100.0;
    double newSalary = salary + raise;

    // Portuguese labels reproduced verbatim; note the space before '%'.
    printf("Novo salario: %.2f\n", newSalary);
    printf("Reajuste ganho: %.2f\n", raise);
    printf("Em percentual: %d %%\n", percent);

    return 0;
}

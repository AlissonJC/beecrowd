/*
 * Beecrowd 1008 - Salary
 *
 * Read an employee's number, the number of hours worked in a month and the
 * amount paid per hour, then print the employee's number and the monthly
 * salary (hours * hourly rate) with two decimal places.
 *
 * Input : an integer (employee number), an integer (hours worked) and a
 *         floating-point value (amount per worked hour).
 * Output: two lines in the exact format below -- note the spaces around '='
 *         and after 'U$', and exactly two decimals on the salary:
 *           NUMBER = <number>
 *           SALARY = U$ <salary>
 *
 * Approach: Multiply hours by the hourly rate. Use double for the rate and the
 * product so the cents are preserved, and format with %.2f.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    int number, hours;
    double perHour;
    if (scanf("%d %d %lf", &number, &hours, &perHour) != 3)
        return 0;  // malformed input guard; also silences the warning

    double salary = hours * perHour;

    // Exact format required by the judge: spaces around '=', a space after
    // 'U$', and two decimal places.
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", salary);

    return 0;
}

/*
 * Beecrowd 1051 - Taxes
 *
 * Read a salary and print the income tax due under a PROGRESSIVE (marginal)
 * bracket schedule, where each rate applies only to the portion of the salary
 * that falls inside its band:
 *      0.00 .. 2000.00 -> tax free
 *   2000.01 .. 3000.00 ->  8%
 *   3000.01 .. 4500.00 -> 18%
 *   above 4500.00      -> 28%
 *
 * Input : one floating-point salary with two decimals.
 * Output: "R$ <tax>" with two decimals, or "Isento" (exempt) when the salary
 *         is up to 2000.00.
 *
 * Approach: This is marginal taxation, not a single flat rate on the whole
 * salary. Each band contributes rate * (portion of salary inside that band).
 * The lower bands are fully filled once the salary passes them: the 8% band is
 * at most 1000 wide (2000->3000) and the 18% band at most 1500 wide
 * (3000->4500). So accumulate the completed bands as constants and apply the
 * top rate only to the salary above that band's floor. The statement's example
 * confirms this: 3002 pays 8% over 1000 plus 18% over 2 = 80.36.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <cstdio>

int main() {
    double salary;
    scanf("%lf", &salary);

    if (salary <= 2000.00) {
        // Entire salary sits in the tax-free band.
        printf("Isento\n");
    } else {
        double tax;
        if (salary <= 3000.00) {
            // Only the slice above 2000 is taxed, all at 8%.
            tax = (salary - 2000.00) * 0.08;
        } else if (salary <= 4500.00) {
            // 8% band (2000->3000) is full: 1000 * 0.08 = 80. The 18% band is
            // filled only up to the salary.
            tax = 1000.00 * 0.08 + (salary - 3000.00) * 0.18;
        } else {
            // Both lower bands full (80 + 1500 * 0.18 = 80 + 270); 28% on the
            // excess above 4500.
            tax = 1000.00 * 0.08 + 1500.00 * 0.18 + (salary - 4500.00) * 0.28;
        }
        // "R$" + single space + amount with two decimals.
        printf("R$ %.2f\n", tax);
    }

    return 0;
}

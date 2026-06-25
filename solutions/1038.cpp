/*
 * Beecrowd 1038 - Snack
 *
 * A snack bar has five items, each identified by a code (1..5) with a fixed
 * unit price:
 *     1 -> R$ 4.00   2 -> R$ 4.50   3 -> R$ 5.00   4 -> R$ 2.00   5 -> R$ 1.50
 * Read a product code X and a quantity Y, then print the total amount to pay.
 *
 * Input : two integers X and Y -- X is the product code, Y is the quantity.
 * Output: the line "Total: R$ " followed by (unit price * quantity) printed
 *         with exactly two digits after the decimal point, plus a trailing
 *         newline (omitting it causes a Presentation Error on Beecrowd). Note
 *         the single space after "R$".
 *
 * Approach: store the five unit prices in a lookup table indexed by code, so
 *           the selection is a single array access rather than a chain of ifs.
 *           Multiply the looked-up price by the quantity to get the total.
 *
 * Complexity: O(1) time and space.
 */

#include <cstdio>

int main() {
    // Index 0 is unused so that price[code] maps directly to each code 1..5.
    const double price[6] = {0.0, 4.00, 4.50, 5.00, 2.00, 1.50};

    int code, quantity;
    if (scanf("%d %d", &code, &quantity) != 2) return 0;

    double total = price[code] * quantity;

    // %.2f matches the required two-decimal money format; keep the space after
    // "R$" exactly as shown in the sample output.
    printf("Total: R$ %.2f\n", total);
    return 0;
}

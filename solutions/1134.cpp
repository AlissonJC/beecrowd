/*
 * Beecrowd 1134 - Type of Fuel
 *
 * A gas station wants to know which fuel its customers prefer. Each customer's
 * choice arrives as an integer code: 1 = Alcohol, 2 = Gasoline, 3 = Diesel,
 * 4 = End. Any code outside the range 1..4 is invalid; it is ignored and a new
 * code is requested (i.e. we simply keep reading). Processing stops as soon as
 * the code 4 is supplied.
 *
 * Input : a sequence of positive integers, one value at a time, terminated by 4.
 * Output: the line "MUITO OBRIGADO" followed by the number of customers for
 *         each fuel type, using the exact Portuguese labels from the sample
 *         (ASCII, no accents): "Alcool", "Gasolina", "Diesel". A trailing
 *         newline is required, otherwise Beecrowd reports a Presentation Error.
 *
 * Approach: a single pass over the input. Keep three counters and switch on
 *           each code -- increment the matching fuel, break out of the loop on
 *           4, and ignore everything else (an invalid code costs nothing; the
 *           next read is the implicitly requested new code).
 *
 * Complexity: O(K) time over the K input values, O(1) extra space.
 */

#include <cstdio>

int main() {
    int alcool = 0, gasolina = 0, diesel = 0;
    int code;

    // Keep reading codes until the terminator (4) or end of input is reached.
    while (scanf("%d", &code) == 1) {
        if (code == 4) break;          // 4 = End: stop processing immediately.
        else if (code == 1) ++alcool;  // 1 = Alcohol
        else if (code == 2) ++gasolina;// 2 = Gasoline
        else if (code == 3) ++diesel;  // 3 = Diesel
        // Any other value is an invalid code: skip it. The next iteration's
        // read serves as the "new code" the statement asks us to request.
    }

    // Labels must match the Output Sample byte-for-byte: ASCII, no accents.
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);

    return 0;
}

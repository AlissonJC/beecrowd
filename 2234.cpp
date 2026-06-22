/*
 * Beecrowd 2234 — Hot Dogs
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Given the total number of hot dogs H consumed in a contest and the
 *   number of contestants P, compute the average number of hot dogs per
 *   participant. Print the result with exactly two digits after the
 *   decimal point, rounded if necessary.
 *
 * Input:
 *   One line with two integers H and P (1 <= H, P <= 1000).
 *
 * Output:
 *   The value H / P with two decimal places. The 0.035 -> 0.04 sample
 *   confirms that the judge expects glibc's default banker's rounding
 *   (round-half-to-even), which is what "%.2f" already does.
 *
 * Approach:
 *   Cast H to double before dividing to force floating-point arithmetic,
 *   then print with "%.2f". Nothing fancier is needed.
 *
 * Complexity:
 *   O(1).
 */

#include <cstdio>

int main() {
    int H, P;
    scanf("%d %d", &H, &P);

    // Cast first operand to force float division (integer / integer
    // would truncate to 0 for every H < P, breaking the sample 10/90).
    double avg = (double) H / P;
    printf("%.2f\n", avg);
    return 0;
}

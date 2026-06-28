/*
 * Beecrowd 1064 - Positives and Average
 *
 * Read six values (which may be floating point), count how many are positive,
 * and print that count followed by the average of the positive values.
 *
 * Input : six numbers (integer or floating point), one per line.
 * Output: line 1 -> "<n> valores positivos" (Portuguese, "n positive values");
 *         line 2 -> the average of the positive values, one decimal place.
 *
 * Constraints: at least one of the six numbers is positive, so the average is
 * always over a non-empty set (no division by zero).
 *
 * Approach: Single pass over the six numbers. A value counts as positive when
 * it is strictly greater than zero (zero is not positive). Accumulate the sum
 * and count of positives, then divide.
 *
 * Complexity: O(1) time (six values), O(1) space.
 */

#include <cstdio>

int main() {
    int count = 0;       // how many positives seen
    double sum = 0.0;    // running sum of the positives only

    // Exactly six values to read.
    for (int i = 0; i < 6; ++i) {
        double x;
        scanf("%lf", &x);
        // Strictly positive only: zero and negatives are excluded.
        if (x > 0) {
            sum += x;
            ++count;
        }
    }

    // Count line uses the Portuguese label exactly as the sample shows it.
    printf("%d valores positivos\n", count);
    // Average of the positives; the problem guarantees count >= 1.
    printf("%.1f\n", sum / count);

    return 0;
}

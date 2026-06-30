/*
 * Beecrowd 1098 - Sequence IJ 4
 *
 * Print a fixed sequence (the program reads no input). The outer value I runs
 * from 0 to 2 in steps of 0.2; for every I, three lines are printed where the
 * inner value J equals 1+I, 2+I and 3+I respectively.
 *
 * Input : none.
 * Output: 33 lines of the form "I=<i> J=<j>".
 *
 * Output format note: the sample prints "I=0 J=1" and "I=2 J=5" with NO decimal
 * digits, but "I=0.2 J=1.2" with one digit. That is the behaviour of printf's
 * "%g" conversion (trailing zeros stripped), not a fixed "%.1f". Using "%.1f"
 * here would print "I=0.0 J=1.0" and get Wrong Answer.
 *
 * Two correctness details:
 *   1. The loop is driven by an integer counter k = 0..10 and I is recomputed as
 *      k * 0.2 each step. Accumulating "i += 0.2" in a double risks the final
 *      value landing slightly above 2.0, which would drop the whole I=2 block.
 *   2. "%g" defaults to 6 significant digits, which safely absorbs the ~1e-16
 *      rounding error in values like 3*0.2 = 0.6000000000000001 -> "0.6".
 *
 * Complexity: O(1) - exactly 33 lines are produced.
 */
#include <cstdio>

int main() {
    // k = 0..10 maps to I = 0.0, 0.2, ..., 2.0 (11 distinct values).
    for (int k = 0; k <= 10; ++k) {
        double i = k * 0.2;

        // For each I, J takes the three bases 1, 2, 3 shifted by I.
        for (int base = 1; base <= 3; ++base) {
            double j = base + i;
            // "%g" prints integers without a decimal point and otherwise the
            // minimal decimal form, matching the statement's sample exactly.
            std::printf("I=%g J=%g\n", i, j);
        }
    }

    return 0;
}

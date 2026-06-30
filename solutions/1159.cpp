/*
 * Beecrowd 1159 - Sum of Consecutive Even Numbers
 *
 * Read integers X repeatedly until a value of 0 is read (the 0 is a sentinel and
 * is not processed). For each X, sum the first five consecutive even numbers
 * starting at X itself when X is even, or starting at the next even number X+1
 * when X is odd. Print one sum per input value.
 *
 * Examples: X = 4  -> 4+6+8+10+12 = 40;  X = 11 -> 12+14+16+18+20 = 80.
 *
 * Input : many integers, one per read; the final value is 0 and ends the input.
 * Output: for each X (excluding the terminating 0), the computed sum on its own
 *         line.
 *
 * Approach: let "first" be the first even number >= X in parity terms (X if even,
 *           else X+1). The five consecutive evens are first, first+2, first+4,
 *           first+6, first+8, whose sum collapses to 5*first + 20. Using X % 2
 *           to test parity is also correct for negative X, since an odd negative
 *           gives a non-zero remainder and is bumped to X+1.
 *
 * Type choice: long long is used so that 5*first cannot overflow even if X is
 *           large (no explicit upper bound is given in the statement).
 *
 * Complexity: O(1) per value, O(K) overall for K input values.
 */
#include <cstdio>

int main() {
    long long x;

    // Read until the terminating zero (or end of input as a safety net).
    while (scanf("%lld", &x) == 1 && x != 0) {
        // Start at X if it is even, otherwise at the next even number X+1.
        long long first = (x % 2 == 0) ? x : x + 1;

        // first + (first+2) + (first+4) + (first+6) + (first+8) = 5*first + 20.
        long long sum = 5 * first + 20;
        printf("%lld\n", sum);
    }

    return 0;
}

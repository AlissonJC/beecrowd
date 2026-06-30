/*
 * Beecrowd 1179 - Array Fill IV
 *
 * Read 15 integers and route each into one of two 5-slot buffers: "par" for even
 * numbers and "impar" for odd numbers. Whenever a buffer becomes full (5 values)
 * its entire contents are printed and the buffer is emptied so it can be reused
 * for the numbers that follow. After all 15 numbers are read, whatever remains in
 * the buffers is printed, starting with the odd ("impar") buffer and then the
 * even ("par") buffer.
 *
 * Input : 15 integers.
 * Output: lines "par[i] = Y" / "impar[i] = Y" (labels kept in Portuguese), where
 *         i is the slot inside the current buffer fill (it restarts at 0 after
 *         each flush) and Y is the stored value.
 *
 * Approach: maintain the two fixed-size buffers with separate fill counters.
 *           Classify each number by parity (num % 2 == 0 is even; this is correct
 *           for negatives too, since an odd negative leaves a non-zero remainder)
 *           and append it; on reaching 5, dump slots 0..4 and reset the counter.
 *           At the end, flush the leftovers in the required odd-then-even order.
 *
 * Complexity: O(1) - a fixed 15 inputs and at most a handful of flushes.
 */
#include <cstdio>

int main() {
    int par[5], impar[5];      // even and odd buffers, 5 slots each
    int pCount = 0, iCount = 0; // how many slots of each buffer are currently used

    for (int k = 0; k < 15; ++k) {
        int num;
        if (scanf("%d", &num) != 1) break;

        if (num % 2 == 0) {
            par[pCount++] = num;
            if (pCount == 5) {                 // even buffer full -> print and reset
                for (int i = 0; i < 5; ++i) printf("par[%d] = %d\n", i, par[i]);
                pCount = 0;
            }
        } else {
            impar[iCount++] = num;
            if (iCount == 5) {                 // odd buffer full -> print and reset
                for (int i = 0; i < 5; ++i) printf("impar[%d] = %d\n", i, impar[i]);
                iCount = 0;
            }
        }
    }

    // Leftovers: the odd buffer is printed first, then the even buffer.
    for (int i = 0; i < iCount; ++i) printf("impar[%d] = %d\n", i, impar[i]);
    for (int i = 0; i < pCount; ++i) printf("par[%d] = %d\n", i, par[i]);

    return 0;
}

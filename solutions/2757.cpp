/*
 * Beecrowd 2757 - Input and Output of Integers
 *
 * Read three integers A, B, C and print them four times in the fixed layout
 * "A = <a>, B = <b>, C = <c>", changing only how each number is padded:
 *   1) natural width;
 *   2) width 10, right-justified (spaces on the left);
 *   3) width 10, zero-filled;
 *   4) width 10, left-justified (spaces on the right).
 *
 * Input : several test files, each three lines with A (-10000..10000),
 *         B (0..99), C (0..999). Read until end of file.
 * Output: four formatted lines per test case, exactly as the samples show.
 *
 * Approach: this is purely an output-format exercise -- each variant maps to a
 *   printf conversion: %d, %10d (right), %010d (zero pad, sign kept before the
 *   zeros), and %-10d (left, hence trailing spaces). Print them verbatim.
 *
 * Complexity: O(1) per test case.
 */

#include <cstdio>

int main() {
    int A, B, C;
    // EOF-terminated: keep reading triples until the input is exhausted.
    while (scanf("%d %d %d", &A, &B, &C) == 3) {
        printf("A = %d, B = %d, C = %d\n", A, B, C);               // natural width
        printf("A = %10d, B = %10d, C = %10d\n", A, B, C);          // right-justified
        printf("A = %010d, B = %010d, C = %010d\n", A, B, C);       // zero-filled
        printf("A = %-10d, B = %-10d, C = %-10d\n", A, B, C);       // left-justified
    }
    return 0;
}

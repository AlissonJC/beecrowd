/*
 * Beecrowd 1186 — Below the Secondary Diagonal
 *
 * Read an uppercase character ('S' for Sum or 'M' for Média/Average) and a
 * 12x12 matrix of floating-point numbers. Compute the operation over only
 * the cells that lie strictly BELOW the secondary diagonal of the matrix.
 *
 * The secondary diagonal of a 12x12 matrix M is the set of cells where
 * i + j == 11 (top-right to bottom-left). "Below" the secondary diagonal
 * is the triangular region where i + j > 11 — the green area in the
 * problem figure. The yellow cells on the diagonal itself are NOT counted.
 *
 * Number of cells below the secondary diagonal in a 12x12 matrix:
 *   for i = 0..11, count of j with i + j > 11 is i
 *   total = 0 + 1 + 2 + ... + 11 = 66 cells
 *
 * Input format:
 *   Line 1: a single character, 'S' or 'M'.
 *   Then: 144 floating-point numbers (row-major, whitespace-separated)
 *         filling matrix M[12][12].
 *
 * Output format:
 *   The sum (if 'S') or the average (if 'M') over the 66 cells,
 *   printed with exactly one digit after the decimal point, terminated
 *   by a newline. Beecrowd is strict about the trailing '\n'.
 *
 * Approach: straightforward simulation.
 *   1. Read the operation character.
 *   2. Read 144 doubles into M[12][12].
 *   3. Iterate cells, accumulate sum when i + j > 11.
 *   4. Divide by 66 if 'M'; print with %.1f.
 *
 * Complexity: O(144) time, O(144) space — trivially within limits.
 */

#include <cstdio>

int main() {
    char op;
    // Read the operation indicator. %c with leading space skips any
    // preceding whitespace/newlines, which is robust to varied input
    // formatting on Beecrowd.
    scanf(" %c", &op);

    double M[12][12];
    // Read all 144 entries of the matrix in row-major order.
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Accumulate values strictly BELOW the secondary diagonal.
    // The secondary diagonal itself (i + j == 11) is excluded — only
    // i + j > 11 qualifies, matching the green region in the figure.
    double sum = 0.0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (i + j > 11) {
                sum += M[i][j];
            }
        }
    }

    // For 'M' (Média = Average in Portuguese), divide by the exact
    // count of cells below the diagonal: 0+1+...+11 = 66.
    if (op == 'M') {
        sum /= 66.0;
    }

    // Print with one decimal place plus the mandatory trailing newline.
    printf("%.1f\n", sum);
    return 0;
}

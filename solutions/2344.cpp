/*
 * Beecrowd 2344 — Notas da Prova (Test Grades)
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Convert a numeric grade N (0 to 100) into a letter concept using a
 *   fixed table, where A is the highest concept and E the lowest:
 *       0          -> E
 *       1  to 35   -> D
 *       36 to 60   -> C
 *       61 to 85   -> B
 *       86 to 100  -> A
 *
 * Input:
 *   A single line with one integer N (0 <= N <= 100).
 *
 * Output:
 *   A single uppercase letter (A, B, C, D or E) — the matching concept.
 *
 * Approach:
 *   Direct range lookup. Test the boundaries from low to high; the first
 *   matching range fixes the letter. Using "<=" upper bounds in order
 *   means each branch only needs to compare against the range's top.
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    // Walk the ranges from lowest to highest. The special case N == 0
    // maps to E; everything else falls into the next matching band.
    // Note: 'concept' is a reserved keyword in C++20, so name it 'letter'.
    char letter;
    if (n == 0)        letter = 'E';
    else if (n <= 35)  letter = 'D';   // 1 .. 35
    else if (n <= 60)  letter = 'C';   // 36 .. 60
    else if (n <= 85)  letter = 'B';   // 61 .. 85
    else               letter = 'A';   // 86 .. 100

    printf("%c\n", letter);

    return 0;
}

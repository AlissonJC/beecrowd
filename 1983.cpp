/*
 * Beecrowd 1983 — The Chosen
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Pick the student with the highest grade out of n students. Each
 *   student is given as (registration number, grade). Grades are
 *   pairwise distinct. If the top grade is at least 8 print that
 *   student's registration number; otherwise print the English string
 *   "Minimum note not reached" (verbatim from the problem statement).
 *
 * Input:
 *   Line 1: n (3 <= n <= 100).
 *   Next n lines: m grade  with 0 < m < 1000000 and 0 <= grade <= 10.0
 *   (one decimal place).
 *
 * Output:
 *   Either the chosen student's registration number, or the message
 *   "Minimum note not reached" (without quotes).
 *
 * Approach:
 *   Linear scan, tracking the running maximum grade and the
 *   registration that goes with it. Compare against 8 at the end.
 *
 * Complexity:
 *   O(n).
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    int bestReg = -1;
    double bestGrade = -1.0;
    for (int i = 0; i < n; i++) {
        int reg;
        double grade;
        scanf("%d %lf", &reg, &grade);
        if (grade > bestGrade) {
            bestGrade = grade;
            bestReg = reg;
        }
    }

    if (bestGrade >= 8.0) {
        printf("%d\n", bestReg);
    } else {
        // Output string is English (per the problem statement); do not
        // translate to Portuguese.
        puts("Minimum note not reached");
    }
    return 0;
}

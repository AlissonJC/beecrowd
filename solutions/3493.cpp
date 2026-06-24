/*
 * Beecrowd 3493 — Stacked Cups
 * Time limit: 1 s
 *
 * Multiple test cases (EOF-terminated). Each contains two integers
 * A and B (1 <= A <= 100, 1 <= B <= 100): the current record and the
 * stack height built in class. Print "ok" when the record is broken
 * (B > A) and "no" otherwise.
 */

#include <cstdio>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        puts(b > a ? "ok" : "no");
    }
    return 0;
}

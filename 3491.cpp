/*
 * Beecrowd 3491 — Encoded Note
 *
 * Read integers N (1..26) until EOF; each one stands for a lowercase
 * letter ('a' = 1, ..., 'z' = 26). Concatenate the letters in input
 * order and print them on a single line.
 */

#include <cstdio>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        putchar('a' + (n - 1));
    }
    putchar('\n');
    return 0;
}

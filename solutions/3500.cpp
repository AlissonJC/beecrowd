/*
 * Beecrowd 3500 — Inversao de Numero (Number Reversal)
 *
 * Read a 3-digit number and print its digit-reversed value, formatted
 * as "Invertido = X".
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int rev = (n % 10) * 100 + ((n / 10) % 10) * 10 + (n / 100);
    printf("Invertido = %d\n", rev);
    return 0;
}

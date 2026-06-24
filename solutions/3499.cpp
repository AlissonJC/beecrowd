/*
 * Beecrowd 3499 — Bella, the saucy puppy
 * Time limit: 1 s
 *
 * Read an integer N (0 <= N <= 100), the number of mischiefs Bella
 * made during the week. Bella earns the cookie iff N <= 3.
 *
 * Output strings are in Portuguese per the original statement:
 *   - "vai ganhar o biscoito"      -> will get the cookie
 *   - "vai ficar sem o biscoito"   -> will not get the cookie
 */

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    puts(n <= 3 ? "vai ganhar o biscoito" : "vai ficar sem o biscoito");
    return 0;
}

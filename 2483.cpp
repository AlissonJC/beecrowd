/*
 * Beecrowd 2483 — Merry Christmaaas!
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Print the Portuguese "Merry Christmas!" greeting "Feliz natal!" but
 *   stretch the last 'a' (the one before 'l!') by repeating it I times
 *   according to a given happiness index. So for I = 5 the output is
 *   "Feliz nataaaaal!" -- five a's between "Feliz nat" and "l!".
 *
 * Input:
 *   A single integer I (1 < I <= 10^4).
 *
 * Output:
 *   "Feliz nat" followed by exactly I copies of 'a', followed by "l!"
 *   and a newline. The Portuguese greeting is kept verbatim per the
 *   problem statement.
 *
 * Approach:
 *   Print the prefix "Feliz nat", emit I 'a' characters in a loop,
 *   print the suffix "l!" and a newline.
 *
 * Complexity:
 *   O(I) characters, up to ~10^4. Trivial.
 */

#include <cstdio>

int main() {
    int i;
    scanf("%d", &i);

    // The greeting decomposes as "Feliz nat" + ('a' * I) + "l!".
    // Keep the Portuguese spelling verbatim -- this is the literal text
    // the judge expects, not a translation.
    fputs("Feliz nat", stdout);
    for (int k = 0; k < i; k++) {
        putchar('a');
    }
    puts("l!");
    return 0;
}

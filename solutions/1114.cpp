/*
 * Beecrowd 1114 - Fixed Password
 *
 * Keep reading integer passwords until the correct one, 2002, is read. For every
 * wrong password print "Senha Invalida"; when 2002 is read print
 * "Acesso Permitido" and stop the program.
 *
 * Input : several integers, one per test case, ending when 2002 is read (or EOF).
 * Output: "Senha Invalida" for each wrong attempt, then "Acesso Permitido".
 *
 * Approach: a read loop -- print the rejection message until 2002 appears, then
 *   print the acceptance message and break.
 *
 * Complexity: O(k) for k attempts read.
 */

#include <cstdio>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 2002) {
            // Output strings follow the sample exactly: ASCII, no accent on
            // "Invalida", capital I -- do not use the accented "inválida".
            printf("Acesso Permitido\n");
            break;
        }
        printf("Senha Invalida\n");
    }
    return 0;
}

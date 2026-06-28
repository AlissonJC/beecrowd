/*
 * Beecrowd 1050 - DDD
 *
 * Read an integer area code (DDD) used for phone dialing and print the
 * corresponding destination city. If the code is not in the known table,
 * print "DDD nao cadastrado" ("DDD not registered").
 *
 * Input : a single integer (the area code).
 * Output: the city name for that code, or "DDD nao cadastrado" when unknown.
 *         City names are printed in ASCII exactly as the statement shows them
 *         (no accents), e.g. "Sao Paulo", "Brasilia", "Vitoria".
 *
 * Approach: A direct lookup. Since the set of codes is tiny and fixed, a switch
 * on the integer code maps each known DDD to its city; the default branch
 * handles every unregistered code.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int ddd;
    std::cin >> ddd;

    // Fixed code -> city table. The strings are reproduced verbatim from the
    // problem (ASCII, no accents); do not translate or re-accent them.
    switch (ddd) {
        case 61: std::cout << "Brasilia\n";       break;
        case 71: std::cout << "Salvador\n";       break;
        case 11: std::cout << "Sao Paulo\n";      break;
        case 21: std::cout << "Rio de Janeiro\n"; break;
        case 32: std::cout << "Juiz de Fora\n";   break;
        case 19: std::cout << "Campinas\n";       break;
        case 27: std::cout << "Vitoria\n";        break;
        case 31: std::cout << "Belo Horizonte\n"; break;
        // Any code outside the table is reported as not registered.
        default: std::cout << "DDD nao cadastrado\n"; break;
    }

    return 0;
}

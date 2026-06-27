/*
 * Beecrowd 2936 - How Much Cassava?
 *
 * Five guests each request a number of cassava servings, and each guest's
 * serving has a fixed size in grams. The host, Dona Chica, always eats a fixed
 * 225 grams herself. Given how many servings each guest will eat, compute the
 * total grams of cassava that must be prepared.
 *
 * Serving sizes (grams): Curupira 300, Boitata 1500, Boto 600,
 *                        Mapinguari 1000, Iara 150. Dona Chica: fixed 225.
 *
 * Input : five integers (each 1..10) -- the serving counts for Curupira,
 *         Boitata, Boto, Mapinguari and Iara, in that order.
 * Output: a single integer, the total grams to prepare, followed by a newline.
 *
 * Approach: Multiply each guest's serving count by its gram size, sum them,
 * and add Dona Chica's constant 225 grams.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int curupira, boitata, boto, mapinguari, iara;
    std::cin >> curupira >> boitata >> boto >> mapinguari >> iara;

    // Weighted total: each serving count scaled by its fixed portion size,
    // plus Dona Chica's own fixed 225 grams.
    int total = 300 * curupira
              + 1500 * boitata
              + 600 * boto
              + 1000 * mapinguari
              + 150 * iara
              + 225;

    std::cout << total << "\n";
    return 0;
}

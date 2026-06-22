/*
 * Beecrowd 2313 — Which Triangle
 *
 * Given three integer side lengths, decide whether they form a valid triangle.
 * If they do, classify it as equilateral, isosceles or scalene, and report
 * whether it is a right triangle.
 *
 * Input:
 *   Three integers A, B, C (0 < A, B, C < 10^5). Read until EOF for safety.
 *
 * Output:
 *   "Invalido" if the values cannot form a triangle. Otherwise two lines:
 *     "Valido-Equilatero" / "Valido-Isoceles" / "Valido-Escaleno"
 *   then
 *     "Retangulo: S" if it is a right triangle, "Retangulo: N" otherwise.
 *
 * Approach:
 *   Sort the three sides as x <= y <= z. They form a (non-degenerate) triangle
 *   iff x + y > z. The number of equal sides gives the class. With sides
 *   sorted, it is a right triangle iff x^2 + y^2 == z^2; squares reach 10^10,
 *   so use 64-bit arithmetic.
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a, b, c;
    while (std::cin >> a >> b >> c) {
        long long s[3] = {a, b, c};
        std::sort(s, s + 3);        // s[0] <= s[1] <= s[2]

        // Triangle inequality: with sorted sides, only the largest needs check.
        if (s[0] + s[1] <= s[2]) {
            std::cout << "Invalido\n";
            continue;
        }

        // Classify by how many sides are equal (equal sides are adjacent here).
        if (s[0] == s[1] && s[1] == s[2])
            std::cout << "Valido-Equilatero\n";
        else if (s[0] == s[1] || s[1] == s[2])
            std::cout << "Valido-Isoceles\n";
        else
            std::cout << "Valido-Escaleno\n";

        // Right triangle: the largest side s[2] would be the hypotenuse.
        bool right = s[0] * s[0] + s[1] * s[1] == s[2] * s[2];
        std::cout << "Retangulo: " << (right ? 'S' : 'N') << '\n';
    }

    return 0;
}

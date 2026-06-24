/*
 * Beecrowd 2759 — Input and Output Character
 *
 * Read three single characters (A, B, C) and print three lines that cyclically
 * rotate them to the left:
 *   line 1: A = v1, B = v2, C = v3
 *   line 2: A = v2, B = v3, C = v1
 *   line 3: A = v3, B = v1, C = v2
 *
 * Input:
 *   Several test cases until EOF. Each case has three lines, one character each
 *   (the values of A, B, C).
 *
 * Output:
 *   For each case, the three rotated lines in the format "A = x, B = y, C = z".
 *
 * Complexity:
 *   O(1) per test case.
 */

#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char a, b, c;
    // >> skips the newlines between the three single-character lines.
    while (std::cin >> a >> b >> c) {
        std::cout << "A = " << a << ", B = " << b << ", C = " << c << '\n';
        std::cout << "A = " << b << ", B = " << c << ", C = " << a << '\n';
        std::cout << "A = " << c << ", B = " << a << ", C = " << b << '\n';
    }

    return 0;
}

/*
 * Beecrowd 1914 - Whose Turn Is It?
 *
 * Two players play "odd or even" (par ou impar). Each picks a side, "PAR" (even)
 * or "IMPAR" (odd), and announces a number. If the sum of the two numbers is
 * even, the player who chose PAR wins; if the sum is odd, the player who chose
 * IMPAR wins. The two players always choose different sides. Report the winner.
 *
 * Input : first line QT, the number of test cases (1 <= QT <= 100). Each test
 *         case has two lines: "name1 choice1 name2 choice2" then two integers
 *         N and M (1 <= N, M <= 10^9), the numbers chosen by players 1 and 2.
 * Output: for each test case, the winning player's name on its own line.
 *
 * Approach: the winning side is decided purely by the parity of N + M - PAR on
 *           an even sum, IMPAR on an odd sum. Since the two choices differ,
 *           exactly one player holds the winning side, so compare player 1's
 *           choice to the winning side and print the matching name.
 *
 * Type choice: N + M can reach 2*10^9, which overflows 32-bit signed int, so the
 *           numbers are read into long long.
 *
 * Complexity: O(QT) time, O(1) space.
 */
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int qt;
    if (!(std::cin >> qt)) return 0;

    while (qt--) {
        std::string name1, choice1, name2, choice2;
        long long n, m;
        std::cin >> name1 >> choice1 >> name2 >> choice2 >> n >> m;

        // Even sum -> the PAR side wins; odd sum -> the IMPAR side wins.
        std::string winningChoice = ((n + m) % 2 == 0) ? "PAR" : "IMPAR";

        // Exactly one player holds the winning side (choices are guaranteed
        // different), so player 1 wins iff their choice is the winning one.
        std::cout << (choice1 == winningChoice ? name1 : name2) << '\n';
    }

    return 0;
}

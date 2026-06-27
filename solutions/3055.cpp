/*
 * Beecrowd 3055 - Forgotten Grade
 *
 * Joao took two Geography tests whose integer grades average to an integer M,
 * where M = (A + B) / 2. He remembers one grade A and the average M but forgot
 * the other grade B. Recover B.
 *
 * Solving M = (A + B) / 2 for B gives B = 2 * M - A.
 *
 * Input : two lines, integers A and M (0 <= A <= 100, 0 <= M <= 100): the
 *         remembered grade and the average of the two grades.
 * Output: a single integer, the other (forgotten) grade B.
 *
 * Approach: Rearrange the average formula to isolate the missing grade.
 *
 * Complexity: O(1) time, O(1) space.
 */

#include <iostream>

int main() {
    int a, m;
    std::cin >> a >> m;

    // From M = (A + B) / 2, the missing grade is B = 2*M - A.
    std::cout << (2 * m - a) << "\n";

    return 0;
}

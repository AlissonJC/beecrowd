/*
 * Beecrowd 2861 - The Output
 *
 * Three friends answer every question the teacher asks with the same magic
 * word, "gzuz". Given the questions, reproduce their answers: for each
 * question asked, output the word "gzuz".
 *
 * Input : possibly several test cases until end of file. Each case starts with
 *         an integer C (2 <= C <= 99), the number of questions, followed by C
 *         lines, each holding one question (its text is irrelevant).
 * Output: for every question, print a line containing exactly "gzuz".
 *
 * Approach: The questions' contents never matter -- the answer is always the
 * fixed string. Read C, then consume the C question lines (so that, if more
 * test cases follow, the next integer is read at the right position) and emit
 * "gzuz" once per question. Loop until the input is exhausted.
 *
 * Complexity: O(total questions) time, O(1) space.
 */

#include <iostream>
#include <string>

int main() {
    int c;
    // Keep reading question-count headers until EOF (covers single or
    // multiple test cases without changing the logic).
    while (std::cin >> c) {
        std::cin.ignore();  // discard the newline left after reading C

        std::string question;
        for (int i = 0; i < c; ++i) {
            // Consume the whole question line; its text is unused, but reading
            // it keeps the stream aligned for any following test case.
            std::getline(std::cin, question);
            std::cout << "gzuz\n";  // fixed answer for every question
        }
    }

    return 0;
}

/*
 * Beecrowd 2581 — I am Toorg!
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Toorg, the wisest hero, has the ideal answer to ANY question, and
 *   that answer is always the phrase "I am Toorg!". Given a list of
 *   questions, print Toorg's reply to each one.
 *
 * Input:
 *   An integer N giving the number of questions, followed by N lines,
 *   each holding one question (the text is irrelevant to the answer).
 *   The reading loop runs until end-of-file so several such blocks are
 *   handled if present.
 *
 * Output:
 *   For each question, one line containing exactly "I am Toorg!".
 *
 * Approach:
 *   The answer never depends on the question, so there is nothing to
 *   parse from the question text — only to count. Read N, consume the N
 *   question lines (discarding them), and print the fixed reply N times.
 *   getline is used to skip exactly N lines, keeping the stream aligned
 *   in case more blocks follow.
 *
 * Complexity:
 *   O(total questions) time, O(1) space.
 */

#include <iostream>
#include <string>
#include <limits>

int main() {
    int n;

    // Loop over input blocks until EOF. Each block: an integer N, then
    // N question lines.
    while (std::cin >> n) {
        // Drop the rest of the line that held N (including the newline)
        // so the following getline starts on the first question line.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string question;
        for (int k = 0; k < n; ++k) {
            // Read and discard the question; the reply is always the same.
            std::getline(std::cin, question);
            std::cout << "I am Toorg!\n";
        }
    }

    return 0;
}

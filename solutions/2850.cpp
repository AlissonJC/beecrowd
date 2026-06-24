/*
 * Beecrowd 2850 - Polyglot Parrot
 *
 * A parrot's spoken language depends on which legs it raises: left leg
 * ("esquerda") -> English, right leg ("direita") -> French, no leg ("nenhuma")
 * -> Portuguese, and both legs ("as duas") -> it falls. Map each situation to the
 * proper word.
 *
 * Input : several test cases, one situation per line (read until end of file).
 * Output: per line, the language -- "ingles", "frances", "portugues" -- or
 *         "caiu" when both legs are raised.
 *
 * Approach: "as duas" contains a space, so read whole lines with getline rather
 *   than token by token, then translate each known phrase directly.
 *
 * Complexity: O(1) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();  // CRLF guard

        // Output strings are the Portuguese words the problem asks for.
        if (line == "esquerda")      cout << "ingles\n";
        else if (line == "direita")  cout << "frances\n";
        else if (line == "nenhuma")  cout << "portugues\n";
        else if (line == "as duas")  cout << "caiu\n";
        // Any blank/unknown line produces no output.
    }
    return 0;
}

/*
 * Beecrowd 2949 - The Fellowship of the Ring
 *
 * Count how many beings of each race enlisted for the journey. Each enlistee is
 * given as a name and a one-letter race code: A dwarf, E elf, H human, M
 * magician, X hobbit. Report the counts in a fixed order with Portuguese labels.
 *
 * Input : N (0 < N <= 10); then N lines "name C" where C is the race letter.
 *         (Read until EOF to be safe.)
 * Output: five lines, in the order hobbits, humans, elves, dwarves, magicians,
 *         each "<count> <label>" with the labels Hobbit(s), Humano(s), Elfo(s),
 *         Anao(oes), Mago(s).
 *
 * Approach: tally one counter per race letter, then print the five counts in the
 *   required order (which differs from the input letter order). All five lines
 *   are always printed, even when a count is zero.
 *
 * Complexity: O(N) per test case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int dwarf = 0, elf = 0, human = 0, mage = 0, hobbit = 0;
        for (int i = 0; i < n; ++i) {
            string name;
            char c;
            cin >> name >> c;
            switch (c) {
                case 'A': ++dwarf;  break;
                case 'E': ++elf;    break;
                case 'H': ++human;  break;
                case 'M': ++mage;   break;
                case 'X': ++hobbit; break;
            }
        }
        // Required order: hobbits, humans, elves, dwarves, magicians.
        cout << hobbit << " Hobbit(s)\n";
        cout << human  << " Humano(s)\n";
        cout << elf    << " Elfo(s)\n";
        cout << dwarf  << " Anao(oes)\n";
        cout << mage   << " Mago(s)\n";
    }
    return 0;
}

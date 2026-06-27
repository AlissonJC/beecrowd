/*
 * Beecrowd 2756 — Output 10
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Print a fixed nine-line figure made of the letters A..E and back to A.
 *   Reading the procedures, line k (k = 0 for 'A' up to k = 4 for 'E') has
 *   (7 - k) leading blanks, then the letter; for every line except 'A' the
 *   letter is repeated after (2k - 1) blanks. The five rising lines A..E are
 *   then mirrored back down to A, forming a chevron that opens to the right.
 *
 * Input:
 *   None.
 *
 * Output:
 *   Nine lines:
 *          A          (7 blanks, A)
 *         B B         (6 blanks, B, 1 blank, B)
 *        C   C        (5 blanks, C, 3 blanks, C)
 *       D     D       (4 blanks, D, 5 blanks, D)
 *      E       E      (3 blanks, E, 7 blanks, E)
 *     then D, C, B, A again (procedures 4, 3, 2, 1 repeated).
 *   No trailing spaces — each line ends on a letter.
 *
 * Approach:
 *   Drive the figure by the level k of each line. The level sequence is
 *   0,1,2,3,4,3,2,1,0; for each, emit (7 - k) spaces, the letter 'A' + k,
 *   and (only when k > 0) a gap of (2k - 1) spaces plus the letter again.
 *
 * Complexity:
 *   O(1) — a constant nine-line figure.
 */

#include <cstdio>
#include <string>

int main() {
    // Level of each line, rising 0..4 then mirrored back down to 0.
    const int levels[] = {0, 1, 2, 3, 4, 3, 2, 1, 0};

    for (int k : levels) {
        char c = static_cast<char>('A' + k);

        std::string line(7 - k, ' ');  // leading blanks shrink as k grows
        line += c;
        if (k > 0) {
            // Inner gap widens by 2 per level: B->1, C->3, D->5, E->7.
            line += std::string(2 * k - 1, ' ');
            line += c;
        }

        printf("%s\n", line.c_str());
    }

    return 0;
}

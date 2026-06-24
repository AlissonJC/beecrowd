/*
 * Beecrowd 2176 — Parity
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Given a binary message S, append a parity bit B so the resulting
 *   string S || B contains an EVEN number of '1' bits. Concretely:
 *     - If the count of '1's in S is even, B = '0'.
 *     - If the count of '1's in S is odd,  B = '1'.
 *   Print S followed immediately by B.
 *
 * Input (multi-case, EOF-terminated):
 *   Each line is a binary string of length 1 to 100.
 *
 * Output (per case):
 *   The original string S with the parity bit B appended.
 *
 * Approach:
 *   Read each line as a string, scan its bytes counting '1' chars,
 *   then write the string and append '0' if the count is even,
 *   '1' otherwise.
 *
 * Complexity:
 *   O(|S|) per line, with |S| <= 100. Trivial.
 */

#include <cstdio>
#include <cstring>

int main() {
    char s[128];
    // Read each line as a single token. cin's >> on a string would
    // behave the same, but scanf("%s") is enough here. Loop exits on EOF.
    while (scanf("%127s", s) == 1) {
        // Tally '1' chars to decide the parity bit.
        int ones = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '1') ones++;
        }
        // Append '0' to preserve already-even parity, '1' to flip odd
        // parity into even. Emit the original string then the new bit.
        char parity = (ones % 2 == 0) ? '0' : '1';
        printf("%s%c\n", s, parity);
    }
    return 0;
}

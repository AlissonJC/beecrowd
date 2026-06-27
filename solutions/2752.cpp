/*
 * Beecrowd 2752 — Output 6
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Store the phrase "AMO FAZER EXERCICIO NO URI" and print it eight times,
 *   each line wrapped between a '<' and a '>', using a different printf
 *   string conversion each time. The exercise drills the width and
 *   precision fields of the "%s" specifier:
 *     1) %s        - the string as is
 *     2) %30s      - min width 30, right-justified (pad left with spaces)
 *     3) %.20s     - print at most 20 characters (truncate)
 *     4) %-20s     - min width 20, left-justified
 *     5) %-30s     - min width 30, left-justified (pad right with spaces)
 *     6) %.30s     - print at most 30 characters
 *     7) %30.20s   - truncate to 20, then right-justify in width 30
 *     8) %-30.20s  - truncate to 20, then left-justify in width 30
 *
 * Input:
 *   None.
 *
 * Output:
 *   Eight lines, each "<" + formatted phrase + ">". The phrase is 26
 *   characters long, so width 20 never pads (it is shorter than the text),
 *   width 30 pads with 4 spaces, and the ".20" precision keeps the first
 *   20 characters: "AMO FAZER EXERCICIO " (note the trailing space).
 *
 * Approach:
 *   Emit each line directly with the matching printf format. The statement
 *   writes the formats as "% s", "% 30s", ... ; the space flag has no effect
 *   on string conversions (the sample's first line has no leading space), so
 *   plain "%s"-family specifiers reproduce the expected output exactly.
 *
 * Complexity:
 *   O(1) — eight formatted prints.
 */

#include <cstdio>

int main() {
    // "Variable to store 50 characters" per the statement; only the text
    // matters for the output.
    char str[50] = "AMO FAZER EXERCICIO NO URI";

    printf("<%s>\n", str);        // as is
    printf("<%30s>\n", str);      // width 30, right-justified
    printf("<%.20s>\n", str);     // first 20 chars
    printf("<%-20s>\n", str);     // width 20, left-justified (no pad: text is longer)
    printf("<%-30s>\n", str);     // width 30, left-justified
    printf("<%.30s>\n", str);     // first 30 chars (no truncation: text is shorter)
    printf("<%30.20s>\n", str);   // truncate to 20, right-justify in width 30
    printf("<%-30.20s>\n", str);  // truncate to 20, left-justify in width 30

    return 0;
}

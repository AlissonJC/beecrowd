/*
 * Beecrowd 1131 - Grenais
 *
 * Tally statistics over a series of "GRENAIS" (Inter vs Gremio matches). For
 * each match read Inter's goals and Gremio's goals, announce a new match, then
 * read whether another match follows (1 = yes, anything else = stop). When the
 * series ends, report the totals and which club won more matches.
 *
 * Input : repeated blocks of "Gi Gg" (two integers) followed by an integer flag
 *         (1 to continue, 2 to finish). There is always at least one match.
 * Output: "Novo grenal (1-sim 2-nao)" after each match's goals are read, then:
 *           <count> grenais
 *           Inter:<inter wins>
 *           Gremio:<gremio wins>
 *           Empates:<draws>
 *           "Inter venceu mais" / "Gremio venceu mais" / "Nao houve vencedor".
 *
 * Approach: a do-while loop (at least one match is guaranteed). Compare the two
 * goal counts to bump the Inter/Gremio/draw counters, print the prompt, and read
 * the continue flag. After the loop, emit the four counters and decide the
 * winner by comparing the two win tallies.
 *
 * Output strings are kept in ASCII exactly as the judge expects (no accents):
 * "nao" in the prompt and "Nao houve vencedor" for the tie - matching the
 * statement's own ASCII spelling of the repeated message.
 *
 * Complexity: O(1) per match, O(number of matches) overall; O(1) space.
 */
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int total = 0, inter = 0, gremio = 0, empates = 0;
    int gi, gg, again;

    // At least one grenal is always played, so a do-while fits naturally.
    do {
        std::cin >> gi >> gg;
        ++total;

        if (gi > gg)
            ++inter;            // Inter scored more
        else if (gg > gi)
            ++gremio;           // Gremio scored more
        else
            ++empates;          // tie game

        std::cout << "Novo grenal (1-sim 2-nao)\n";
        std::cin >> again;      // 1 keeps the series going; otherwise stop
    } while (again == 1);

    // Final statistics block.
    std::cout << total << " grenais\n";
    std::cout << "Inter:" << inter << '\n';
    std::cout << "Gremio:" << gremio << '\n';
    std::cout << "Empates:" << empates << '\n';

    // Overall winner by number of matches won (ASCII tie message).
    if (inter > gremio)
        std::cout << "Inter venceu mais\n";
    else if (gremio > inter)
        std::cout << "Gremio venceu mais\n";
    else
        std::cout << "Nao houve vencedor\n";

    return 0;
}

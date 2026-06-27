/*
 * Beecrowd 3174 - Noel's Work Groups
 *
 * Santa hires N temporary elves; each works H hours a day in one of four
 * groups, and every group needs a fixed number of hours of work to finish one
 * gift of its type: bonecos (dolls) 8, arquitetos (architects) 4, musicos
 * (musicians) 6, desenhistas (drawers) 12. Compute how many complete gifts the
 * whole factory finishes in one day.
 *
 * Key point: the hours are shared WITHIN a group, not counted per elf. Two
 * elves of the musicos group working 10 hours each contribute 20 hours, which
 * yields 20 / 6 = 3 gifts -- whereas counting them separately (1 + 1) would
 * undercount. So sum each group's hours first, then divide by the group's
 * per-gift cost (integer division drops the leftover hours of the day).
 *
 * Input : first line N (1 <= N <= 1000). Each of the next N lines has the elf's
 *         name, the group name (lowercase) and the hours H (1 <= H <= 24).
 * Output: a single integer P, the total gifts produced per day.
 *
 * Approach: Accumulate total hours per group, then sum floor(hours / cost) over
 * the four groups.
 *
 * Complexity: O(N) time, O(1) space.
 */

#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // Pooled hours per group; index them by gift type.
    long long bonecos = 0, arquitetos = 0, musicos = 0, desenhistas = 0;

    for (int i = 0; i < n; ++i) {
        std::string name, group;
        long long h;
        std::cin >> name >> group >> h;

        // Add this elf's hours to the shared pool of its group.
        if (group == "bonecos")          bonecos += h;
        else if (group == "arquitetos")  arquitetos += h;
        else if (group == "musicos")     musicos += h;
        else /* desenhistas */           desenhistas += h;
    }

    // Complete gifts per group = pooled hours / cost per gift; leftover hours
    // within a group do not finish a gift and are dropped by integer division.
    long long gifts = bonecos / 8 + arquitetos / 4 + musicos / 6 + desenhistas / 12;

    std::cout << gifts << "\n";
    return 0;
}

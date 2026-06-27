/*
 * Beecrowd 3161 - The Forgotten Fruits
 *
 * Sheldon's list of fruits he likes was scrambled by a virus that, for each
 * fruit on the list, may have applied SOME of these changes: appended junk
 * characters to the left and/or right of the name, flipped the case of some
 * letters, and/or reversed the whole name (e.g. "Bergamota" -> "Atomagreb").
 * Given N fruit names to look up and the M scrambled lines, report for each
 * query whether Sheldon likes that fruit.
 *
 * A query fruit is "liked" if, in at least one scrambled line, its name shows
 * up as a contiguous block once we ignore letter case and allow the block to
 * be reversed. Junk only appears to the sides, so the name stays contiguous:
 * thus the test is a case-insensitive substring search for the name in either
 * its forward or reversed orientation.
 *
 * Input : first line has N and M (1 <= N <= 100, 15 <= M <= 500). The next N
 *         lines are the fruit names to search; the following M lines are the
 *         scrambled list. Every name has length in [4, 100] and no spaces.
 * Output: for each query (in order), "Sheldon come a fruta X" if found, else
 *         "Sheldon detesta a fruta X", where X is the query name in lowercase.
 *
 * Approach: Lowercase everything. For each query, scan the M lines; a match is
 * line.find(name) or line.find(reverse(name)). Stop at the first hit.
 *
 * Complexity: O(N * M * L^2) worst case with L <= 100 (substring search),
 * which is well within the 5-second limit. Space O(M * L).
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// Return a lowercase copy of s, so comparisons ignore the virus's case flips.
static std::string toLower(std::string s) {
    for (char &c : s)
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    // Read the N query names first (kept lowercase for output and matching).
    std::vector<std::string> queries(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> queries[i];
        queries[i] = toLower(queries[i]);
    }

    // Then read the M scrambled lines, also lowercased once up front.
    std::vector<std::string> list(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> list[i];
        list[i] = toLower(list[i]);
    }

    for (const std::string &q : queries) {
        std::string rev(q.rbegin(), q.rend());  // reversed orientation

        bool liked = false;
        for (const std::string &line : list) {
            // Forward or reversed name appearing as a substring means a match.
            if (line.find(q) != std::string::npos ||
                line.find(rev) != std::string::npos) {
                liked = true;
                break;
            }
        }

        // Portuguese verdict strings per the statement; fruit printed lowercase.
        if (liked)
            std::cout << "Sheldon come a fruta " << q << "\n";
        else
            std::cout << "Sheldon detesta a fruta " << q << "\n";
    }

    return 0;
}

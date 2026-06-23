/*
 * Beecrowd 2740 - League
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   A ranking table lists each team and its final position. Report the top
 *   three teams prefixed with "Podium: " and the bottom two teams (which get
 *   demoted) prefixed with "Demoted: ", as a single result set.
 *
 * Schema:
 *   league(
 *     position INTEGER PRIMARY KEY,   -- 1 = champion, larger = worse rank
 *     team     VARCHAR
 *   )
 *
 * Input  : the rows already present in the `league` table.
 * Output : one column `name`, in this exact order ->
 *            Podium:  positions 1, 2, 3   (ascending)
 *            Demoted: the two largest positions (ascending)
 *
 * Sample (15 teams):
 *   Podium: The Quack Bats
 *   Podium: The Responsible Hornets
 *   Podium: The Bawdy Dolphins
 *   Demoted: The Rough Robins      (position 14)
 *   Demoted: The Silver Crocs      (position 15)
 *
 * Approach:
 *   Both groups are emitted by ONE query so a single `ORDER BY position` fixes
 *   the whole output order: the wanted positions are {1,2,3} and the two
 *   largest, and ascending position order is exactly 1,2,3,...,n-1,n -- which
 *   already places the podium block before the demoted block. The WHERE keeps
 *   only those rows; the bottom two are found generically via
 *   MAX(position) - 1 instead of hard-coding 14/15, so the query still works
 *   if the league size changes. A CASE picks the right prefix per row, and the
 *   "Podium: " / "Demoted: " strings (both with a trailing space) are
 *   concatenated with `||`.
 *
 * Output-format note:
 *   The prefixes come straight from the statement and the sample -- keep the
 *   exact casing and the single space after each colon. Result aliased `name`
 *   to match the expected header.
 *
 * Complexity:
 *   O(n) scan over the n league rows (plus a trivial MAX subquery).
 */

SELECT
    CASE WHEN position <= 3
         THEN 'Podium: '  || team   -- top three go to the podium
         ELSE 'Demoted: ' || team   -- only the bottom two reach this branch
    END AS name
FROM league
WHERE position <= 3                                  -- the podium
   OR position >= (SELECT MAX(position) - 1 FROM league)  -- the last two ranks
ORDER BY position;                                   -- 1,2,3, ... , n-1, n

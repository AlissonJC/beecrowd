/*
 * Beecrowd 2746 - Viruses
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   A table stores virus names. Every occurrence of the substring 'H1'
 *   (Hemagglutinin) inside a name must be rewritten as 'X' (Xenomorphina).
 *   Output the transformed name for every row, in table order.
 *
 * Schema:
 *   virus(
 *     id   INTEGER  PRIMARY KEY,
 *     name VARCHAR            -- the virus name to transform
 *   )
 *
 * Input  : the rows already present in the `virus` table.
 * Output : one column `name`, one row per virus, with every 'H1' turned into 'X'.
 *
 * Sample:
 *   name   ->  output
 *   H1RT   ->  XRT
 *   H7H1   ->  H7X
 *   HUN8   ->  HUN8     (no 'H1' present -> unchanged)
 *   XH1HX  ->  XXHX     (the inner 'H1' is replaced; surrounding chars stay)
 *   XXXX   ->  XXXX
 *
 * Approach:
 *   This is a pure string-substitution task, so a single projection with the
 *   built-in REPLACE() solves it. REPLACE(name, 'H1', 'X') swaps *all*
 *   non-overlapping occurrences of 'H1' in one pass -- exactly the required
 *   behaviour (e.g. a name could legitimately contain 'H1' more than once).
 *   No filtering, joining, grouping, or ordering clause is needed because the
 *   judge expects every row, in its natural order.
 *
 * Why the alias matters:
 *   The expected result set is headed by the column `name`, so the projection
 *   is aliased `AS name` to reproduce that header exactly.
 *
 * Complexity:
 *   O(n) over the n rows of `virus`; each REPLACE scans one name once.
 */

SELECT REPLACE(name, 'H1', 'X') AS name
FROM virus;

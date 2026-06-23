/*
 * Beecrowd 2743 - Number of Characters
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   For every person, report their name together with how many characters the
 *   name has, listing the longest names first.
 *
 * Schema:
 *   people(
 *     id   INTEGER PRIMARY KEY,
 *     name VARCHAR
 *   )
 *
 * Input  : the rows already present in the `people` table.
 * Output : two columns -> name, length (character count), sorted by length
 *          descending.
 *
 * Sample:
 *   name        length
 *   Valentine   9
 *   Manuel      6
 *   Karen       5
 *   Ygor        4
 *   Jo          2
 *
 * Approach:
 *   LENGTH(name) returns the number of characters in the name. Project it next
 *   to the name aliased as `length`, then ORDER BY that count descending so the
 *   longest names come first. The statement gives no tie-break rule and the
 *   data has no equal-length names, so a single ORDER BY length DESC is enough.
 *
 * Complexity:
 *   O(n log n) dominated by the sort over the n people rows.
 */

SELECT name,
       LENGTH(name) AS length   -- character count of the name
FROM people
ORDER BY length DESC;           -- longest names first

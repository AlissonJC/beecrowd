/*
 * Beecrowd 2993 - Most Frequent
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Given a single-column table of integers, return the statistical mode -- the
 *   value that occurs most often.
 *
 * Schema:
 *   value_table(
 *     amount INTEGER
 *   )
 *
 * Input  : the rows already present in the `value_table` table.
 * Output : one column `most_frequent_value` with a single row: the mode.
 *
 * Sample:
 *   The value 1 occurs 5 times (more than any other), so the answer is 1.
 *
 * Approach:
 *   Group the rows by value and count occurrences per value, order the groups by
 *   that count descending, and keep just the top one with LIMIT 1. The value of
 *   that single surviving group is the mode.
 *
 * Edge / tie note:
 *   If several values shared the maximum frequency, LIMIT 1 returns just one of
 *   them. The given data has a unique mode (1, with count 5), so a single row is
 *   exactly what is expected. Alias the column `most_frequent_value` to match
 *   the required header.
 *
 * Complexity:
 *   O(n) to aggregate the n rows, plus O(k log k) to sort the k distinct values.
 */

SELECT amount AS most_frequent_value
FROM value_table
GROUP BY amount
ORDER BY COUNT(*) DESC   -- most occurrences first
LIMIT 1;                 -- keep only the mode

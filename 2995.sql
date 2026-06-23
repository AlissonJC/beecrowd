/*
 * Beecrowd 2995 - The Sensor Message
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   A sensor logs the room temperature every minute. Each record also has a
 *   `mark` that is bumped every time the temperature changes, so a run of
 *   consecutive equal-temperature readings all share the same mark. To shrink
 *   the message, compact each run into a single line showing the temperature
 *   and how many readings it covered.
 *
 * Schema:
 *   records(
 *     id          INTEGER PRIMARY KEY,
 *     temperature INTEGER,
 *     mark        INTEGER   -- run identifier: changes whenever temperature changes
 *   )
 *
 * Input  : the rows already present in the `records` table.
 * Output : columns temperature, number_of_records -- one row per run, in
 *          chronological (mark) order.
 *
 * Sample:
 *   temperature  number_of_records
 *   30           3
 *   32           4
 *   30           3     <- a SECOND run of 30, kept separate from the first
 *   31           2
 *   33           3
 *
 * Approach:
 *   The `mark` column already encodes the "islands" of consecutive equal
 *   temperatures, so no manual gaps-and-islands logic is needed: just GROUP BY
 *   mark and count the rows. Grouping by mark (not by temperature) is essential
 *   -- the temperature 30 appears in two different runs (marks 1 and 3) and must
 *   stay as two separate output rows. Ordering by mark restores the original
 *   chronological order.
 *
 * Complexity:
 *   O(n) to aggregate the n records, plus O(k log k) to order the k runs.
 */

SELECT temperature,
       COUNT(*) AS number_of_records   -- size of this run
FROM records
GROUP BY mark, temperature             -- one group per consecutive-temperature run
ORDER BY mark;                         -- keep the chronological order of the runs

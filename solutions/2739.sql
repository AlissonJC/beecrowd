/*
 * Beecrowd 2739 - Payday
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   A bank lost the collection dates of its loan parcels. For every client,
 *   print the client's name together with the day of the month on which the
 *   parcel must be paid. The day has to be reported as a plain INTEGER.
 *
 * Schema:
 *   loan(
 *     id     INTEGER PRIMARY KEY,
 *     name   VARCHAR,
 *     value  NUMERIC,
 *     payday TIMESTAMP        -- ISO YMD, e.g. 2017-10-05
 *   )
 *
 * Input  : the rows already present in the `loan` table.
 * Output : two columns -> `name`, `day` (one row per client).
 *
 * Sample:
 *   name                payday        ->  day
 *   Cristian Ghyprievy  2017-10-19    ->  19
 *   John Serial         2017-10-10    ->  10
 *   Michael Seven       2017-10-17    ->  17
 *   Joana Cabel         2017-10-05    ->  5      (NO leading zero!)
 *   Miguel Santos       2017-10-20    ->  20
 *
 * Approach:
 *   EXTRACT(DAY FROM payday) pulls the day-of-month component out of the
 *   timestamp. The statement stresses that the day must be an INTEGER, so the
 *   result is wrapped in CAST(... AS INTEGER). This is what produces 5 rather
 *   than 05 (TO_CHAR(payday,'DD') would wrongly pad to '05') and avoids any
 *   numeric/double-precision rendering such as 5.0. The output column is
 *   aliased `day` to match the expected header.
 *
 * Complexity:
 *   O(n) over the n rows of `loan`; one date extraction per row.
 */

SELECT name,
       CAST(EXTRACT(DAY FROM payday) AS INTEGER) AS day
FROM loan;

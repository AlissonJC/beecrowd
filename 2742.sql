/*
 * Beecrowd 2742 - Richard's Multiverse
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   List every person named "Richard" who lives in dimension C875 or C774,
 *   along with their existence probability ("N factor"). The N factor is the
 *   person's omega multiplied by 1.618, shown with three decimal places. Sort
 *   the result by ascending omega ("least omega value" first).
 *
 * Schema:
 *   dimensions(
 *     id   NUMERIC PRIMARY KEY,
 *     name VARCHAR                 -- dimension code, e.g. 'C774'
 *   )
 *   life_registry(
 *     id            NUMERIC PRIMARY KEY,
 *     name          VARCHAR,
 *     omega         NUMERIC,
 *     dimensions_id NUMERIC        -- FK -> dimensions.id
 *   )
 *
 * Input  : the rows already present in both tables.
 * Output : two columns -> name, "The N Factor", one row per matching Richard.
 *
 * Sample:
 *   name                  The N Factor
 *   Richard Gran Master   4.045        (omega 2.5 in dimension C774; 2.5*1.618)
 *
 * Approach:
 *   Join life_registry to dimensions on the FK so each person's dimension code
 *   is available. Keep only people whose name starts with "Richard"
 *   (LIKE 'Richard%') and whose dimension code is C875 or C774. The N factor is
 *   computed inline as omega * 1.618 and rounded to three decimals; the alias
 *   carries spaces, so it must be double-quoted as "The N Factor". Finally sort
 *   by omega ascending as required.
 *
 * Output-format note:
 *   ROUND(omega * 1.618, 3) on NUMERIC yields scale 3, so values print with
 *   exactly three decimals (e.g. 4.045). The sample value is exact, so ROUND
 *   and TRUNC coincide here; ROUND matches the "three decimal places of
 *   precision" wording.
 *
 * Complexity:
 *   O(n log n) for the ordered join over the life_registry rows.
 */

SELECT lr.name,
       ROUND(lr.omega * 1.618, 3) AS "The N Factor"   -- N = omega * 1.618, 3 decimals
FROM life_registry lr
JOIN dimensions d ON d.id = lr.dimensions_id           -- resolve each person's dimension code
WHERE lr.name LIKE 'Richard%'                          -- every "Richard"
  AND d.name IN ('C875', 'C774')                       -- only these two dimensions
ORDER BY lr.omega ASC;                                 -- least omega first

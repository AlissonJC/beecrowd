/*
 * Beecrowd 3483 - Second Largest and Smallest
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   From a table of cities and their populations, report two cities: first the
 *   city with the SECOND largest population, then the city with the SECOND
 *   smallest population.
 *
 * Schema:
 *   cities(
 *     id          NUMERIC,
 *     city_name   VARCHAR(50),
 *     population  NUMERIC
 *   )
 *
 * Input  : the rows already present in the `cities` table.
 * Output : columns city_name, population -- exactly two rows, the 2nd largest
 *          first and the 2nd smallest second.
 *
 * Sample:
 *   city_name        population
 *   Rio de Janeiro   6775561     (2nd largest; Sao Paulo is the largest)
 *   Belem            1506420     (2nd smallest; Porto Alegre is the smallest)
 *
 * Approach:
 *   "Second largest" = skip the top row and take the next: ORDER BY population
 *   DESC, LIMIT 1 OFFSET 1. "Second smallest" = the same idea ascending. Each is
 *   computed in its own derived table, then combined with UNION ALL. A constant
 *   tag column `ord` (1 for the largest side, 2 for the smallest side) is
 *   carried along so the outer query can ORDER BY ord and guarantee the required
 *   output order regardless of how UNION ALL interleaves rows. The tag is not
 *   selected in the final projection, so only city_name and population appear.
 *
 * Edge note:
 *   Assumes at least two cities exist (so a "second" value is defined) and that
 *   ranks are taken by row position, which is fine here since all populations
 *   are distinct.
 *
 * Complexity:
 *   O(n log n) for each ordered scan over the n cities.
 */

SELECT city_name, population
FROM (
    -- second largest population (skip the largest, take the next)
    SELECT city_name, population, 1 AS ord
    FROM (SELECT city_name, population
          FROM cities
          ORDER BY population DESC
          LIMIT 1 OFFSET 1) AS big
    UNION ALL
    -- second smallest population (skip the smallest, take the next)
    SELECT city_name, population, 2 AS ord
    FROM (SELECT city_name, population
          FROM cities
          ORDER BY population ASC
          LIMIT 1 OFFSET 1) AS small
) AS t
ORDER BY ord;   -- 2nd largest first, then 2nd smallest

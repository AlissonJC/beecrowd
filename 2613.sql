/*
 * Beecrowd SQL 2613 - "Cheap Movies"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The studio once put movies on sale. List the id and name of every movie
 *   whose price value is less than 2.00.
 *
 * SCHEMA
 *   movies(id PK, name, id_prices FK -> prices.id)
 *   prices(id PK, categorie, value)
 *
 * OUTPUT
 *   Two columns: id, name -- one row per movie priced below 2.00.
 *
 * APPROACH
 *   Inner-join each movie to its price row and keep those with value < 2.00.
 *
 * EDGE CASE -- strict "less than"
 *   "The Two Hours" sits in the Bronze Seal price band whose value is exactly
 *   2.00. The requirement is "less than 2.00", so 2.00 itself must be EXCLUDED:
 *   use a strict < (not <=). With <= the 2.00 movie would wrongly appear.
 *
 * COMPLEXITY
 *   O(M) over the movies rows for the join + filter; trivial here.
 */

SELECT m.id, m.name
FROM movies m
JOIN prices p ON p.id = m.id_prices
-- Strictly below 2.00 -- the 2.00 price band is NOT "cheap" for this report.
WHERE p.value < 2.00;

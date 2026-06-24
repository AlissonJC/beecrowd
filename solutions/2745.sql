/*
 * Beecrowd 2745 - Taxes
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Everyone earning more than 3000 pays a tax of 10% of their income. Show the
 *   name and the tax owed by each such person, with two decimal places.
 *
 * Schema:
 *   people(
 *     id     INTEGER PRIMARY KEY,
 *     name   VARCHAR,
 *     salary NUMERIC
 *   )
 *
 * Input  : the rows already present in the `people` table.
 * Output : two columns -> name, tax, only for salary > 3000.
 *
 * Sample:
 *   name               tax
 *   Rafael T. Hendon   428.10   (4281 * 0.10)
 *   Linda J. Gardner   443.70
 *   Nicholas J. Conn   801.10
 *   Lolita S. Graves   870.90
 *
 * Approach:
 *   Filter to incomes strictly greater than 3000 ("higher than 3000"), then
 *   compute 10% of the salary. ROUND(..., 2) on a NUMERIC keeps scale 2, so the
 *   value prints with two decimals including trailing zeros (428.10, not 428.1).
 *
 * Output-format note:
 *   salary is an integer amount, so salary * 0.1 has at most one decimal digit
 *   and the second decimal is always 0. ROUND and TRUNC to two places therefore
 *   give the same result here -- the usual "truncate vs round" ambiguity does
 *   not apply. The threshold is strict (>), and the result column is aliased
 *   `tax` to match the header.
 *
 * Complexity:
 *   O(n) over the n people rows.
 */

SELECT name,
       ROUND(salary * 0.1, 2) AS tax   -- 10% of income, two decimals
FROM people
WHERE salary > 3000;                   -- strictly more than 3000

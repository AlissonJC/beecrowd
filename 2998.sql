/*
 * Beecrowd 2998 - The Payback
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Each client makes an initial investment and then earns monthly profits
 *   (operations). A client "reaches payback" in the first month where the
 *   accumulated profit (sum of all operations up to and including that month)
 *   becomes greater than or equal to the investment. For every client that
 *   reaches payback, show the name, the investment, the payback month, and the
 *   payback value (accumulated profit at that month - investment). Clients that
 *   never reach payback are omitted. Order from highest to lowest payback value.
 *
 * Schema:
 *   clients(id INT PK, name VARCHAR(50), investment NUMERIC)
 *   operations(id INT PK, client_id INT -> clients.id, month INT, profit NUMERIC)
 *
 * Input  : the rows already present in both tables.
 * Output : columns name, investment, month_of_payback, return -- ordered by
 *          return descending.
 *
 * Sample:
 *   name      investment  month_of_payback  return
 *   Lucas     1000        3                 300     (100+300+900=1300; 1300-1000)
 *   Oliveira  2000        2                 0       (1000+1000=2000; 2000-2000)
 *   (Daniel never reaches 500 -> omitted)
 *
 * Approach:
 *   1) cumulative: a running total of each client's profit ordered by month,
 *      via SUM(profit) OVER (PARTITION BY client_id ORDER BY month).
 *   2) payback: join to clients, keep only months whose running total already
 *      covers the investment (acc >= investment), and number those qualifying
 *      months per client by month with ROW_NUMBER. WHERE runs before the window
 *      function, so the numbering is over the qualifying months only.
 *   3) The first qualifying month per client (rn = 1) is the payback month; its
 *      return is acc - investment. Order by return descending.
 *
 * Output-format note:
 *   `return` is quoted as an alias because it is a SQL keyword; the header must
 *   read exactly "return". investment and return come straight from integer-
 *   valued NUMERIC data, so they print without decimals (e.g. 1000, 0).
 *
 * Complexity:
 *   O(m log m) over the m operations (the window ordering dominates), plus the
 *   final sort of the qualifying clients.
 */

WITH cumulative AS (
    -- running total of profit per client, in month order
    SELECT o.client_id,
           o.month,
           SUM(o.profit) OVER (PARTITION BY o.client_id ORDER BY o.month) AS acc
    FROM operations o
),
payback AS (
    -- among the months that already cover the investment, number them per client
    SELECT c.name,
           c.investment,
           cu.month,
           cu.acc - c.investment AS ret,
           ROW_NUMBER() OVER (PARTITION BY cu.client_id ORDER BY cu.month) AS rn
    FROM cumulative cu
    JOIN clients c ON c.id = cu.client_id
    WHERE cu.acc >= c.investment           -- payback reached at this month
)
SELECT name,
       investment,
       month AS month_of_payback,
       ret   AS "return"                   -- quoted: "return" is a keyword
FROM payback
WHERE rn = 1                               -- the FIRST month that reaches payback
ORDER BY ret DESC;                         -- highest payback first

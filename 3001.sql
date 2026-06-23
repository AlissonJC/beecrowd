/*
 * Beecrowd 3001 - Update sem Where
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   An accidental UPDATE without a WHERE zeroed the price column. Prices can be
 *   rebuilt from the product type: type 'A' -> 20.0, 'B' -> 70.0, 'C' -> 530.5.
 *   Show the name and recalculated price of every product, grouped by type in
 *   the order A, then B, then C, and within each group ordered by descending id.
 *
 * Schema (the actual data table is `products`; the column layout is):
 *   products(
 *     id    NUMERIC,
 *     name  VARCHAR(50),
 *     type  CHAR,        -- 'A', 'B' or 'C'
 *     price NUMERIC      -- currently all zeros; recomputed from type
 *   )
 *
 * Input  : the rows already present in the `products` table.
 * Output : columns name, price.
 *
 * Sample:
 *   name           price
 *   Mouse          20.0     -- type A, ids 6,3,2 (descending)
 *   PC Case        20.0
 *   Headset        20.0
 *   Monitor        70.0     -- type B
 *   Gaming Chair   530.5    -- type C, ids 5,4 (descending)
 *   Computer Desk  530.5
 *
 * Approach:
 *   A CASE on the type maps each product to its fixed price. The grouped output
 *   order is produced entirely by ORDER BY type, id DESC: ascending type sorts
 *   the groups A < B < C, and id DESC orders members of each group from highest
 *   id to lowest.
 *
 * Output-format note:
 *   The price literals 20.0 / 70.0 / 530.5 are written with a decimal, so the
 *   CASE result is NUMERIC with scale 1 and prints as "20.0", "70.0", "530.5".
 *
 * Complexity:
 *   O(n log n) dominated by the final sort over the n products.
 */

SELECT name,
       CASE type
           WHEN 'A' THEN 20.0
           WHEN 'B' THEN 70.0
           WHEN 'C' THEN 530.5
       END AS price
FROM products
ORDER BY type,      -- groups in order A, B, C
         id DESC;   -- within each group, highest id first

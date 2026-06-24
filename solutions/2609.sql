/*
 * Beecrowd SQL 2609 - "Products by Categories"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   For a stock analysis, report each category together with the total quantity
 *   (sum of the amount column) of the products that belong to it.
 *
 * SCHEMA
 *   products(id PK, name, amount, price, id_categories FK -> categories.id)
 *   categories(id PK, name)
 *
 * OUTPUT
 *   Two columns: name (category name) and sum (total amount in that category).
 *   Categories that own no product are NOT listed (e.g. "super luxury").
 *
 * APPROACH
 *   Inner-join products to their category, group by category, and SUM(amount).
 *   The INNER JOIN is what drops empty categories: a category with no product
 *   contributes no rows, so it simply never appears -- matching the sample where
 *   "super luxury" is absent.
 *
 * ORDERING
 *   The statement asks for no particular order and the sample rows are in hash-
 *   aggregate order, so no ORDER BY is used; the judge compares the rows without
 *   regard to order for this problem.
 *
 * FORMATTING
 *   amount is an integer-valued numeric, so SUM stays whole (e.g. "850") with no
 *   decimals -- no ROUND/format needed. The aggregate is aliased to "sum" so the
 *   output header matches.
 *
 * COMPLEXITY
 *   O(P) over the products rows for the join + grouped sum; trivial here.
 */

SELECT
    c.name,                  -- category name
    SUM(p.amount) AS sum     -- total stocked quantity in this category
FROM categories c
JOIN products p ON p.id_categories = c.id
GROUP BY c.name;

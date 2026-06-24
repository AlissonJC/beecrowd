/*
 * Beecrowd SQL 2623 - "Categories with Various Products"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   Stock report: show the product name and the category name for products whose
 *   amount is greater than 100 AND whose category id is one of 1, 2, 3, 6 or 9.
 *   Order the rows ascending by category id.
 *
 * SCHEMA
 *   products(id PK, name, amount, price, id_categories FK -> categories.id)
 *   categories(id PK, name)
 *
 * OUTPUT
 *   Two columns, both header "name": product name and category name. For the
 *   sample the single match is:  Red Chair | Super Luxury
 *
 * APPROACH
 *   Join products to their category, then apply both filters: a strict amount
 *   above 100 and membership of the category id in the allowed set via IN. Both
 *   conditions are required -- e.g. Disney Wardrobe has amount 400 but sits in
 *   category 4, which is not in the list, so it is excluded. Order by category id.
 *
 * NAMES
 *   PostgreSQL allows the two "name" output columns to share their header, so no
 *   aliasing is needed.
 *
 * COMPLEXITY
 *   O(P) over the products rows for the join + filter, plus a small sort.
 */

SELECT
    p.name,        -- product name
    c.name         -- category name
FROM products p
JOIN categories c ON c.id = p.id_categories
-- More than 100 in stock and in one of the requested categories.
WHERE p.amount > 100
  AND p.id_categories IN (1, 2, 3, 6, 9)
ORDER BY c.id;     -- ascending by category id

/*
 * Beecrowd SQL 2618 - "Imported Products"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The import sector needs a report listing the product name, the supplier name
 *   and the category name for products that are supplied by 'Sansul SA' AND whose
 *   category is named 'Imported'.
 *
 * SCHEMA
 *   products(id PK, name, amount, price, id_providers FK, id_categories FK)
 *   providers(id PK, name, street, city, state)
 *   categories(id PK, name)
 *
 * OUTPUT
 *   Three columns -- product name, supplier name, category name (all header
 *   "name"). For the sample the single match is:  TV | Sansul SA | Imported
 *
 * APPROACH
 *   Join products to both providers and categories on their foreign keys, then
 *   restrict to the supplier 'Sansul SA' and the category 'Imported'. Both
 *   filters use the NAME columns, exactly as the statement phrases them, rather
 *   than hard-coded ids.
 *
 * NAMES
 *   PostgreSQL permits the three "name" output columns to share their header, so
 *   no aliasing is needed.
 *
 * COMPLEXITY
 *   O(P) over the products rows for the joins + filter; trivial here.
 */

SELECT
    p.name,        -- product name
    pr.name,       -- supplier name
    c.name         -- category name
FROM products p
JOIN providers  pr ON pr.id = p.id_providers
JOIN categories c  ON c.id  = p.id_categories
-- Supplied by Sansul SA and in the Imported category, both matched by name.
WHERE pr.name = 'Sansul SA'
  AND c.name  = 'Imported';

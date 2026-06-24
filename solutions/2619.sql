/*
 * Beecrowd SQL 2619 - "Super Luxury"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   For a new supply contract, show the product name, the provider name and the
 *   price of every product whose price is greater than 1000 AND whose category
 *   is 'Super Luxury'.
 *
 * SCHEMA
 *   products(id PK, name, amount, price, id_providers FK, id_categories FK)
 *   providers(id PK, name, street, city, state)
 *   categories(id PK, name)
 *
 * OUTPUT
 *   Three columns -- product name, provider name (both header "name") and price.
 *   For the sample the single match is:  Red Chair | Sansul SA | 2150.00
 *
 * APPROACH
 *   Join products to both providers and categories on the foreign keys, then
 *   apply the two conditions: a strict price > 1000 and the category named
 *   'Super Luxury' (filtered by NAME, as the statement states, not by id).
 *
 * FORMATTING / NAMES
 *   price is a numeric with scale 2, so selecting it directly prints "2150.00"
 *   (no ROUND/format needed). PostgreSQL permits the two "name" output columns
 *   to share their header, so no aliasing is required.
 *
 * COMPLEXITY
 *   O(P) over the products rows for the joins + filter; trivial here.
 */

SELECT
    p.name,        -- product name
    pr.name,       -- provider name
    p.price        -- numeric, prints with its two stored decimals
FROM products p
JOIN providers  pr ON pr.id = p.id_providers
JOIN categories c  ON c.id  = p.id_categories
-- Above 1000 (strict) and in the Super Luxury category, matched by its name.
WHERE p.price > 1000
  AND c.name = 'Super Luxury';

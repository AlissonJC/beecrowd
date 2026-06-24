/*
 * Beecrowd SQL 2621 - "Amounts Between 10 and 20"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   Rebuild part of a corrupted stock report: list the name of every product
 *   whose stock amount is between 10 and 20 AND whose supplier's name starts
 *   with the letter 'P'.
 *
 * SCHEMA
 *   providers(id PK, name, street, city, state)
 *   products(id PK, name, amount, price, id_providers FK -> providers.id)
 *
 * OUTPUT
 *   One column "name": the qualifying product names.
 *
 * APPROACH
 *   Join each product to its supplier, then apply two filters: an inclusive
 *   amount range with BETWEEN (10 and 20 included) and a prefix match on the
 *   supplier name with LIKE 'P%'. In PostgreSQL LIKE is case-sensitive, so 'P%'
 *   matches the capital-P supplier "Pr Sheppard Chairs" and nothing lowercase.
 *
 * COMPLEXITY
 *   O(P) over the products rows for the join + filter; trivial here.
 */

SELECT p.name
FROM products p
JOIN providers pr ON pr.id = p.id_providers
-- Stock between 10 and 20 inclusive, and supplied by a provider whose name
-- begins with an uppercase 'P'.
WHERE p.amount BETWEEN 10 AND 20
  AND pr.name LIKE 'P%';

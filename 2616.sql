/*
 * Beecrowd SQL 2616 - "No Rental"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The video store wants to target customers who have never rented anything.
 *   List the id and name of every customer with no rental, ordered by id.
 *
 * SCHEMA
 *   customers(id PK, name, street, city)
 *   locations(id PK, locations_date DATE, id_customers FK -> customers.id)
 *
 * OUTPUT
 *   Two columns: id, name -- one row per customer that owns no locations row,
 *   sorted ascending by id.
 *
 * APPROACH
 *   Anti-join: keep each customer for whom NO row in locations references them.
 *   NOT EXISTS expresses exactly "this customer never appears in locations" and,
 *   unlike NOT IN, stays correct even if id_customers ever held a NULL.
 *
 * COMPLEXITY
 *   O(C) customers, each probing locations; trivial for this data size.
 */

SELECT c.id, c.name
FROM customers c
-- "Made no rental": there is no locations row pointing at this customer.
WHERE NOT EXISTS (
    SELECT 1
    FROM locations l
    WHERE l.id_customers = c.id
)
ORDER BY c.id;

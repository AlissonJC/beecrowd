/*
 * Beecrowd SQL 2620 - "Orders in First Half"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   For a financial audit covering the first half of 2016, list the customer
 *   name and the order number of every order placed between January and June
 *   2016 (inclusive).
 *
 * SCHEMA
 *   customers(id PK, name, street, city, state, credit_limit)
 *   orders(id PK, orders_date DATE, id_customers FK -> customers.id)
 *
 * OUTPUT
 *   Two columns: name (customer) and id. NOTE: the id column is the ORDER number
 *   (orders.id), not the customer id -- the sample values 1,2,3,5 are order ids.
 *
 * APPROACH
 *   Join orders to their customer, keep orders whose date falls in the first
 *   half of 2016, and output the customer name with the order id. The date test
 *   uses the half-open range [2016-01-01, 2016-07-01): every date from January
 *   through June passes and 1 July onward is excluded -- no need to know each
 *   month's last day. Results are ordered by order id to match the sample.
 *
 * COMPLEXITY
 *   O(O) over the orders rows for the join + filter; trivial here.
 */

SELECT
    c.name,        -- customer name
    o.id           -- ORDER number (orders.id), not the customer id
FROM customers c
JOIN orders o ON o.id_customers = c.id
-- First half of 2016: on/after 1 Jan and strictly before 1 Jul.
WHERE o.orders_date >= '2016-01-01'
  AND o.orders_date <  '2016-07-01'
ORDER BY o.id;

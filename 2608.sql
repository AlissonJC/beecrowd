/*
 * Beecrowd SQL 2608 - "Higher and Lower Price"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The finance team wants the cheapest and most expensive product we sell.
 *   From the products table, output the single highest price and the single
 *   lowest price.
 *
 * SCHEMA
 *   products(id PK numeric, name varchar, amount numeric, price numeric)
 *
 * OUTPUT
 *   Exactly one row with two columns, BOTH labelled "price":
 *     <max price>  <min price>
 *   For the sample data that is:  800   25.50
 *
 * APPROACH
 *   A single aggregate over the whole table: MAX(price) and MIN(price). No
 *   GROUP BY is needed since the aggregate spans every row.
 *
 * FORMATTING NOTE (why no ROUND)
 *   price is a bare numeric, so PostgreSQL keeps each value's own scale: 800 is
 *   stored with scale 0 and prints "800", while 25.50 keeps scale 2 and prints
 *   "25.50". MAX/MIN return those stored values untouched, reproducing the
 *   sample exactly. Applying ROUND(price, 2) would force "800.00" and fail the
 *   byte-exact text comparison -- so it is deliberately omitted.
 *
 * COLUMN NAMES
 *   The expected header shows "price" twice. PostgreSQL allows two result
 *   columns to share an alias, so both aggregates are aliased to price.
 *
 * COMPLEXITY
 *   O(N) single scan of the products table; constant memory.
 */

SELECT
    MAX(price) AS price,   -- highest price (most expensive product)
    MIN(price) AS price    -- lowest price  (cheapest product)
FROM products;

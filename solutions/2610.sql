/*
 * Beecrowd SQL 2610 - "Average Value of Products"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   A survey on product values needs the average of the price column across all
 *   products, shown with two digits after the decimal point.
 *
 * SCHEMA
 *   products(id PK, name, amount, price)
 *
 * OUTPUT
 *   One column named "price": the average price with exactly two decimals.
 *
 * APPROACH
 *   A single AVG(price) over the whole table, formatted to two decimals.
 *
 * KEY DETAIL -- truncate, do NOT round
 *   The six prices sum to 2376.64, so the average is 2376.64 / 6 = 396.1066...
 *   The expected output is 396.10, i.e. the value is TRUNCATED to two decimals,
 *   not rounded (ROUND would give 396.11 and fail). TRUNC(value, 2) cuts the
 *   extra digits without rounding and yields a numeric of scale 2, which prints
 *   as "396.10" -- the two trailing decimals the statement asks for.
 *
 * COMPLEXITY
 *   O(N) single scan of products; constant memory.
 */

-- Average price, truncated (not rounded) to two decimal places. Alias to "price"
-- so the output header matches the expected column name.
SELECT TRUNC(AVG(price), 2) AS price
FROM products;

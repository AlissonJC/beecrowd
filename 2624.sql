/*
 * Beecrowd SQL 2624 - "Number of Cities per Customers"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The board wants to know how many cities the company has reached: report the
 *   number of distinct cities present in the customers table.
 *
 * SCHEMA
 *   customers(id PK, name, street, city, state, credit_limit)
 *
 * OUTPUT
 *   One column "count" with the number of distinct city values.
 *
 * APPROACH
 *   COUNT(DISTINCT city) collapses repeated cities and counts the unique ones
 *   (Porto Alegre appears three times but is counted once). No alias is needed:
 *   PostgreSQL already names a COUNT result column "count", matching the header.
 *
 * COMPLEXITY
 *   O(N) single scan of customers; constant output.
 */

-- Count the unique cities; duplicates (e.g. repeated "Porto Alegre") collapse to one.
SELECT COUNT(DISTINCT city)
FROM customers;

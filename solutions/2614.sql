/*
 * Beecrowd SQL 2614 - "September Rentals"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   For a semi-annual report, list the client name and the rental date of every
 *   rental that happened in September 2016.
 *
 * SCHEMA
 *   customers(id PK, name, street, city)
 *   rentals(id PK, rentals_date DATE, id_customers FK -> customers.id)
 *
 * OUTPUT
 *   Two columns: name, rentals_date -- one row per September-2016 rental.
 *
 * APPROACH
 *   Inner-join rentals to their customer, then keep rentals whose date is in
 *   September 2016. The filter uses a half-open range [2016-09-01, 2016-10-01):
 *   every date in September passes and 1 October onward is excluded. This range
 *   form is preferred over BETWEEN '...-09-01' AND '...-09-30' because it needs
 *   no knowledge of the month's last day and stays correct even if the column
 *   ever carried a time component.
 *
 * COMPLEXITY
 *   O(R) over the rentals rows for the join + filter; trivial here.
 */

SELECT c.name, r.rentals_date
FROM customers c
JOIN rentals r ON r.id_customers = c.id
-- Rentals dated in September 2016: on/after the 1st and strictly before 1 Oct.
WHERE r.rentals_date >= '2016-09-01'
  AND r.rentals_date <  '2016-10-01';

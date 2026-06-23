/*
 * Beecrowd SQL 2622 - "Legal Person"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The sales team wants to run a promotion for every client that is a legal
 *   entity (pessoa juridica). List the name of those customers.
 *
 * SCHEMA
 *   customers(id PK, name, street, city, state, credit_limit)
 *   legal_person(id_customers FK -> customers.id, cnpj, contact)
 *
 * OUTPUT
 *   One column "name": the customers that have a legal_person record.
 *
 * APPROACH
 *   A customer is a legal entity exactly when a row in legal_person points to
 *   it. Inner-join customers to legal_person on the foreign key and project the
 *   name -- the join keeps only matched customers, which is the filter we want.
 *
 * NOTE -- no DISTINCT
 *   Two customers share the name "Nicolas Diogo Cardoso" (ids 1 and 4), but only
 *   id 4 has a legal_person row, so the join already yields it once. Adding
 *   DISTINCT is unnecessary here and would even be wrong if two different legal
 *   entities happened to share a name -- each must still be listed.
 *
 * COMPLEXITY
 *   O(L) over the legal_person rows for the join; trivial here.
 */

SELECT c.name
FROM customers c
JOIN legal_person lp ON lp.id_customers = c.id;

/*
 * Beecrowd SQL 2625 - "CPF Validation"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The natural-person customers have their CPF stored as raw digits. Output
 *   every CPF formatted with the Brazilian mask '000.000.000-00'.
 *
 * SCHEMA
 *   customers(id PK, name, street, city, state, credit_limit)
 *   natural_person(id_customers FK -> customers.id, cpf char(14))
 *
 * OUTPUT
 *   One column "CPF" (uppercase header): each CPF as ddd.ddd.ddd-dd.
 *   e.g. 26774287840 -> 267.742.878-40
 *
 * APPROACH
 *   The CPF is 11 digits. Cut it positionally into the groups 3/3/3/2 and glue
 *   them back with dots and a dash. Slicing by fixed position (1,4,7,10) is the
 *   robust choice here: cpf is declared char(14), so the 11-digit value is stored
 *   padded with trailing spaces; positions 1..11 are always the digits, so the
 *   padding (positions 12..14) is never pulled into the result. A regex replace
 *   would instead leave those trailing spaces and fail the byte-exact compare.
 *
 * HEADER
 *   The expected header is uppercase "CPF". Unquoted aliases fold to lowercase in
 *   PostgreSQL, so the alias is double-quoted to keep the capitals.
 *
 * COMPLEXITY
 *   O(N) over the natural_person rows; constant string work per row.
 */

SELECT
    substr(cpf, 1, 3) || '.' ||   -- first block of 3 digits
    substr(cpf, 4, 3) || '.' ||   -- second block of 3
    substr(cpf, 7, 3) || '-' ||   -- third block of 3
    substr(cpf, 10, 2) AS "CPF"   -- final 2 check digits
FROM natural_person;

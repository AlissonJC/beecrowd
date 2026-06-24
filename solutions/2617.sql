/*
 * Beecrowd SQL 2617 - "Provider Ajax SA"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   A delivery from one supplier did not match its invoice. Produce a report
 *   listing the product name together with the supplier name, restricted to the
 *   products supplied by the provider named 'Ajax SA'.
 *
 * SCHEMA
 *   providers(id PK, name, street, city, state)
 *   products(id PK, name, amount, price, id_providers FK -> providers.id)
 *   (The sample data labels the products money column "value" instead of
 *    "price"; that column is never used here, so the mismatch is harmless.)
 *
 * OUTPUT
 *   Two columns, BOTH labelled "name": the product name, then the provider name.
 *   For the sample data the single matching row is:  Red Chair   Ajax SA
 *
 * APPROACH
 *   Inner-join products to providers on the foreign key, then keep only the
 *   rows whose provider name is 'Ajax SA'. Filtering by the provider NAME (not a
 *   hard-coded id) is what the statement asks for and is robust to whichever id
 *   Ajax SA happens to have in the judge's data.
 *
 * COLUMN NAMES
 *   The expected header shows "name" twice; PostgreSQL allows two result columns
 *   to share an alias, so both selected names are aliased to name.
 *
 * COMPLEXITY
 *   O(P) over the products rows for the join + filter; trivial for this size.
 */

SELECT
    pr.name AS name,    -- product name
    pv.name AS name     -- provider name
FROM products pr
JOIN providers pv ON pv.id = pr.id_providers
-- Restrict to the single supplier of interest, matched by name as the statement
-- specifies rather than by a literal id.
WHERE pv.name = 'Ajax SA';

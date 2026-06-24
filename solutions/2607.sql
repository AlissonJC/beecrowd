-- Beecrowd 2607 - Providers' City in Alphabetical Order
--
-- Return every city where a provider is registered, in alphabetical order and
-- without repeating any city.
--
-- Schema: providers(id PK numeric, name varchar, street varchar, city varchar,
--         state char).
--
-- Approach: DISTINCT collapses providers that share a city into a single row;
-- ORDER BY city sorts the remaining cities ascending.

SELECT DISTINCT city
FROM providers
ORDER BY city;

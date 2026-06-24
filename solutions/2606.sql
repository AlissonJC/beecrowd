-- Beecrowd SQL 2606 — Categories
-- Time limit: 1 s
--
-- Problem (restated in English):
--   The data team needs the ID and name of every product whose category
--   name starts with the literal word "super". Each product belongs to a
--   single category through the foreign key products.id_categories.
--
-- Schema:
--   products(id PK, name, amount, price, id_categories FK -> categories.id)
--   categories(id PK, name)
--
-- Expected output (per the sample):
--   id | name
--    2 | Table for painting     (category 9: "super luxury")
--    3 | Notebook desk          (category 9: "super luxury")
--    5 | Chair                  (category 9: "super luxury")
--   The "superior" category (id 7) also matches the LIKE pattern but no
--   product references it in the sample data, so it contributes nothing.
--
-- Approach:
--   Join products to categories on id_categories = categories.id and
--   filter by categories.name LIKE 'super%'. ORDER BY p.id keeps the
--   row ordering deterministic and matches the sample exactly.
SELECT p.id, p.name
FROM products p
INNER JOIN categories c ON p.id_categories = c.id
WHERE c.name LIKE 'super%'
ORDER BY p.id;

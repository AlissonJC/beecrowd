/*
 * Beecrowd 2992 - Highest Average Salary Divisions
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Inside each department there are several divisions. For every department,
 *   report the single division that has the highest average employee salary,
 *   showing the department name, that division name, and that division's
 *   average salary. Order the result by average salary, descending.
 *   (Same database as Beecrowd 2989; this asks only for each department's top
 *    division instead of all divisions.)
 *
 * Relevant schema (only the tables this query needs):
 *   departamento(cod_dep INT PK, nome, endereco)
 *   divisao(cod_divisao INT PK, nome, endereco, cod_dep NUMERIC -> departamento)
 *   empregado(matr INT PK, ..., lotacao_div INT -> divisao.cod_divisao, ...)
 *   vencimento(cod_venc INT PK, ..., valor NUMERIC)   -- earning items
 *   desconto  (cod_desc INT PK, ..., valor NUMERIC)   -- deduction items
 *   emp_venc(cod_venc, matr)   -- earnings each employee receives
 *   emp_desc(cod_desc, matr)   -- deductions each employee suffers
 *
 * Salary definition (same as 2989):
 *   salary(employee) = SUM(earnings via emp_venc) - SUM(deductions via emp_desc),
 *   where an employee with no earning rows counts as 0 (not NULL) so that they
 *   still pull down their division's average -- hence COALESCE(..., 0).
 *
 * Output: departamento, divisao, media -- one row per department, media DESC.
 *
 * Approach:
 *   1) salario : net salary per employee (LEFT JOINs + COALESCE turn "no
 *      earnings" into 0).
 *   2) div_avg : average salary of every division (join employees up to their
 *      division and department, group per division).
 *   3) ranked  : within each department, RANK divisions by average salary
 *      descending; the best division gets rank 1.
 *   4) Keep rank 1 per department and order the surviving rows by average desc.
 *
 * Output-format note:
 *   ROUND(media, 2) on NUMERIC keeps scale 2 (e.g. 5900.00). ROUND -- not TRUNC
 *   -- matches the sample (e.g. 6316.666... -> 6316.67). Ranking is done on the
 *   raw average so near-equal averages are not accidentally tied by rounding.
 *
 * Complexity:
 *   O(n log n): grouped joins to build per-division averages, then a window
 *   ranking and a final sort over the (few) divisions.
 */

WITH venc_emp AS (                 -- total earnings per employee
    SELECT ev.matr, SUM(v.valor) AS total
    FROM emp_venc ev
    JOIN vencimento v ON v.cod_venc = ev.cod_venc
    GROUP BY ev.matr
),
desc_emp AS (                      -- total deductions per employee
    SELECT ed.matr, SUM(d.valor) AS total
    FROM emp_desc ed
    JOIN desconto d ON d.cod_desc = ed.cod_desc
    GROUP BY ed.matr
),
salario AS (                       -- net salary per employee, with its division
    SELECT e.matr,
           e.lotacao_div,
           COALESCE(ve.total, 0) - COALESCE(de.total, 0) AS salary  -- no-earnings -> 0
    FROM empregado e
    LEFT JOIN venc_emp ve ON ve.matr = e.matr
    LEFT JOIN desc_emp de ON de.matr = e.matr
),
div_avg AS (                       -- average salary of each division
    SELECT dep.cod_dep,
           dep.nome AS departamento,
           div.nome AS divisao,
           AVG(s.salary) AS media
    FROM salario s
    JOIN divisao div      ON div.cod_divisao = s.lotacao_div
    JOIN departamento dep ON dep.cod_dep     = div.cod_dep
    GROUP BY dep.cod_dep, dep.nome, div.nome
),
ranked AS (                        -- rank divisions inside each department
    SELECT departamento, divisao, media,
           RANK() OVER (PARTITION BY cod_dep ORDER BY media DESC) AS rk
    FROM div_avg
)
SELECT departamento,
       divisao,
       ROUND(media, 2) AS media
FROM ranked
WHERE rk = 1                       -- keep each department's top division
ORDER BY media DESC;               -- highest average salary first

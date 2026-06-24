/*
 * Beecrowd 2989 - Departments and Divisions
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   For every division, report its department name, the division name, the
 *   average salary and the highest salary of the employees allocated to that
 *   division. Order the rows by average salary, descending.
 *
 * Relevant schema (only the tables this query needs):
 *   departamento(cod_dep INT PK, nome, endereco)
 *   divisao(cod_divisao INT PK, nome, endereco, cod_dep NUMERIC -> departamento)
 *   empregado(matr INT PK, ..., lotacao_div INT -> divisao.cod_divisao, ...)
 *   vencimento(cod_venc INT PK, nome, tipo, valor NUMERIC)   -- earning items
 *   desconto  (cod_desc INT PK, nome, tipo, valor NUMERIC)   -- deduction items
 *   emp_venc(cod_venc, matr)   -- which earnings each employee receives
 *   emp_desc(cod_desc, matr)   -- which deductions each employee suffers
 *
 * Salary definition (derived from the sample):
 *   salary(employee) = SUM(earnings via emp_venc) - SUM(deductions via emp_desc)
 *   An employee with no earning rows must count as salary 0 (not NULL): e.g.
 *   matr 725 has no emp_venc rows, yet still lowers its division's average, so
 *   COALESCE(..., 0) is required around each side.
 *
 * Output: departamento, divisao, media, maior -- ordered by media DESC.
 *
 * Approach:
 *   1) venc_emp: total earnings per employee  (emp_venc JOIN vencimento).
 *   2) desc_emp: total deductions per employee (emp_desc JOIN desconto).
 *   3) salario : LEFT JOIN both onto empregado so every employee survives, then
 *      net salary = COALESCE(earnings,0) - COALESCE(deductions,0). The LEFT JOIN
 *      plus COALESCE is exactly what turns "no earnings" into 0 instead of NULL.
 *   4) Aggregate per division (join up to divisao and departamento), taking
 *      AVG and MAX of the net salary, and order by the average descending.
 *
 * Output-format note:
 *   ROUND(value, 2) on NUMERIC keeps scale 2, so values print with two decimals
 *   including trailing zeros (e.g. 6900.00). ROUND -- not TRUNC -- is correct
 *   here: 13100/3 = 4366.666... must round up to 4366.67, matching the sample.
 *
 * Complexity:
 *   O(n log n): grouped joins over employees and their earning/deduction rows,
 *   then a final sort of the divisions.
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
)
SELECT dep.nome                       AS departamento,
       div.nome                       AS divisao,
       ROUND(AVG(s.salary), 2)        AS media,
       ROUND(MAX(s.salary), 2)        AS maior
FROM salario s
JOIN divisao div      ON div.cod_divisao = s.lotacao_div
JOIN departamento dep ON dep.cod_dep     = div.cod_dep
GROUP BY dep.nome, div.nome
ORDER BY media DESC;                   -- highest average salary first

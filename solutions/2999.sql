/*
 * Beecrowd 2999 - Highest Division Salary
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   List the name and net salary of every employee who earns MORE than the
 *   average salary of their own division AND earns 8000.00 or more. Order the
 *   result by the lotacao_div column.
 *   (Same database as Beecrowd 2989 / 2992.)
 *
 * Relevant schema (only the tables this query needs):
 *   empregado(matr INT PK, nome VARCHAR, ..., lotacao_div INT, ...)
 *   vencimento(cod_venc INT PK, ..., valor NUMERIC)   -- earning items
 *   desconto  (cod_desc INT PK, ..., valor NUMERIC)   -- deduction items
 *   emp_venc(cod_venc, matr)   -- earnings each employee receives
 *   emp_desc(cod_desc, matr)   -- deductions each employee suffers
 *
 * Net salary (same as 2989):
 *   salary(emp) = SUM(earnings via emp_venc) - SUM(deductions via emp_desc),
 *   with COALESCE(...,0) so an employee with no earnings counts as 0, not NULL
 *   (otherwise that employee would be dropped from their division's average).
 *
 * Input  : the rows already present in the tables.
 * Output : columns nome, salario -- ordered by lotacao_div.
 *
 * Sample:
 *   Jose Sampaio   8700.00   (div 12, avg 5900.00)
 *   Andre          10350.00  (div 22, avg 7733.33)
 *   Barbara        9200.00   (div 22)
 *   Jose da Silva  10650.00  (div 31, avg 6316.67)
 *
 * Approach:
 *   1) salario : net salary per employee (LEFT JOINs + COALESCE).
 *   2) div_avg : the average net salary of each division.
 *   3) Join each employee to their division average and keep those whose salary
 *      both exceeds that average and is at least 8000. Order by lotacao_div.
 *      A secondary sort by matr makes the order deterministic so that two
 *      qualifiers in the same division come out as in the sample (Andre before
 *      Barbara in division 22).
 *
 * Output-format note:
 *   ROUND(salary, 2) prints two decimals (e.g. 8700.00). Headers are nome and
 *   salario as required.
 *
 * Complexity:
 *   O(n log n): grouped joins to build salaries and division averages, then the
 *   final ordered scan of employees.
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
           e.nome,
           e.lotacao_div,
           COALESCE(ve.total, 0) - COALESCE(de.total, 0) AS salary  -- no-earnings -> 0
    FROM empregado e
    LEFT JOIN venc_emp ve ON ve.matr = e.matr
    LEFT JOIN desc_emp de ON de.matr = e.matr
),
div_avg AS (                       -- average net salary per division
    SELECT lotacao_div, AVG(salary) AS avg_salary
    FROM salario
    GROUP BY lotacao_div
)
SELECT s.nome,
       ROUND(s.salary, 2) AS salario
FROM salario s
JOIN div_avg da ON da.lotacao_div = s.lotacao_div
WHERE s.salary > da.avg_salary     -- above their division's average ...
  AND s.salary >= 8000             -- ... and at least 8000
ORDER BY s.lotacao_div, s.matr;    -- by division (matr breaks ties deterministically)

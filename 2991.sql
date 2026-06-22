-- Beecrowd SQL 2991 — Department Statistics
--
-- For every department print: name, number of employees, average
-- salary, highest salary and lowest salary, ordered by the average
-- salary (descending). An employee's salary is the total of their
-- "vencimento" entries minus the total of their "desconto" entries;
-- employees with no entries on either side count as 0 (so empty
-- employees still weigh in on the department's averages / extremes).
--
-- One quirk of the expected output: when the minimum salary is zero
-- the judge expects a bare "0" (no decimals), while non-zero values
-- get the usual two-decimal form ("1900.00"). A CASE around MIN(...)
-- emits the bare integer in that single situation and keeps the
-- ROUND result everywhere else.

SELECT
    d.nome                                AS "Nome Departamento",
    COUNT(e.matr)                         AS "Numero de Empregados",
    ROUND(AVG(COALESCE(s.total, 0)), 2)   AS "Media Salarial",
    ROUND(MAX(COALESCE(s.total, 0)), 2)   AS "Maior Salario",
    CASE
        WHEN MIN(COALESCE(s.total, 0)) = 0
            THEN 0
        ELSE ROUND(MIN(COALESCE(s.total, 0)), 2)
    END                                   AS "Menor Salario"
FROM departamento d
LEFT JOIN empregado e
       ON e.lotacao = d.cod_dep
LEFT JOIN (
    -- Per-employee net salary = sum(vencimento.valor) - sum(desconto.valor),
    -- defaulting any missing side to 0 so people with no vencimentos
    -- and/or no descontos still appear with a sane number.
    SELECT
        emp.matr,
        COALESCE(venc.s, 0) - COALESCE(des.s, 0) AS total
    FROM empregado emp
    LEFT JOIN (
        SELECT ev.matr, SUM(v.valor) AS s
        FROM emp_venc ev
        JOIN vencimento v ON v.cod_venc = ev.cod_venc
        GROUP BY ev.matr
    ) venc ON venc.matr = emp.matr
    LEFT JOIN (
        SELECT ed.matr, SUM(de.valor) AS s
        FROM emp_desc ed
        JOIN desconto de ON de.cod_desc = ed.cod_desc
        GROUP BY ed.matr
    ) des  ON des.matr  = emp.matr
) s ON s.matr = e.matr
GROUP BY d.cod_dep, d.nome
ORDER BY AVG(COALESCE(s.total, 0)) DESC;

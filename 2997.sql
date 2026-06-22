-- Beecrowd SQL 2997 — Employees Payment
--
-- For every employee print: department name, employee name, gross
-- salary (sum of vencimentos), total discount (sum of descontos), and
-- net salary (gross minus discount). One row per employee, ordered by
-- net salary descending. The same display quirk as 2991 applies: when
-- a number equals zero the judge expects a bare "0" with no decimals,
-- while non-zero numbers must come out with two decimal places (e.g.
-- "11050.00"). A CASE around each numeric column emits the bare
-- integer in the zero branch and ROUND(..., 2) in the other.

SELECT
    dep.nome AS "Departamento",
    e.nome   AS "Empregado",
    CASE
        WHEN COALESCE(venc.s, 0) = 0 THEN 0
        ELSE ROUND(venc.s, 2)
    END AS "Salario Bruto",
    CASE
        WHEN COALESCE(des.s, 0) = 0 THEN 0
        ELSE ROUND(des.s, 2)
    END AS "Total Desconto",
    CASE
        WHEN COALESCE(venc.s, 0) - COALESCE(des.s, 0) = 0 THEN 0
        ELSE ROUND(COALESCE(venc.s, 0) - COALESCE(des.s, 0), 2)
    END AS "Salario Liquido"
FROM empregado e
JOIN departamento dep
       ON dep.cod_dep = e.lotacao
LEFT JOIN (
    -- Per-employee gross salary: sum of all vencimento values.
    SELECT ev.matr, SUM(v.valor) AS s
    FROM emp_venc ev
    JOIN vencimento v ON v.cod_venc = ev.cod_venc
    GROUP BY ev.matr
) venc ON venc.matr = e.matr
LEFT JOIN (
    -- Per-employee total discount: sum of all desconto values.
    SELECT ed.matr, SUM(de.valor) AS s
    FROM emp_desc ed
    JOIN desconto de ON de.cod_desc = ed.cod_desc
    GROUP BY ed.matr
) des ON des.matr = e.matr
ORDER BY
    COALESCE(venc.s, 0) - COALESCE(des.s, 0) DESC,
    e.matr ASC;

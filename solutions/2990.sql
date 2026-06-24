/*
 * Beecrowd SQL 2990 - "Employees CPF"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   List the CPF, the employee name (enome) and the department name (dnome) of
 *   every employee who does NOT work on any project -- i.e. has no row in the
 *   trabalha table. Order the result by CPF.
 *
 * SCHEMA
 *   empregados(cpf PK varchar, enome, salario, cpf_supervisor, dnumero)
 *   departamentos(dnumero PK, dnome, cpf_gerente)
 *   trabalha(cpf_emp FK -> empregados.cpf, pnumero)   -- employee<->project link
 *   projetos(pnumero PK, pnome, dnumero)
 *
 * OUTPUT
 *   cpf | enome | dnome, one row per non-working employee, ordered by cpf.
 *
 * APPROACH
 *   Anti-join: take each employee, join to their department for dnome, and keep
 *   only those with no matching row in trabalha (NOT EXISTS).
 *
 * KEY GOTCHA -- compare CPFs numerically, not as text
 *   cpf is a varchar, and the data is inconsistent across tables: empregados
 *   stores Joao Silva as '049382234322' (leading zero) while trabalha stores the
 *   same person as '49382234322' (no leading zero). A plain string comparison
 *   would treat them as different people and wrongly report Joao as "not
 *   working", contradicting the expected output. Casting both sides to BIGINT
 *   normalises the leading zero so the two spellings match. BIGINT (not INT) is
 *   required because values such as 586733922290 exceed the 32-bit range.
 *
 * COMPLEXITY
 *   O(E) employees, each probing trabalha; trivial for this data size.
 */

SELECT e.cpf, e.enome, d.dnome
FROM empregados e
JOIN departamentos d ON d.dnumero = e.dnumero
-- "Works on no project": no trabalha row matches this employee. Match on the
-- numeric value of the CPF so '049382234322' and '49382234322' are recognised
-- as the same person despite the leading-zero difference between the tables.
WHERE NOT EXISTS (
    SELECT 1
    FROM trabalha t
    WHERE CAST(t.cpf_emp AS BIGINT) = CAST(e.cpf AS BIGINT)
)
ORDER BY e.cpf;

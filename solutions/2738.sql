/*
 * Beecrowd SQL 2738 - "Contest"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   Rank candidates for open research positions. For each candidate print the
 *   name and the final weighted score to two decimal places, listed from the
 *   highest score to the lowest. The weighted average is:
 *       avg = (math*2 + specific*3 + project_plan*5) / 10
 *
 * SCHEMA
 *   candidate(id PK, name)
 *   score(candidate_id FK -> candidate.id, math, specific, project_plan)
 *
 * OUTPUT
 *   Two columns: name and avg (two decimals), ordered by avg descending.
 *
 * APPROACH
 *   Join each candidate to their score row, compute the weighted average inline,
 *   and sort by it descending. ROUND(..., 2) returns a numeric of scale 2 so the
 *   value prints with both decimals (e.g. "47.00", "74.10") to match Beecrowd's
 *   exact-text comparison. Dividing by 10.0 keeps the division in numeric/decimal
 *   arithmetic (no risk of integer-division truncation).
 *
 * COMPLEXITY
 *   O(N) over the candidates for the join + a sort; trivial here.
 */

SELECT
    c.name,
    -- Weighted average, fixed to two decimals so it prints as e.g. 47.00.
    ROUND((s.math * 2 + s.specific * 3 + s.project_plan * 5) / 10.0, 2) AS avg
FROM candidate c
JOIN score s ON s.candidate_id = c.id
ORDER BY avg DESC;   -- highest score first

/*
 * Beecrowd 2988 - Cearense Championship
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Build a league standings table from the played matches. For every team show
 *   its name, number of matches played, victories, defeats, draws, and total
 *   score, where a win is worth 3 points, a draw 1, and a loss 0. List the
 *   table from the highest score to the lowest.
 *
 * Schema:
 *   teams(
 *     id   INTEGER PRIMARY KEY,
 *     name VARCHAR(50)
 *   )
 *   matches(
 *     id           INTEGER PRIMARY KEY,
 *     team_1       INTEGER,   -- FK -> teams.id (home side)
 *     team_2       INTEGER,   -- FK -> teams.id (away side)
 *     team_1_goals INTEGER,
 *     team_2_goals INTEGER
 *   )
 *
 * Input  : the rows already present in both tables.
 * Output : columns name, matches, victories, defeats, draws, score -- one row
 *          per team, ordered by score descending.
 *
 * Sample:
 *   name                matches victories defeats draws score
 *   CEARA               3       2         0       1     7
 *   FORTALEZA           3       2         0       1     7
 *   FLORESTA            3       1         2       0     3
 *   GUARANY DE SOBRAL   3       0         3       0     0
 *
 * Approach:
 *   A team appears in a match either as team_1 or as team_2, so first normalize
 *   each match into two "one team's view" rows via UNION ALL: (team, goals_for,
 *   goals_against). The CTE `games` holds these 2*|matches| rows. Joining that
 *   to `teams` and grouping by team lets a single aggregation derive every
 *   column: COUNT(*) for matches, and SUM(CASE ...) to count wins/losses/draws
 *   and to add up the score (3 for gf>ga, 1 for a tie, 0 otherwise). Finally
 *   ORDER BY score DESC.
 *
 * Tie-break note:
 *   The statement gives no tie-break rule, and CEARA and FORTALEZA both finish
 *   on 7. The sample lists them in ascending id order (CEARA id 1 before
 *   FORTALEZA id 2), so t.id is added as a deterministic secondary sort key to
 *   reproduce that order exactly.
 *
 * Assumption:
 *   Every team has played at least one match in this dataset, so an inner JOIN
 *   is sufficient (a team with zero games would need a LEFT JOIN + COUNT of the
 *   match key instead of COUNT(*)).
 *
 * Complexity:
 *   O(m + n log n): one scan over the 2*m normalized game rows for the
 *   aggregation, plus the final sort of the n teams.
 */

WITH games AS (
    -- Each match contributes two rows: one from each team's perspective.
    SELECT team_1 AS team, team_1_goals AS gf, team_2_goals AS ga FROM matches
    UNION ALL
    SELECT team_2 AS team, team_2_goals AS gf, team_1_goals AS ga FROM matches
)
SELECT t.name,
       COUNT(*)                                              AS matches,
       SUM(CASE WHEN g.gf > g.ga THEN 1 ELSE 0 END)          AS victories,
       SUM(CASE WHEN g.gf < g.ga THEN 1 ELSE 0 END)          AS defeats,
       SUM(CASE WHEN g.gf = g.ga THEN 1 ELSE 0 END)          AS draws,
       SUM(CASE WHEN g.gf > g.ga THEN 3                      -- win  -> 3 points
                WHEN g.gf = g.ga THEN 1                      -- draw -> 1 point
                ELSE 0 END)                                  AS score
FROM teams t
JOIN games g ON g.team = t.id
GROUP BY t.id, t.name
ORDER BY score DESC, t.id;   -- highest score first; id breaks the points tie

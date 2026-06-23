/*
 * Beecrowd 3492 - "Ranking turismo CE" (Ceara Tourism Ranking)
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   The Ceara State Department of Tourism wants a report over its cities. For
 *   each city it needs: the city name and its region, how many tourist
 *   attractions it has, the average visitor rating of those attractions, and
 *   the city's position (ranking) inside its own region ordered by that average
 *   rating, highest first. Only cities that have at least 2 registered
 *   attractions belong in the report. Rows come out ordered by region and then
 *   by the regional ranking.
 *
 * SCHEMA
 *   Cidades(cidade_id, nome_cidade, regiao)
 *   PontosTuristicos(ponto_id, nome_ponto, cidade_id)   -- attractions per city
 *   Avaliacoes(avaliacao_id, ponto_id, nota)            -- nota is a 1..5 rating
 *
 * OUTPUT COLUMNS
 *   nome_cidade | regiao | qtd_pontos | media_avaliacoes | ranking_regional
 *
 * APPROACH
 *   Join each city to its attractions and to the ratings of those attractions,
 *   then aggregate per city. Two subtleties decide the whole problem:
 *     1) The rating join multiplies rows (an attraction with k ratings yields k
 *        rows), so the attraction count must use COUNT(DISTINCT ponto_id); a
 *        plain COUNT would overcount. The average, on the other hand, is taken
 *        over every individual rating row -- it is rating-weighted, which the
 *        sample confirms: Fortaleza = (5+4+3)/3 = 4.00, not the per-attraction
 *        average 3.75.
 *     2) Use a LEFT JOIN to the ratings so an attraction with no rating still
 *        counts toward qtd_pontos (AVG simply skips its NULL nota).
 *   Keep only cities with >= 2 attractions (HAVING). Finally, RANK() partitioned
 *   by region and ordered by the average descending gives ranking_regional, and
 *   the outer ORDER BY emits region-by-region, best-rated city first.
 *
 * NOTE ON THE STATEMENT'S OUTPUT TABLE
 *   The illustration lists all four cities, but Juazeiro ("-") and Sobral (blank)
 *   are shown dimmed: each has a single attraction, so the ">= 2" rule drops them.
 *   The real result is the two Litoral cities below.
 *
 * COMPLEXITY
 *   One pass of joins + group-by + a window rank: O(R log R) on the number of
 *   joined rating rows R, dominated by the grouping/sort. Trivial for this size.
 */

WITH city_stats AS (
    SELECT
        c.cidade_id,
        c.nome_cidade,
        c.regiao,
        -- DISTINCT is essential: the LEFT JOIN below repeats an attraction once
        -- per rating it has, so without DISTINCT the count would be inflated.
        COUNT(DISTINCT p.ponto_id)        AS qtd_pontos,
        -- Rating-weighted average over all notas; ROUND to numeric(.,2) so the
        -- value prints as "4.00"/"4.33" to match Beecrowd's exact-text compare.
        ROUND(AVG(a.nota), 2)             AS media_avaliacoes
    FROM Cidades c
    JOIN PontosTuristicos p ON p.cidade_id = c.cidade_id
    -- LEFT JOIN: an attraction with zero ratings still contributes to the count;
    -- its NULL nota is ignored by AVG.
    LEFT JOIN Avaliacoes a  ON a.ponto_id  = p.ponto_id
    GROUP BY c.cidade_id, c.nome_cidade, c.regiao
    -- Only cities with at least 2 registered attractions enter the report.
    HAVING COUNT(DISTINCT p.ponto_id) >= 2
)
SELECT
    nome_cidade,
    regiao,
    qtd_pontos,
    media_avaliacoes,
    -- Position within the region by average rating, highest first. RANK() lets
    -- two cities tied on average share the same position.
    RANK() OVER (PARTITION BY regiao ORDER BY media_avaliacoes DESC) AS ranking_regional
FROM city_stats
-- Group the report region by region, and inside each region best rank first.
ORDER BY regiao, ranking_regional;

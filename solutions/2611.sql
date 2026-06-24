/*
 * Beecrowd SQL 2611 - "Action Movies"
 * Dialect: PostgreSQL
 *
 * PROBLEM
 *   Cataloguing a video store: list the code (id) and the name of every movie
 *   whose genre description is 'Action'.
 *
 * SCHEMA
 *   movies(id PK, name, id_genres FK -> genres.id)
 *   genres(id PK, description)
 *
 * OUTPUT
 *   Two columns: id, name -- one row per Action movie.
 *
 * APPROACH
 *   Inner-join movies to genres on the foreign key and keep only the rows whose
 *   genre description is 'Action'. Filtering by the genre NAME (not a hard-coded
 *   id) follows the statement and is robust to whichever id 'Action' has.
 *
 * COMPLEXITY
 *   O(M) over the movies rows for the join + filter; trivial here.
 */

SELECT m.id, m.name
FROM movies m
JOIN genres g ON g.id = m.id_genres
-- Restrict to the Action genre, matched by its description as the statement asks
-- rather than by a literal genre id.
WHERE g.description = 'Action';

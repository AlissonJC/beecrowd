/*
 * Beecrowd 3480 - Adjacent Chairs
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Chairs are arranged in rows ("queue"); each chair is available or not.
 *   Find every pair of side-by-side chairs in the SAME row that are both
 *   available. Report the row, the left chair's id and the right chair's id,
 *   ordered by the left id.
 *
 * Schema:
 *   chairs(
 *     id        NUMERIC,    -- chair number; consecutive ids are adjacent
 *     queue     NUMERIC,    -- the row the chair belongs to
 *     available BOOLEAN
 *   )
 *
 * Input  : the rows already present in the `chairs` table.
 * Output : columns queue, left, right -- one row per adjacent available pair,
 *          ordered by left ascending.
 *
 * Sample:
 *   queue  left  right
 *   1      7     8
 *   2      11    12
 *   2      14    15
 *   3      21    22
 *   4      28    29
 *
 * Approach:
 *   Self-join the table so c2 sits immediately to the right of c1
 *   (c2.id = c1.id + 1). Two chairs are only neighbours when they share the
 *   same row, so the join also requires c2.queue = c1.queue -- this is what
 *   rejects a "pair" that straddles the boundary between two rows (e.g. ids 8
 *   and 9). Keep pairs where both chairs are available, then order by the left
 *   id.
 *
 * Output-format note:
 *   `left` and `right` are reserved words in PostgreSQL, so the aliases are
 *   double-quoted to use them as the (lower-case) output headers required by
 *   the problem.
 *
 * Complexity:
 *   O(n) over the n chairs given an index on (queue, id); the self-join matches
 *   each chair with at most one neighbour.
 */

SELECT c1.queue,
       c1.id AS "left",    -- smaller id of the adjacent pair
       c2.id AS "right"    -- the chair immediately to its right
FROM chairs c1
JOIN chairs c2 ON c2.id = c1.id + 1     -- physically next chair ...
             AND c2.queue = c1.queue    -- ... and in the same row
WHERE c1.available
  AND c2.available                      -- both seats free
ORDER BY c1.id;                         -- order by the left chair

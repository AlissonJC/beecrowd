/*
 * Beecrowd 2996 - Package Delivery
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   For a delivery company, list the year, the sender's name and the receiver's
 *   name of every package that is either blue OR from 2015, and where NEITHER
 *   the sender NOR the receiver is located in Taiwan. Order by year, descending.
 *
 * Schema:
 *   users(id NUMERIC PK, name VARCHAR, type CHAR, address VARCHAR)
 *   packages(
 *     id_package       NUMERIC PK,
 *     id_user_sender   INTEGER -> users.id,
 *     id_user_receiver INTEGER -> users.id,
 *     color            VARCHAR,
 *     year             INTEGER
 *   )
 *
 * Input  : the rows already present in both tables.
 * Output : columns year, sender, receiver -- ordered by year descending.
 *
 * Sample:
 *   year  sender            receiver
 *   2019  Elizabeth O'Neil  Jim Gray          (package 6, blue)
 *   2019  Edgar Codd        Jim Gray          (package 2, blue)
 *   2015  Jim Gray          Elizabeth O'Neil  (package 5, year 2015)
 *
 * Approach:
 *   Join packages to `users` twice -- once for the sender, once for the receiver
 *   -- to fetch both names and both addresses. Keep packages that are blue or
 *   from 2015, AND where both endpoints avoid Taiwan. Note the wording trap:
 *   "sender or receiver is not from Taiwan" actually means NEITHER is from
 *   Taiwan, i.e. sender.address <> 'Taiwan' AND receiver.address <> 'Taiwan'
 *   (a single Taiwan endpoint excludes the package -- e.g. the blue/2015
 *   package 1 is dropped because its receiver is in Taiwan).
 *
 * Output-format note:
 *   The statement only orders by year (descending). A secondary id_package DESC
 *   is added so the within-year order is deterministic and matches the sample
 *   (package 6 before package 2 in 2019).
 *
 * Complexity:
 *   O(n log n) over the n packages, dominated by the final ordering.
 */

SELECT p.year,
       s.name AS sender,
       r.name AS receiver
FROM packages p
JOIN users s ON s.id = p.id_user_sender      -- the sender
JOIN users r ON r.id = p.id_user_receiver    -- the receiver
WHERE (p.color = 'blue' OR p.year = 2015)    -- blue, or from 2015
  AND s.address <> 'Taiwan'                  -- sender not in Taiwan ...
  AND r.address <> 'Taiwan'                  -- ... and receiver not in Taiwan
ORDER BY p.year DESC,        -- newest year first
         p.id_package DESC;  -- deterministic tie-break to match the sample

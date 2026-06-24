/*
 * Beecrowd 3482 - Followers
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   In a social network, find every pair of users that follow each other
 *   (a mutual / reciprocal follow). For each such pair print the two user names:
 *   the user with the FEWER posts in the first column and the user with MORE
 *   posts in the second. Order the result by the user id shown in the first
 *   column.
 *
 * Schema:
 *   users(
 *     user_id   NUMERIC PRIMARY KEY,
 *     user_name VARCHAR,
 *     posts     NUMERIC
 *   )
 *   followers(
 *     follower_id          NUMERIC PRIMARY KEY,
 *     user_id_fk           NUMERIC,  -- the follower            (-> users.user_id)
 *     following_user_id_fk NUMERIC   -- the one being followed  (-> users.user_id)
 *   )
 *   A followers row means: user_id_fk follows following_user_id_fk.
 *
 * Input  : the rows already present in both tables.
 * Output : columns u1_name, u2_name -- one row per mutual pair, ordered by the
 *          first user's id.
 *
 * Sample:
 *   u1_name     u2_name
 *   Francisco   Laura     (1<->5, posts 23 < 55)
 *   Brenda      Miguel    (2<->4, posts 51 < 70)
 *   Laura       Miguel    (5<->4, posts 55 < 70)
 *   Alice       Helena    (7<->3, posts  3 < 12)
 *
 * Approach:
 *   Self-join `followers` to itself to find reciprocal edges: f1 is "a follows
 *   b" and f2 is the reverse "b follows a", matched by
 *   f1.user_id_fk = f2.following_user_id_fk AND
 *   f1.following_user_id_fk = f2.user_id_fk. Each mutual pair surfaces twice
 *   (once per orientation). Joining both endpoints to `users` and keeping only
 *   the orientation where the first user has fewer posts (u1.posts < u2.posts)
 *   does double duty: it removes the duplicate AND forces the required
 *   "fewer posts first" column order. Finally order by the first user's id.
 *
 * Edge note:
 *   The strict "<" assumes the two users in a mutual pair never have identical
 *   post counts (true for this data); equal counts would otherwise drop the
 *   pair. Self-follows cannot occur because a==b would make u1.posts < u2.posts
 *   false.
 *
 * Complexity:
 *   O(E^2) worst case for the self-join over E follow edges (tiny here); the
 *   final ordering is O(k log k) over the k mutual pairs.
 */

SELECT u1.user_name AS u1_name,   -- fewer posts  -> first column
       u2.user_name AS u2_name    -- more posts   -> second column
FROM followers f1
JOIN followers f2
       ON f1.user_id_fk           = f2.following_user_id_fk   -- a follows b ...
      AND f1.following_user_id_fk = f2.user_id_fk             -- ... and b follows a
JOIN users u1 ON u1.user_id = f1.user_id_fk
JOIN users u2 ON u2.user_id = f1.following_user_id_fk
WHERE u1.posts < u2.posts          -- dedupe each pair + order columns by posts
ORDER BY u1.user_id;               -- order by the first column's user id

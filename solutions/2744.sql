/*
 * Beecrowd 2744 - Passwords
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Passwords are stored in plain text, which is insecure. For every account
 *   show the id, the original (plain) password, and the MD5 hash of that
 *   password.
 *
 * Schema:
 *   account(
 *     id       INTEGER PRIMARY KEY,
 *     name     VARCHAR,
 *     login    VARCHAR,
 *     password VARCHAR
 *   )
 *
 * Input  : the rows already present in the `account` table.
 * Output : three columns -> id, password, MD5 (one row per account).
 *
 * Sample:
 *   id  password      MD5
 *   1   noh1Oozei     b67ed42ced0e0a19ce7ed904bb94b607
 *   2   Iath3see9bi   66877b2da87fb09af3f5602f31c6d35c
 *   ...
 *
 * Approach:
 *   PostgreSQL ships a built-in MD5() that takes text and returns the 32-char
 *   lowercase hexadecimal digest -- exactly the format shown in the sample.
 *   So the whole task is one projection: id, the raw password, and
 *   MD5(password).
 *
 * Output-format note:
 *   The expected header is the upper-case "MD5". Unquoted identifiers in
 *   PostgreSQL fold to lower case (AS MD5 -> md5), so the alias is quoted
 *   AS "MD5" to reproduce the header casing verbatim.
 *
 * Complexity:
 *   O(n) over the n account rows; one hash computation per row.
 */

SELECT id,
       password,
       MD5(password) AS "MD5"   -- 32-char lowercase hex; quoted alias keeps the case
FROM account;

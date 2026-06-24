/*
 * Beecrowd 2741 - Students Grades
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   List the approved students of a course. A student is approved when their
 *   grade is at least 7. For each approved student print the name prefixed by
 *   "Approved: " together with the grade, ordered from the highest grade down.
 *
 * Schema:
 *   students(
 *     id    INTEGER PRIMARY KEY,
 *     name  VARCHAR,
 *     grade NUMERIC
 *   )
 *
 * Input  : the rows already present in the `students` table.
 * Output : two columns -> `name` (prefixed) and `grade`, only for grade >= 7,
 *          sorted by grade descending.
 *
 * Sample:
 *   name                          grade
 *   Approved: Ben M. Dantzler     9.6
 *   Approved: Terry B. Padilla    7.3
 *   (Julie B. Manzer, 6.7, is NOT approved -> 6.7 < 7)
 *
 * Approach:
 *   A single filtered, ordered projection. WHERE grade >= 7 keeps only the
 *   approved students; the threshold is inclusive ("grade >= 7"), so a 7.0
 *   would pass while 6.7 is rejected. The name column is built by
 *   concatenating the literal 'Approved: ' with the student name via `||`.
 *   ORDER BY grade DESC yields "higher grades first".
 *
 * Output-format note:
 *   `grade` is printed straight from the column. It is a stored value, not a
 *   computed average, so its scale is preserved as-is (7.3 prints as 7.3) -- no
 *   ROUND/TRUNC is needed here. Keep the prefix exactly "Approved: " (trailing
 *   space) and alias both output columns to the expected headers name/grade.
 *
 * Complexity:
 *   O(n log n) dominated by the ORDER BY sort over the n student rows.
 */

SELECT 'Approved: ' || name AS name,   -- literal tag + student name
       grade
FROM students
WHERE grade >= 7                       -- inclusive pass mark
ORDER BY grade DESC;                   -- highest grades first

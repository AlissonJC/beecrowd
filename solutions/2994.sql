/*
 * Beecrowd 2994 - How much does a Doctor earn?
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   Each doctor earns 150 per hour, increased by a percentage bonus that
 *   depends on the work shift of each attendance. Compute every doctor's total
 *   pay (summed over all their attendances) and list it from highest to lowest.
 *
 * Schema:
 *   doctors(id INT PK, name VARCHAR)
 *   work_shifts(id INT PK, name VARCHAR, bonus NUMERIC)   -- bonus is a percent
 *   attendances(id INT PK, id_doctor INT -> doctors.id,
 *               hours INT, id_work_shift INT -> work_shifts.id)
 *
 * Input  : the rows already present in the three tables.
 * Output : columns name, salary -- one row per doctor, ordered by salary DESC.
 *
 * Pay formula (from the worked example):
 *   per attendance: hours * 150 * (1 + bonus/100)
 *   Wellington = (1*150)*(1+1/100) + (2*150)*(1+15/100) = 151.5 + 345 = 496.5
 *
 * Sample:
 *   Arlino 1620.0, Amanda 1110.0, Tiago 915.0, Wellington 496.5
 *
 * Approach:
 *   Join each attendance to its doctor and its work shift so the bonus is
 *   available, compute the per-attendance pay hours*150*(1 + bonus/100), sum it
 *   per doctor, and order by that total descending. The bonus is divided by
 *   100.0 to apply it as a percentage (also avoids integer-division surprises).
 *
 * Output-format note:
 *   ROUND(total, 1) gives one decimal place (e.g. 915.0, 496.5), as required.
 *
 * Complexity:
 *   O(a + n log n): one pass over the a attendances for the grouped join, then
 *   a sort of the n doctors.
 */

SELECT d.name,
       ROUND(SUM(a.hours * 150 * (1 + ws.bonus / 100.0)), 1) AS salary
FROM doctors d
JOIN attendances a  ON a.id_doctor = d.id
JOIN work_shifts ws ON ws.id = a.id_work_shift
GROUP BY d.id, d.name
ORDER BY salary DESC;   -- highest earner first

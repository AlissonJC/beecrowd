/*
 * Beecrowd 3481 - Classifying a Tree
 * Platform: Beecrowd (SQL category) - PostgreSQL dialect
 *
 * Problem restatement:
 *   A binary tree is stored as edges in the `nodes` table: a row (node_id,
 *   pointer) means node_id has pointer as a child; a leaf is stored with
 *   pointer = NULL. Classify every node as ROOT, INNER, or LEAF and list the
 *   nodes ordered by node_id.
 *
 * Schema:
 *   nodes(
 *     node_id NUMERIC,   -- a node
 *     pointer NUMERIC     -- one of its children, or NULL when it has none
 *   )
 *
 * Input  : the rows already present in the `nodes` table.
 * Output : columns node_id, type, ordered by node_id ascending.
 *
 * Classification rules:
 *   ROOT  : the node nobody points to (never appears as a non-NULL `pointer`).
 *   LEAF  : a node with no children (it never appears as a node_id with a
 *           non-NULL pointer).
 *   INNER : everything else (it has both a parent and at least one child).
 *
 * Sample:
 *   node_id 50 is ROOT; 1, 20, 32, 40, 55, 70, 80, 95 are LEAF; the rest
 *   (15, 30, 35, 60, 75, 90) are INNER.
 *
 * Approach:
 *   Iterate the distinct node ids. For each, two existence tests decide the
 *   class: "is it a child?" (does any row have pointer = this node) and "does it
 *   have a child?" (does any row have node_id = this node with a non-NULL
 *   pointer). A CASE checks ROOT first (no parent), then LEAF (no child),
 *   otherwise INNER. Every node has its own node_id row (leaves are stored as
 *   (leaf, NULL)), so DISTINCT node_id enumerates all nodes.
 *
 * Complexity:
 *   O(n) distinct nodes, each probing the indexed edge set -> effectively
 *   O(n) over the small tree.
 */

SELECT n.node_id,
       CASE
           -- no row points TO this node -> it is the root
           WHEN NOT EXISTS (SELECT 1 FROM nodes p
                            WHERE p.pointer = n.node_id)                THEN 'ROOT'
           -- this node has no non-NULL child -> it is a leaf
           WHEN NOT EXISTS (SELECT 1 FROM nodes c
                            WHERE c.node_id = n.node_id
                              AND c.pointer IS NOT NULL)                THEN 'LEAF'
           -- has both a parent and a child
           ELSE 'INNER'
       END AS type
FROM (SELECT DISTINCT node_id FROM nodes) n
ORDER BY n.node_id;

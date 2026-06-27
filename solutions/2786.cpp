/*
 * Beecrowd 2786 — School Floor
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   An L x C rectangular floor is tiled with square tiles laid as diamonds
 *   (each tile has a 1-meter diagonal, set parallel to the room's sides).
 *   Three tile shapes appear: type 1 is a whole diamond, type 2 is half a
 *   diamond (a triangle), and type 3 is half a triangle (a corner quarter).
 *   Count how many type 1 and type 2 tiles are needed. (Type 3 is always 4,
 *   one per corner, and is not requested.)
 *
 * Input:
 *   Two lines: integer L (1 <= L <= 100) then integer C (1 <= C <= 100).
 *
 * Output:
 *   Two lines: the count of type 1 tiles, then the count of type 2 tiles.
 *
 * Approach:
 *   The diamonds form two interleaved lattices. Diamonds centered at the
 *   unit-cell centers number L*C and are all whole. Diamonds centered at the
 *   integer grid points are whole when interior — (L-1)*(C-1) of them — half
 *   (type 2) when on an edge, and quarter (type 3) at the four corners.
 *   Counting the edge half-diamonds along the four sides gives
 *   2*(L-1) + 2*(C-1). Hence:
 *       type1 = L*C + (L-1)*(C-1)
 *       type2 = 2*(L + C - 2)
 *   (Check: 2*type1 + type2 = 4*L*C - 2, the floor area in eighth-tiles.)
 *
 * Complexity:
 *   O(1) time and space.
 */

#include <cstdio>

int main() {
    int L, C;
    scanf("%d %d", &L, &C);  // the two values sit on separate lines

    // Whole diamonds: one per cell center plus the interior grid points.
    int type1 = L * C + (L - 1) * (C - 1);
    // Half diamonds: the non-corner grid points along the four edges.
    int type2 = 2 * (L + C - 2);

    printf("%d\n%d\n", type1, type2);
    return 0;
}

/*
 * Beecrowd 2203 — Crowstorm
 *
 * Fiddlesticks (at F) ults toward an invader (at I): he channels for 1.5 s and
 * then teleports up to R1 along the direction of the invader, dealing damage in
 * a radius R2 around the landing point. During the channel the invader flees
 * directly away from F at speed Vi. Decide whether the invader can be hit.
 *
 * Because Fiddlesticks aims exactly at the invader and the invader flees
 * straight away from F, the points F, the invader and the landing spot stay
 * collinear. The invader ends at distance d0 + 1.5*Vi from F (d0 = |F - I|);
 * Fiddlesticks can land up to R1 away and the crows reach R2 beyond that, so a
 * hit is possible iff:
 *       d0 + 1.5 * Vi <= R1 + R2.
 *
 * To stay in exact integer arithmetic, multiply by 2 and square:
 *       2*d0 <= 2*(R1 + R2) - 3*Vi
 *   Let rhs = 2*(R1 + R2) - 3*Vi. If rhs < 0 the answer is "N"; otherwise the
 *   condition becomes 4*d0^2 <= rhs^2, i.e.
 *       4 * ((Xf-Xi)^2 + (Yf-Yi)^2) <= rhs^2.
 *
 * Input:
 *   Several lines until EOF, each: Xf Yf Xi Yi Vi R1 R2 (all in [0, 100]).
 *
 * Output:
 *   "Y" if the invader can be reached, otherwise "N", one per line.
 *
 * Complexity:
 *   O(1) per line.
 */

#include <cstdio>

int main() {
    long long xf, yf, xi, yi, vi, r1, r2;
    while (scanf("%lld %lld %lld %lld %lld %lld %lld",
                 &xf, &yf, &xi, &yi, &vi, &r1, &r2) == 7) {
        long long dx = xf - xi, dy = yf - yi;
        long long distSq = dx * dx + dy * dy;     // d0^2

        // rhs = 2*(R1+R2) - 3*Vi  is  2*(R1+R2) - 2*(1.5*Vi), kept integer.
        long long rhs = 2 * (r1 + r2) - 3 * vi;

        // Reachable iff rhs is non-negative and (2*d0)^2 <= rhs^2.
        bool reachable = (rhs >= 0) && (4 * distSq <= rhs * rhs);
        puts(reachable ? "Y" : "N");
    }
    return 0;
}

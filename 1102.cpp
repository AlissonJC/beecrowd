/*
 * Beecrowd 1102 — Deadly Attack
 * Time limit: 1 s
 *
 * Multiple test cases ended by "0 0 0". Each test case has the disk
 * (X, Y, R) representing the protecting wall and the cannon (P, Q, A,
 * T): position, beam direction A (deg, ccw from x-axis) and full
 * spread T (deg). Output the area of the disk destroyed by the cone-
 * shaped beam to one decimal place. The cannon is always outside the
 * wall (distance(cannon, centre) > R).
 *
 * Derivation:
 *   Place the cannon at the origin. Let d = distance to disk centre
 *   and phi = direction angle to that centre. For a ray at angle
 *   theta from the cannon, set beta = theta - phi. The ray hits the
 *   disk iff |beta| <= alpha where alpha = asin(R / d) (tangent
 *   half-angle). When it hits, intersect points are at radii
 *       r = d*cos(beta) +/- sqrt(R^2 - d^2*sin^2(beta)),
 *   so the chord squared difference is
 *       r2^2 - r1^2 = 4*d*cos(beta)*sqrt(R^2 - d^2*sin^2(beta)).
 *   The destroyed area inside an angular slice [b1, b2] is
 *       (1/2) * integral of (r2^2 - r1^2) dbeta
 *     = 2*d * integral cos(beta)*sqrt(R^2 - d^2*sin^2(beta)) dbeta.
 *   Substituting u = d*sin(beta)/R gives the clean closed form
 *       Area = R^2 * (g(u2) - g(u1))    with g(u) = u*sqrt(1-u^2) + asin(u).
 *   The full disk corresponds to u going -1 -> 1 and yields pi*R^2,
 *   as expected.
 *
 * Algorithm:
 *   1. Compute d, phi, alpha.
 *   2. Beam covers theta in [A_rad - T_rad/2, A_rad + T_rad/2]. The
 *      "tangent cone" covers [phi - alpha, phi + alpha]. Because both
 *      intervals are shorter than pi, only a single 2*pi shift of the
 *      tangent cone can intersect the beam; iterate over a small
 *      neighbourhood of shifts to find the matching one without
 *      worrying about modular arithmetic.
 *   3. For the intersected angular range, convert endpoints to beta,
 *      then to u, and accumulate R^2 * (g(u_hi) - g(u_lo)).
 *
 * Complexity:
 *   O(1) per test case (a handful of transcendental ops).
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, R;
    while (scanf("%d %d %d", &X, &Y, &R) == 3) {
        if (X == 0 && Y == 0 && R == 0) break;
        int P, Q, A, Tdeg;
        scanf("%d %d %d %d", &P, &Q, &A, &Tdeg);

        double dx = X - P, dy = Y - Q;
        double d = sqrt(dx * dx + dy * dy);
        double alpha = asin((double)R / d);
        double phi = atan2(dy, dx);
        double Arad = A * M_PI / 180.0;
        double Trad = Tdeg * M_PI / 180.0;
        double beamLo = Arad - Trad / 2.0;
        double beamHi = Arad + Trad / 2.0;

        // The integrand antiderivative; clamping keeps the inverse trig
        // happy when rounding nudges |u| slightly past 1.
        auto g = [](double u) {
            if (u > 1.0)  u = 1.0;
            if (u < -1.0) u = -1.0;
            return u * sqrt(max(0.0, 1.0 - u * u)) + asin(u);
        };

        double area = 0.0;
        // The beam and the tangent cone are each shorter than pi, so at
        // most one shift of the tangent cone by a multiple of 2*pi can
        // intersect the beam. Try a few shifts and take whichever one
        // produces a non-empty overlap.
        for (int k = -2; k <= 2; k++) {
            double tcLo = phi - alpha + 2.0 * M_PI * k;
            double tcHi = phi + alpha + 2.0 * M_PI * k;
            double lo = max(beamLo, tcLo);
            double hi = min(beamHi, tcHi);
            if (hi <= lo) continue;

            double betaLo = lo - phi - 2.0 * M_PI * k;
            double betaHi = hi - phi - 2.0 * M_PI * k;
            double uLo = d * sin(betaLo) / R;
            double uHi = d * sin(betaHi) / R;
            area += (double)R * R * (g(uHi) - g(uLo));
        }

        printf("%.1f\n", area);
    }
    return 0;
}

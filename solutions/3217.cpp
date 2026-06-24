/*
 * Beecrowd 3217 - Rain Fall
 *
 * A vertical rain-collection tube has a leak at height L (mm). While the water
 * level is strictly above the leak, water drains at K mm/h; at or below the
 * leak nothing drains. Rain falls at an unknown but constant rate for T1 hours
 * (so the total rainfall is F = rate * T1), then T2 more hours pass, after
 * which the level is observed to be H mm. Report the smallest (F1) and largest
 * (F2) total rainfall that could produce that observation.
 *
 * Input : one line with five positive two-decimal numbers  L K T1 T2 H,
 *         each in [0.01, 1000.00].
 * Output: two numbers  F1 F2  (six decimals); error < 1e-6 accepted.
 *
 * Model and why a *range* can appear
 * ----------------------------------
 * During the rain the level rises monotonically to a peak; during the T2 wait
 * it can only fall, and only down to L (water below the leak never drains).
 * Hence the final level is a NON-DECREASING function of the total rainfall F:
 * pumping in more water can never leave the column lower at any instant. That
 * function is strictly increasing everywhere except for a single flat stretch
 * pinned at H = L (while the post-rain column still has time to drain back to
 * the leak). So multiple rainfalls match the observation only when H == L.
 *
 *   H < L : the water never reached the leak, so nothing ever drained and the
 *           tube kept every drop -> F = H, and nothing else fits (more rain
 *           would reach the leak and finish at >= L). Unique.
 *
 *   H = L : an interval of rainfalls fits.
 *             F1 = L          (just reach L at the final instant, lose nothing)
 *             F2 = quadratic  (rise to L + K*T2, drain back to L during T2)
 *
 *   H > L : the final level fixes the rate uniquely (strictly increasing here);
 *           F1 = F2 = quadratic.
 *
 * The quadratic: the peak level reached during the rain is L + (r-K)(T1 - L/r),
 * where r is the rain rate. Requiring the column to drain to the observation,
 * peak = H + K*T2, and clearing denominators gives
 *         T1*r^2 - (K*T1 + K*T2 + H)*r + K*L = 0.
 * Its larger root is the physical rate (the smaller root falls below K, where
 * water could not have risen past the leak at all); the rainfall is r * T1.
 *
 * Complexity: O(1) per observation.
 */

#include <cstdio>
#include <cmath>

int main() {
    double L, K, T1, T2, H;

    // EOF-terminated read: handles the single observation per the statement,
    // and stays correct if the judge happens to stack several on the input.
    while (scanf("%lf %lf %lf %lf %lf", &L, &K, &T1, &T2, &H) == 5) {
        const double eps = 1e-9;

        // Larger root of  T1*r^2 - (K*T1 + K*T2 + H)*r + K*L = 0,  then F = r*T1.
        // b is negative, so (-b + sqrt(disc)) adds two positives: no cancellation.
        double a = T1;
        double b = -(H + K * T2 + K * T1);
        double c = K * L;
        double disc = b * b - 4.0 * a * c;
        if (disc < 0.0) disc = 0.0;                 // clamp rounding noise
        double rate = (-b + sqrt(disc)) / (2.0 * a);
        double Froot = rate * T1;

        double F1, F2;
        if (H < L - eps) {
            // Ended below the leak: every drop retained, rainfall equals H.
            F1 = F2 = H;
        } else if (H < L + eps) {
            // Ended exactly at the leak: a genuine range of rainfalls.
            F1 = L;          // minimum: barely reach the leak, no leakage
            F2 = Froot;      // maximum: overfill to L + K*T2, drain back to L
        } else {
            // Ended above the leak: rainfall determined uniquely.
            F1 = F2 = Froot;
        }

        // Print nine decimals: the Beecrowd judge compares the text tightly
        // here (six decimals are rejected even though they are well within the
        // 1e-6 tolerance the statement mentions), and the reference answers are
        // formatted to nine places, e.g. "80.759403280".
        printf("%.9f %.9f\n", F1, F2);
    }
    return 0;
}

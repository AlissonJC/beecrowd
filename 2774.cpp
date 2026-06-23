/*
 * Beecrowd 2774 - Sensor Accuracy
 *
 * A sensor is read every M minutes during H hours, giving QT = H*60/M
 * measurements. The "accuracy" is the sample standard deviation of those
 * readings:  sigma = sqrt( sum_i (X_i - mean)^2 / (QT - 1) ).  Compute and print
 * it for each test case.
 *
 * Input : several cases (EOF). Each case: a line "H M", then a line with the QT
 *         measurements (reals in [0, 255], two decimals; 5 <= QT <= 1e5).
 * Output: the standard deviation with exactly five digits after the decimal.
 *
 * Approach: QT follows from H and M (whole 16-minute-style steps that fit in the
 *   window, i.e. floor division). Read the QT readings, take the mean, then sum
 *   the squared deviations and divide by QT-1 (Bessel's correction) before the
 *   square root. A two-pass computation (mean first, deviations second) avoids
 *   the cancellation that the sum-of-squares shortcut suffers when the variance
 *   is tiny.
 *
 * Complexity: O(QT) time and space per case.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, M;
    while (scanf("%d %d", &H, &M) == 2) {
        int QT = H * 60 / M;                 // number of measurements in the window

        vector<double> x(QT);
        double sum = 0.0;
        for (int i = 0; i < QT; ++i) {
            if (scanf("%lf", &x[i]) != 1) x[i] = 0.0;
            sum += x[i];
        }
        double mean = sum / QT;

        // Second pass: accumulate squared deviations from the mean.
        double sq = 0.0;
        for (double xi : x) {
            double d = xi - mean;
            sq += d * d;
        }
        double sigma = sqrt(sq / (QT - 1));   // sample standard deviation

        printf("%.5f\n", sigma);
    }
    return 0;
}

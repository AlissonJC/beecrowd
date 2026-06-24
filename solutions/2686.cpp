/*
 * Beecrowd 2686 - "The Change Continues!!"
 *
 * Given the angular position M (in degrees) of the Sun/Moon over the sky,
 * convert it into a 24-hour clock time and greet the corresponding period of
 * the day. The sky is a full circle: 360 degrees span 24 hours, so each degree
 * equals 240 seconds. The reference frame puts M = 0 degrees (due East) at
 * 06:00 (sunrise), M = 90 at 12:00 (noon), M = 180 at 18:00 (sunset) and
 * M = 270 at 00:00 (midnight) - i.e. there is a fixed +6h offset.
 *
 *   total_seconds = (M * 240 + 21600) mod 86400        (21600 s = 6 h, 86400 s = 24 h)
 *
 * Period of the day, by the resulting hour h:
 *   06..11 -> "Bom Dia!!"        (morning)
 *   12..17 -> "Boa Tarde!!"      (afternoon)
 *   18..23 -> "Boa Noite!!"      (night)
 *   00..05 -> "De Madrugada!!"   (dawn)
 *
 * Input : several floating-point values M (0 <= M < 360), one per line, until EOF.
 * Output: per case, two lines -> the greeting, then the time as HH:MM:SS.
 *
 * Approach  : closed-form angle->seconds conversion, then split into H:M:S.
 * Complexity: O(1) per test case.
 *
 * Precision note: round the SINGLE total-seconds value with llround instead of
 * truncating per field. Splitting M into hours/minutes/seconds step by step and
 * casting each to int lets tiny float errors (e.g. 95.5/15 = 6.36666...) drop a
 * second and turn 12:22:00 into 12:21:59. Rounding the whole sum avoids that.
 *
 * Output note: the dawn line is "De Madrugada!!" as shown in the sample output
 * (the statement's prose says "Boa Madrugada!!", but the judge matches the
 * sample). Keep these Portuguese strings verbatim.
 */

#include <cstdio>
#include <cmath>

int main() {
    double m;
    // EOF-terminated stream of angles.
    while (scanf("%lf", &m) == 1) {
        // Angle -> seconds since midnight, with the +6h (sunrise) offset, wrapped to a day.
        long long t = llround(m * 240.0 + 21600.0);
        t %= 86400;            // wrap into [0, 86400); m >= 0 keeps t non-negative

        int h  = (int)(t / 3600);
        int mi = (int)((t % 3600) / 60);
        int s  = (int)(t % 60);

        // Greeting chosen by the hour bucket.
        if (h >= 6 && h <= 11)
            printf("Bom Dia!!\n");
        else if (h >= 12 && h <= 17)
            printf("Boa Tarde!!\n");
        else if (h >= 18 && h <= 23)
            printf("Boa Noite!!\n");
        else  // 0..5
            printf("De Madrugada!!\n");

        // Zero-padded 24-hour time.
        printf("%02d:%02d:%02d\n", h, mi, s);
    }
    return 0;
}

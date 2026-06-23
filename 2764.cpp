/*
 * Beecrowd 2764 - Date Input and Output
 *
 * Read a date written as DD/MM/YY and reprint it in three other arrangements:
 * MM/DD/YY, then YY/MM/DD, then DD-MM-YY (this last one separated by hyphens).
 *
 * Input : several test files, each one line "DD/MM/YY" (DD, MM, YY integers).
 *         Read until end of file.
 * Output: three reformatted lines per test case.
 *
 * Approach: read the three fields with scanf using '/' as literal separators
 *   (this also skips the newline between cases), then print them in the required
 *   order. Each field is reprinted with %02d so a value like 2 shows as "02".
 *
 * Complexity: O(1) per test case.
 */

#include <cstdio>

int main() {
    int dd, mm, yy;
    // EOF-terminated; the '/' literals in the format match the input separators.
    while (scanf("%d/%d/%d", &dd, &mm, &yy) == 3) {
        printf("%02d/%02d/%02d\n", mm, dd, yy);   // MM/DD/YY
        printf("%02d/%02d/%02d\n", yy, mm, dd);   // YY/MM/DD
        printf("%02d-%02d-%02d\n", dd, mm, yy);   // DD-MM-YY (hyphens)
    }
    return 0;
}

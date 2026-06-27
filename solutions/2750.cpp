/*
 * Beecrowd 2750 — Output 4
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Print a fixed table that lists the integers 0..15 in three bases.
 *   The screen is 39 columns wide with vertical bars '|' under the 1st,
 *   13th, 23rd and 39th dash, splitting each row into three cells. A
 *   header row labels the columns "decimal", "octal" and "Hexadecimal";
 *   then sixteen rows show each value 0..15 written in decimal, octal and
 *   uppercase hexadecimal. Horizontal borders of 39 dashes frame the top,
 *   separate the header from the data, and close the bottom. There is no
 *   input.
 *
 * Input:
 *   None.
 *
 * Output:
 *   border / header / border / 16 value rows / border, every line exactly
 *   39 characters wide.
 *
 * Layout (1-indexed columns):
 *   - bars at columns 1, 13, 23, 39 on every content line, giving three
 *     cells of widths 11 (cols 2-12), 9 (cols 14-22) and 15 (cols 24-38);
 *   - header labels are written LEFT-aligned starting at columns 4, 16 and
 *     26 (which also centers them in their cells);
 *   - data values are written RIGHT-aligned, ending at columns 8, 18 and
 *     31. So a one-digit value sits on that column; a two-digit value puts
 *     its units digit there and its tens digit one place to the left.
 *
 * Approach:
 *   Build each content line as a 39-space buffer and drop the four bars
 *   in. For the header, copy each label so its first character lands on
 *   its start column. For data, copy each value so its LAST character
 *   lands on its end column (right alignment). Values come from standard
 *   base conversion (%o for octal, %X for uppercase hex).
 *
 * Complexity:
 *   O(1) — a fixed 20-line table.
 */

#include <cstdio>
#include <string>

namespace {

const int WIDTH = 39;

// A content row: all spaces, with bars at columns 1, 13, 23, 39.
std::string row() {
    std::string s(WIDTH, ' ');
    s[0] = '|';
    s[12] = '|';
    s[22] = '|';
    s[38] = '|';
    return s;
}

// Write text left-aligned with its first character at 1-indexed startCol.
void placeLeft(std::string& s, int startCol, const std::string& text) {
    for (std::size_t i = 0; i < text.size(); ++i) s[startCol - 1 + i] = text[i];
}

// Write text right-aligned with its last character at 1-indexed endCol.
void placeRight(std::string& s, int endCol, const std::string& text) {
    int startCol = endCol - static_cast<int>(text.size()) + 1;
    placeLeft(s, startCol, text);
}

std::string border() { return std::string(WIDTH, '-'); }

std::string toBase(int v, const char* fmt) {
    char buf[8];
    std::snprintf(buf, sizeof(buf), fmt, v);
    return std::string(buf);
}

}  // namespace

int main() {
    // Top border, header, separator border.
    printf("%s\n", border().c_str());

    std::string header = row();
    placeLeft(header, 4, "decimal");
    placeLeft(header, 16, "octal");
    placeLeft(header, 26, "Hexadecimal");
    printf("%s\n", header.c_str());

    printf("%s\n", border().c_str());

    // Sixteen data rows: value v in decimal, octal and uppercase hex,
    // each right-aligned to its column so units digits line up.
    for (int v = 0; v <= 15; ++v) {
        std::string line = row();
        placeRight(line, 8, toBase(v, "%d"));    // decimal units at column 8
        placeRight(line, 18, toBase(v, "%o"));   // octal units at column 18
        placeRight(line, 31, toBase(v, "%X"));   // hex at column 31
        printf("%s\n", line.c_str());
    }

    // Bottom border.
    printf("%s\n", border().c_str());

    return 0;
}

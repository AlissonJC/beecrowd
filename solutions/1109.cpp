/*
 * Beecrowd 1109 — Cheating on the Contest
 *
 * Build a regex matcher for a small fully-parenthesized regex language over
 * the alphabet {a, b}. The grammar is:
 *   R    ::= X                   (a top-level regex can already be a bare atom)
 *          | "(" X ")"          (or a redundantly-parenthesized base, seen in samples)
 *          | "(" X "." Y ")"    (concatenation)
 *          | "(" X "|" Y ")"    (alternation)
 *          | "(" X "*" ")"      (Kleene star)
 *   X, Y ::= "a" | "b" | R      (operand: bare atom OR nested regex)
 *
 * For each test case the input has one regex R, an integer P, then P words.
 * For every word, print "Y" if it belongs to the language L(R) of R, else
 * "N". A blank line follows EVERY test case, including the last one.
 *
 * Constraints: |R| < 150, 1 ≤ P ≤ 100, |word| < 50. Several test cases,
 * terminated by EOF.
 *
 * Approach:
 *   Compile R into a Thompson NFA, where every grammar production adds
 *   a constant number of states and epsilon edges:
 *     atom 'a' / 'b'   : 2 states with one labeled edge
 *     concat (P.S)     : merge P.accept --eps--> S.start
 *     alt    (P|S)     : new start --eps--> P.start, S.start ;
 *                        P.accept, S.accept --eps--> new accept
 *     star   (P*)      : new start --eps--> P.start, new accept ;
 *                        P.accept --eps--> P.start, new accept (loop + skip)
 *
 *   Then for every input word, run a subset simulation:
 *     state-set = ε-closure({ start })
 *     for each character c of the word:
 *         move state-set by labeled edges that match c
 *         take ε-closure of the result
 *     accept iff state-set contains the NFA's accept state.
 *
 * Complexity per query: O(|S| · |word|) with |S| ≤ ~2·|R| ≤ 300, so the
 * whole problem runs comfortably under the 1-second limit.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

static const int MAXS = 4000;             // safe upper bound on NFA states

// Adjacency list: each entry is (label, dest). label = -1 marks an epsilon
// transition. Labels for 'a' / 'b' are the character codes themselves.
static std::vector<std::pair<int,int>> trans[MAXS];
static int nstates;

struct NFA { int start, accept; };

// Recursive-descent parser cursor into the regex string.
static const char* cur;

static NFA parse_regex();

// Parse an operand of a binary/unary operator. By the grammar this is either
// a bare atom ('a' or 'b') or a fully-parenthesized nested regex.
static NFA parse_operand() {
    if (*cur == '(') return parse_regex();
    int c = (unsigned char)*cur++;           // 'a' or 'b'
    int s = nstates++, a = nstates++;
    trans[s].push_back({c, a});
    return {s, a};
}

// Parse a regex; cur must point at '(' on entry. Leaves cur just past the
// matching ')'.
static NFA parse_regex() {
    ++cur;                                   // consume '('
    NFA P = parse_operand();

    if (*cur == ')') {
        // "(X)" — a parenthesized base form, no operator.
        ++cur;
        return P;
    }

    char op = *cur++;
    if (op == '*') {
        // (P*): Thompson star. Two fresh states wrap P, with the standard
        // four epsilon edges that allow zero or more iterations.
        ++cur;                               // consume ')'
        int ns = nstates++, nf = nstates++;
        trans[ns].push_back({-1, P.start});  // enter loop
        trans[ns].push_back({-1, nf});       // skip directly to accept (zero iterations)
        trans[P.accept].push_back({-1, P.start}); // loop back for another iteration
        trans[P.accept].push_back({-1, nf}); // exit loop
        return {ns, nf};
    }

    // Binary operator: parse the second operand, then expect ')'.
    NFA S = parse_operand();
    ++cur;                                   // consume ')'

    if (op == '.') {
        // (P.S): concatenation — connect P's accept to S's start.
        trans[P.accept].push_back({-1, S.start});
        return {P.start, S.accept};
    }
    // op == '|': alternation — branch into either, then converge.
    int ns = nstates++, nf = nstates++;
    trans[ns].push_back({-1, P.start});
    trans[ns].push_back({-1, S.start});
    trans[P.accept].push_back({-1, nf});
    trans[S.accept].push_back({-1, nf});
    return {ns, nf};
}

// Simulation buffers reused across queries to avoid per-query allocation.
static bool in_set[MAXS], next_set[MAXS];
static int stack_buf[MAXS], stack_top;

// In-place epsilon closure. After the call, every state reachable from a
// state already in `set` via epsilon edges is also in `set`.
static void eps_close(bool* set) {
    stack_top = 0;
    for (int i = 0; i < nstates; ++i)
        if (set[i]) stack_buf[stack_top++] = i;
    while (stack_top > 0) {
        int u = stack_buf[--stack_top];
        for (const auto& e : trans[u]) {
            if (e.first == -1 && !set[e.second]) {
                set[e.second] = true;
                stack_buf[stack_top++] = e.second;
            }
        }
    }
}

static bool simulate(const NFA& M, const char* word) {
    int n = (int)strlen(word);

    // Start from the ε-closure of {M.start}. This correctly handles the
    // empty-word case for star: the ε-closure may already include M.accept.
    memset(in_set, 0, sizeof(bool) * nstates);
    in_set[M.start] = true;
    eps_close(in_set);

    for (int i = 0; i < n; ++i) {
        memset(next_set, 0, sizeof(bool) * nstates);
        int c = (unsigned char)word[i];
        for (int u = 0; u < nstates; ++u) {
            if (!in_set[u]) continue;
            for (const auto& e : trans[u]) {
                if (e.first == c) next_set[e.second] = true;
            }
        }
        eps_close(next_set);
        memcpy(in_set, next_set, sizeof(bool) * nstates);
    }

    return in_set[M.accept];
}

// Read one line into `buf` (capacity `cap`). Returns false on EOF before any
// character. Strips a trailing CR/LF. An empty line yields an empty string —
// distinct from EOF, which is what lets us accept zero-length words.
static bool read_line(char* buf, int cap) {
    if (!fgets(buf, cap, stdin)) return false;
    int n = (int)strlen(buf);
    while (n > 0 && (buf[n - 1] == '\n' || buf[n - 1] == '\r')) buf[--n] = 0;
    return true;
}

int main() {
    char regex[256], word[64], line[64];

    // Loop over test cases. We MUST read words line-by-line, not via scanf("%s"),
    // because the problem allows empty words (no lower bound on word size). An
    // empty word matches e.g. (a*) — losing it via whitespace-skipping would
    // mis-align everything that follows it.
    while (true) {
        // Read the next regex; skip any leading blank lines (defensive — the
        // input is not supposed to have blank lines, but trailing newlines and
        // CRLF artifacts can sneak in).
        if (!read_line(regex, sizeof(regex))) break;
        while (regex[0] == 0) {
            if (!read_line(regex, sizeof(regex))) return 0;
        }

        // Reset NFA storage from the previous test case.
        for (int i = 0; i < nstates; ++i) trans[i].clear();
        nstates = 0;

        cur = regex;
        // parse_operand handles either a bare atom ("a"/"b") OR a parenthesized
        // regex — covers both the literal grammar's rule 1 and the sample form.
        NFA M = parse_operand();

        if (!read_line(line, sizeof(line))) break;
        int P = atoi(line);

        for (int i = 0; i < P; ++i) {
            if (!read_line(word, sizeof(word))) { word[0] = 0; }
            putchar(simulate(M, word) ? 'Y' : 'N');
            putchar('\n');
        }
        // Trailing blank line after every test case, including the last one.
        putchar('\n');
    }
    return 0;
}

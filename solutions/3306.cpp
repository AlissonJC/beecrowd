/*
 * Beecrowd 3306 — Search and Change
 * Time limit: 1 s
 *
 * Problem (restated in English):
 *   Multiple test cases (EOF-terminated). Each test case has an array
 *   of N values and Q queries:
 *     - "1 A B V": add V to every a[A..B];
 *     - "2 A B"  : print gcd(a[A], a[A+1], ..., a[B]).
 *   1 <= N, Q <= 10^5; positions are 1-indexed.
 *
 * Key identity:
 *   gcd(a[l..r]) = gcd(a[l], a[l+1] - a[l], a[l+2] - a[l+1], ...,
 *                      a[r] - a[r-1])
 *                = gcd(a[l], gcd(d[l+1..r]))
 *   where d[i] = a[i] - a[i-1] is the difference array. A range-add
 *   of V on [A, B] only changes TWO entries of d: d[A] gains V and
 *   d[B+1] loses V (all other differences inside the range cancel).
 *   So range-add becomes two POINT updates on d -- easy with a plain
 *   segment tree that stores gcd in each node.
 *
 *   To still know what a[A] is currently, keep a Fenwick tree of
 *   "delta" point increments (the standard difference-array trick):
 *   on a range-add [A, B] of V do delta[A] += V, delta[B+1] -= V,
 *   and the current value at position i is the original a[i] plus
 *   prefix-sum of delta up to i.
 *
 * Approach:
 *   1. Read a[1..N] and build d[1..N] (d[1] = a[1]).
 *   2. Build a segment tree over d[] holding gcd (taken on absolute
 *      values so signs don't matter).
 *   3. Maintain a BIT for the delta point updates that encode
 *      range-adds.
 *   4. For each "1 A B V": bit.add(A, V); bit.add(B+1, -V);
 *      seg.point_update(A, +V); if (B+1 <= N) seg.point_update(B+1, -V).
 *   5. For each "2 A B": cur = a[A] + bit.prefix(A); answer = cur
 *      if A == B else gcd(cur, seg.query(A+1, B)). Print |answer|.
 *
 * Complexity:
 *   O((N + Q) log N) per test case. The segment tree's gcd combine is
 *   O(log V) extra, but V is bounded by the input so it stays small.
 */

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100005;

static int N;
static long long A_VAL[MAXN];
static long long D[MAXN];
static long long bit[MAXN];
static long long seg[4 * MAXN];

// gcd on absolute values -- the difference array can be negative.
static long long gcdll(long long x, long long y) {
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    return __gcd(x, y);
}

// ---------- Fenwick / BIT for the range-add delta trick ----------
static void bitAdd(int i, long long v) {
    if (i <= 0 || i > N) return;
    for (; i <= N; i += i & -i) bit[i] += v;
}
static long long bitPrefix(int i) {
    long long s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}

// ---------- Segment tree storing gcd of the difference array ----------
static void segBuild(int node, int l, int r) {
    if (l == r) {
        seg[node] = D[l];
        return;
    }
    int m = (l + r) >> 1;
    segBuild(node << 1, l, m);
    segBuild(node << 1 | 1, m + 1, r);
    seg[node] = gcdll(seg[node << 1], seg[node << 1 | 1]);
}

static void segPoint(int node, int l, int r, int idx, long long delta) {
    if (l == r) {
        seg[node] += delta;
        return;
    }
    int m = (l + r) >> 1;
    if (idx <= m) segPoint(node << 1, l, m, idx, delta);
    else          segPoint(node << 1 | 1, m + 1, r, idx, delta);
    seg[node] = gcdll(seg[node << 1], seg[node << 1 | 1]);
}

static long long segQuery(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[node];
    int m = (l + r) >> 1;
    return gcdll(segQuery(node << 1, l, m, ql, qr),
                 segQuery(node << 1 | 1, m + 1, r, ql, qr));
}

int main() {
    int Q;
    while (scanf("%d %d", &N, &Q) == 2) {
        for (int i = 1; i <= N; i++) scanf("%lld", &A_VAL[i]);

        // Build difference array and segment tree.
        D[1] = A_VAL[1];
        for (int i = 2; i <= N; i++) D[i] = A_VAL[i] - A_VAL[i - 1];
        segBuild(1, 1, N);

        // Reset the BIT to all zeros between test cases.
        for (int i = 0; i <= N; i++) bit[i] = 0;

        for (int q = 0; q < Q; q++) {
            int type;
            scanf("%d", &type);
            if (type == 1) {
                int A, B;
                long long V;
                scanf("%d %d %lld", &A, &B, &V);
                // Range-add V on [A, B] via the standard difference trick.
                bitAdd(A, V);
                bitAdd(B + 1, -V);
                // The difference array changes at two points only.
                segPoint(1, 1, N, A, V);
                if (B + 1 <= N) segPoint(1, 1, N, B + 1, -V);
            } else {
                int A, B;
                scanf("%d %d", &A, &B);
                long long cur = A_VAL[A] + bitPrefix(A);
                long long g   = cur;
                if (A < B) g = gcdll(g, segQuery(1, 1, N, A + 1, B));
                if (g < 0) g = -g;
                printf("%lld\n", g);
            }
        }
    }
    return 0;
}

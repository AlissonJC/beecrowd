/*
 * Beecrowd 1230 - Integral
 *
 * A function f on [0, n] is partially given: its integer-point values are fixed
 * on a set S (which always contains 0 and n), and between consecutive points f
 * is linear. At the integer points not in S we are free to choose integer values
 * subject to one rule -- on every maximal block of consecutive free points the
 * function must vary monotonically between its two fixed endpoints. We must pick
 * the free values so the area under f equals a target y, printing the chosen
 * values (lexicographically smallest), or 'N' if impossible.
 *
 * Input : several test cases. Each starts with N, M, Y; then M lines "X F"
 *         giving f(X)=F (X not necessarily sorted). 1<=N<=1e6, 0<=Y<=1e9,
 *         0<=X<=N, 0<=F<=1e6. Read until end of file.
 * Output: per case, "S" followed by f at the free points in increasing x order
 *         (space separated), or "N".
 *
 * Key identity: f is piecewise linear, so the area is the trapezoid sum
 *   integral = (1/2) * ( f(0) + f(n) + 2*sum_{0<i<n} f(i) ).
 * Writing weight w(i)=1 for the ends 0,n and w(i)=2 elsewhere, "integral == y"
 * is exactly  sum_i w(i) f(i) == 2y.  Fixed points give a constant; every free
 * point is interior, hence has weight 2.  So with G = sum of free values,
 *   fixedSum + 2*G == 2y   =>   G = (2y - fixedSum) / 2,
 * which needs 2y - fixedSum even.  A run of k free points between fixed values
 * va, vb is monotonic in [lo, hi] = [min(va,vb), max(va,vb)], and the sum of a
 * monotonic k-sequence in [lo,hi] covers exactly every integer in [k*lo, k*hi].
 * So feasibility is parity + ( sum k*lo <= G <= sum k*hi ).
 *
 * Lexicographically smallest: scan free points left to right and give each the
 * smallest value that (a) respects the run's monotonic bound w.r.t. the previous
 * value and (b) still lets the remaining free points hit the remaining sum. With
 * cnt points left in the current run after this one and "later" runs aggregated:
 *   up-run   (va<=vb): p = max(prevBound, R - (cnt*hi + maxOfLaterRuns))
 *   down-run (va> vb): p = max(lo, ceil( (R - maxOfLaterRuns) / (cnt+1) ))
 * (prevBound is va for the first point of a run, else the previous free value).
 *
 * Complexity: O(M log M) per case for sorting the fixed points; output is O(n).
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ---- fast input ----
static char *inbuf;
static size_t inpos, inlen;
static inline ll readInt(bool &ok) {
    while (inpos < inlen && (inbuf[inpos] < '0' || inbuf[inpos] > '9') && inbuf[inpos] != '-')
        ++inpos;
    if (inpos >= inlen) { ok = false; return 0; }
    ok = true;
    bool neg = false;
    if (inbuf[inpos] == '-') { neg = true; ++inpos; }
    ll v = 0;
    while (inpos < inlen && inbuf[inpos] >= '0' && inbuf[inpos] <= '9')
        v = v * 10 + (inbuf[inpos++] - '0');
    return neg ? -v : v;
}

// ---- fast output ----
static string out;
static inline void writeInt(ll v) {
    if (v < 0) { out.push_back('-'); v = -v; }
    char tmp[24]; int t = 0;
    if (v == 0) tmp[t++] = '0';
    while (v) { tmp[t++] = char('0' + v % 10); v /= 10; }
    while (t) out.push_back(tmp[--t]);
}

static inline ll ceilDiv(ll a, ll b) {            // b > 0
    return (a >= 0) ? (a + b - 1) / b : -((-a) / b);
}

int main() {
    // slurp all of stdin
    {
        static vector<char> buf;
        char chunk[1 << 16];
        size_t n;
        while ((n = fread(chunk, 1, sizeof(chunk), stdin)) > 0)
            buf.insert(buf.end(), chunk, chunk + n);
        inbuf = buf.data(); inlen = buf.size(); inpos = 0;
        out.reserve(1 << 20);

        bool ok;
        while (true) {
            ll N = readInt(ok); if (!ok) break;
            ll M = readInt(ok);
            ll Y = readInt(ok);

            vector<pair<ll, ll>> pts(M);            // (x, f)
            for (ll i = 0; i < M; ++i) {
                ll x = readInt(ok), f = readInt(ok);
                pts[i] = {x, f};
            }
            sort(pts.begin(), pts.end());

            // Fixed contribution to sum w(i) f(i); ends 0 and N have weight 1.
            ll fixedSum = 0;
            for (auto &pr : pts) {
                ll wgt = (pr.first == 0 || pr.first == N) ? 1 : 2;
                fixedSum += wgt * pr.second;
            }

            // Runs between consecutive fixed points; gather lo/hi and totals.
            // runs store (k, lo, hi, va, vb)
            int R = (int)pts.size() - 1;             // number of consecutive gaps
            vector<ll> rk, rlo, rhi, rva, rvb;
            rk.reserve(R); rlo.reserve(R); rhi.reserve(R);
            rva.reserve(R); rvb.reserve(R);
            ll minG = 0, maxG = 0;
            for (int i = 0; i + 1 < (int)pts.size(); ++i) {
                ll gap = pts[i + 1].first - pts[i].first;
                ll k = gap - 1;                      // free points between them
                if (k <= 0) continue;
                ll va = pts[i].second, vb = pts[i + 1].second;
                ll lo = min(va, vb), hi = max(va, vb);
                rk.push_back(k); rlo.push_back(lo); rhi.push_back(hi);
                rva.push_back(va); rvb.push_back(vb);
                minG += k * lo; maxG += k * hi;
            }

            ll need = 2 * Y - fixedSum;
            // Parity and range decide feasibility.
            if ((need & 1) != 0) { out.append("N\n"); continue; }
            ll G = need / 2;
            if (G < minG || G > maxG) { out.append("N\n"); continue; }

            int nr = (int)rk.size();
            if (nr == 0) { out.append("S\n"); continue; } // no free points at all

            // Suffix sums of capacity for runs strictly after r.
            vector<ll> sufMax(nr + 1, 0), sufMin(nr + 1, 0);
            for (int r = nr - 1; r >= 0; --r) {
                sufMax[r] = sufMax[r + 1] + rk[r] * rhi[r];
                sufMin[r] = sufMin[r + 1] + rk[r] * rlo[r];
            }

            out.push_back('S');
            ll Rem = G;
            for (int r = 0; r < nr; ++r) {
                ll k = rk[r], lo = rlo[r], hi = rhi[r], va = rva[r], vb = rvb[r];
                ll smaxL = sufMax[r + 1];
                bool up = (va <= vb);
                ll prev = va;                        // bound from the left endpoint
                for (ll idx = 0; idx < k; ++idx) {
                    ll cnt = k - 1 - idx;            // free points left in this run
                    ll p;
                    if (up) {
                        ll Lmono = (idx == 0) ? va : prev;
                        ll lb = Rem - (cnt * hi + smaxL);
                        p = max(Lmono, lb);
                    } else {
                        ll lb = ceilDiv(Rem - smaxL, cnt + 1);
                        p = max(lo, lb);
                    }
                    out.push_back(' ');
                    writeInt(p);
                    Rem -= p;
                    prev = p;
                }
            }
            out.push_back('\n');
        }
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}

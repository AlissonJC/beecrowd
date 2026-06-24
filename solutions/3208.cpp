/*
 * Beecrowd 3208 - The Embarrassed Cryptographer
 *
 * A cryptographic key K is the product of two primes. The key is "BAD" if it
 * has a prime factor strictly smaller than a threshold L (a weak key); then we
 * must report the smallest such factor. Otherwise the key is "GOOD".
 *
 * Input : up to 20 lines "K L" with 4 <= K <= 10^100 and 2 <= L <= 10^6.
 *         K is a big integer of up to ~101 decimal digits. Terminated by "0 0".
 * Output: one line per case -- "BAD p" (p = smallest prime factor of K, which
 *         is necessarily < L), or "GOOD" when both prime factors are >= L.
 *
 * Approach
 * --------
 * K is far too large to factor, but any *weak* factor is < L <= 10^6, so only
 * small primes can matter. Sieve every prime below 10^6 once. For each case,
 * test those primes in increasing order; the first one that divides K is, by
 * construction, the smallest prime factor of K. If none below L divides K, both
 * factors are >= L and the key is GOOD.
 *
 * Taking K mod p for a 100-digit K: fold K nine decimal digits at a time
 * (base 10^9) with Horner's rule,
 *       r = (r * 10^9 + chunk) mod p.
 * Every intermediate stays below (10^6)(10^9) = 10^15, safely inside 64 bits.
 *
 * Complexity: O(pi(L) * ceil(digits/9)) per case; worst (GOOD) case is about
 *             20 * 78498 * 12 folds, well within the 3 s limit.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Sieve of Eratosthenes for every prime below 10^6 (the cap on L, and hence
    // on any factor we ever need to test).
    const int LIMIT = 1000000;
    vector<bool> composite(LIMIT + 1, false);
    vector<int> primes;
    for (int i = 2; i <= LIMIT; ++i) {
        if (!composite[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= LIMIT; j += i)
                composite[j] = true;
        }
    }

    string K;
    int L;
    while (cin >> K >> L) {
        if (K == "0" && L == 0) break;          // "0 0" sentinel terminates input

        // Fold the decimal string into big-endian base-10^9 chunks, once per
        // case. The most significant chunk holds the leftover (len % 9) digits.
        long long chunk[16];
        int nch = 0;
        int len = (int)K.size();
        int first = len % 9;
        if (first == 0) first = 9;
        int idx = 0;
        long long c = 0;
        for (int i = 0; i < first; ++i) c = c * 10 + (K[idx++] - '0');
        chunk[nch++] = c;
        while (idx < len) {
            c = 0;
            for (int i = 0; i < 9; ++i) c = c * 10 + (K[idx++] - '0');
            chunk[nch++] = c;
        }

        // Walk the primes upward; the first divisor found is the smallest factor.
        int factor = -1;
        for (size_t pi = 0; pi < primes.size(); ++pi) {
            int p = primes[pi];
            if (p >= L) break;                  // only factors strictly below L count
            long long r = 0;
            for (int i = 0; i < nch; ++i)
                r = (r * 1000000000LL + chunk[i]) % p;
            if (r == 0) { factor = p; break; }
        }

        if (factor == -1) cout << "GOOD\n";
        else cout << "BAD " << factor << "\n";
    }
    return 0;
}

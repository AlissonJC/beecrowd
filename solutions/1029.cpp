/*
 * Beecrowd 1029 — Fibonacci, How Many Calls?
 * Time limit: 1 s
 *
 * For each query X (1 <= X <= 39), print the number of RECURSIVE
 * calls a naive fib() would make and the value of fib(X), in the
 * exact format:
 *     fib(X) = <num_calls> calls = <fib(X)>
 *
 * Closed-form for the call count:
 *   Let C(n) be the number of recursive calls made when evaluating
 *   fib(n) with the naive double-recursion. fib(0) and fib(1) make
 *   no further calls, so C(0) = C(1) = 0. For n >= 2,
 *       C(n) = 2 + C(n-1) + C(n-2)
 *   because the body issues two new calls and inherits all the calls
 *   inside them. A direct induction shows
 *       C(n) = 2 * fib(n+1) - 2,
 *   which also handles the base cases. fib(40) fits in 32 bits, so a
 *   precomputed table up to index 40 is plenty.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long fib[42] = {0, 1};
    for (int i = 2; i <= 41; i++) fib[i] = fib[i - 1] + fib[i - 2];

    int N;
    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        long long calls = 2 * fib[x + 1] - 2;
        printf("fib(%d) = %lld calls = %lld\n", x, calls, fib[x]);
    }
    return 0;
}

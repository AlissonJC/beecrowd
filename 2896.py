t = int(input())

for i in range(t):
    n, k = map(int, input().split())

    if n >= k:
        a = n // k
        b = n % k
        print(a+b)
    else:
        print(n)
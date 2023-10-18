n, s = map(int, input().split())

lower = s

for i in range(n):
    m = int(input())

    s += m

    if s < lower:
        lower = s

print(lower)
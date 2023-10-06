c, b, p = map(int, input().split())
c1, b1, p1 = map(int, input().split())

if c1 > c:
    n1 = c1 - c
else:
    n1 = 0

if b1 > b:
    n2 = b1 - b
else:
    n2 = 0

if p1 > p:
    n3 = p1 - p
else:
    n3 = 0

total = n1 + n2 + n3

print(total)
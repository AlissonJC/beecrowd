n = int(input())

price = 0
for i in range(n):
    p, q = map(int, input().split())

    if p == 1001:
        v = 1.50
    elif p == 1002:
        v = 2.50
    elif p == 1003:
        v = 3.50
    elif p == 1004:
        v = 4.50
    elif p == 1005:
        v = 5.50

    price += v * q

print(f"{price:.2f}")
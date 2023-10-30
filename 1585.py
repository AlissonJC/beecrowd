import math

n = int(input())

for i in range(n):
    x, y = map(int, input().split())

    print(f"{math.floor(x*y/2)} cm2")
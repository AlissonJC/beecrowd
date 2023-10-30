import math

while True:
    try:
        m, n = map(int, input().split())

        res = math.factorial(m) + math.factorial(n)

        print(res)
    except EOFError:
        break
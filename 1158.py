n = int(input())

for case in range(n):
    x, y = map(int, input().split())

    values = []

    for i in range(y):
        if x % 2 != 0:
            values.append(x)
            x += 1
        else:
            values.append(x + 1)
            x += 2
            i -= 1
    print(sum(values))
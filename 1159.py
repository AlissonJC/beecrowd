n = int(input())
while n != 0:
    values = []
    if n % 2 == 0:
        values.append(n)
        n += 2
        for i in range(4):
            if n % 2 == 0:
                values.append(n)
                n += 2
    else:
        n += 1
        values.append(n)
        n += 2
        for i in range(4):
            if n % 2 == 0:
                values.append(n)
                n += 2
    print(sum(values))
    n = int(input())
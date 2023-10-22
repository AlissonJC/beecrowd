a, b = input().split()

while a != "0" and b != "0":
    a = int(a)
    b = int(b)

    res = list(str(a+b))

    while "0" in res:
        res.remove("0")

    print(''.join(map(str, res)))
    a, b = input().split()
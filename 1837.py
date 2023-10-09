a, b = map(int, input().split())

div = divmod(a, abs(b))

if b < 0:
    print(f"{-div[0]} {div[1]}")
else:
    print(f"{div[0]} {div[1]}")
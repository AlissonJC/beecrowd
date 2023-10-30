while True:
    A, B, C = map(int, input().split())
    if A == 0 and B == 0 and C == 0:
        break

    cube = int((A * B * C) ** (1 / 3))
    print(cube)
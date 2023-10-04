while True:
    try:
        v, t = map(int, input().split())

        d = v * t * 2

        print(d)
    except EOFError:
        break
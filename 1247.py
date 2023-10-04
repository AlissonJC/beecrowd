while True:
    try:
        pf = 12
        d, vf, vg = map(int, input().split())
        h = (pf ** 2 + d ** 2) ** (1 / 2)
        tf = pf / vf
        tg = h / vg

        if tg > tf:
            print("N")
        else:
            print("S")
    except EOFError:
        break
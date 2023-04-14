h1, h2 = map(int, input().split())

if h1 >= h2:
    duration = 24 - h1 + h2
    print(f"O JOGO DUROU {duration} HORA(S)")
else:
    duration = h2 - h1
    print(f"O JOGO DUROU {duration} HORA(S)")
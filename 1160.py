import math

T = int(input())

for _ in range(T):
    PA, PB, G1, G2 = map(float, input().split())

    years = 0

    while PA <= PB:
        PA = math.floor(PA * (1 + G1 / 100))
        PB = math.floor(PB * (1 + G2 / 100))
        years += 1

        if years > 100:
            print("Mais de 1 seculo.")
            break

    if years <= 100:
        print(f"{years} anos.")
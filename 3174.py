n = int(input())

dolls = 0
architects = 0
musicians = 0
drawers = 0

for elf in range(n):
    e, g, h = input().split()

    h = int(h)

    if g == "bonecos":
        dolls += h
    elif g == "arquitetos":
        architects += h
    elif g == "musicos":
        musicians += h
    elif g == "desenhistas":
        drawers += h

dolls //= 8
architects //= 4
musicians //= 6
drawers //= 12

p = dolls + architects + musicians + drawers

print(p)
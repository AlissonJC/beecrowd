pairs = []

while True:
    x, y = map(int, input().split())

    if x == y:
        break

    pair = (x, y)
    pairs.append(pair)

for x, y in pairs:
    if x > y:
        print("Decrescente")
    elif x < y:
        print("Crescente")
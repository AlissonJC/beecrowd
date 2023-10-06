scores = []

i = 0
while i < 2:
    x = float(input())

    if 0 <= x <= 10:
        scores.append(x)
        i += 1
    else:
        print("nota invalida")


print(f"media = {sum(scores)/2:.2f}")
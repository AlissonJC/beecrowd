scores = []
i = 0
while i < 2:
    score = float(input())

    if 0 <= score <= 10:
        scores.append(score)
        i += 1
        if len(scores) == 2:
            print(f"media = {sum(scores) / 2:.2f}")
            x = int(input("novo calculo (1-sim 2-nao)\n"))
            while x != 1 and x != 2:
                x = int(input("novo calculo (1-sim 2-nao)\n"))
            if x == 1:
                i = 0
                scores.clear()
            elif x == 2:
                break
    else:
        print("nota invalida")
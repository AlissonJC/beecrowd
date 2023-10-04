x, y = map(int, input().split())

while True:
    if x == 0 or y == 0:
        break
    elif x > 0 and y > 0:
        print("primeiro")
    elif x > 0 > y:
        print("quarto")
    elif x < 0 < y:
        print("segundo")
    else:
        print("terceiro")
    x, y = map(int, input().split())
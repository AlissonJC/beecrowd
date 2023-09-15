count = int(input())

while count > 0:
    height, diameter, branches = map(int, input().split())

    if 200 <= height <= 300 and diameter >= 50 and branches >= 150:
        print("Sim")
    else:
        print("Nao")
    count -= 1
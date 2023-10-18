cups = list(map(int, input().split()))

for i in range(len(cups)):
    if cups[i] == 1:
        print(i+1)
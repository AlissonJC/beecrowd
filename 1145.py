x, y = map(int, input().split())

for i in range(1, y+1):
    if i % x == 0:
        print(i)
    else:
        print(f"{i}", end=" ")
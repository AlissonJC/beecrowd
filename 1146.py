n = int(input())
while n != 0:
    for j in range(1, n+1):
        if j == n:
            print(f"{j}")
        else:
            print(f"{j}", end=' ')
    n = int(input())
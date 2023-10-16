n = int(input())

for i in range(n):
    x = int(input())

    sum = 0

    for i in range(1, x):
        if x % i == 0:
            sum += i

    if sum == x:
        print(f"{x} eh perfeito")
    else:
        print(f"{x} nao eh perfeito")
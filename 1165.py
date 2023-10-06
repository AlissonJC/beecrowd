n = int(input())

for i in range(n):
    x = int(input())

    flag = False
    for number in range(2, x):
        if x % number == 0:
            flag = True
    if flag:
        print(f"{x} nao eh primo")
    else:
        print(f"{x} eh primo")
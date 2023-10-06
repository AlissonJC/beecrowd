n = int(input())

j = 1
k = 1
l = 1

for i in range(n*2):
    if i == 0:
        print(f"{j ** i} {k ** i} {l ** i}")
    elif i % 2 != 0:
        k += 1
        l += 1
        print(f"{j} {k} {l}")
    elif i > 0 and i % 2 == 0:
        j += 1
        k = j ** 2
        l = j ** 3
        print(f"{j} {k} {l}")
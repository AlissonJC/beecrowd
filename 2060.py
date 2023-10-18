n = int(input())

count_2 = 0
count_3 = 0
count_4 = 0
count_5 = 0

x = list(map(int, input().split()))

for i in range(len(x)):
    if x[i] % 2 == 0:
        count_2 += 1
    if x[i] % 3 == 0:
        count_3 += 1
    if x[i] % 4 == 0:
        count_4 += 1
    if x[i] % 5 == 0:
        count_5 += 1

print(f"{count_2} Multiplo(s) de 2")
print(f"{count_3} Multiplo(s) de 3")
print(f"{count_4} Multiplo(s) de 4")
print(f"{count_5} Multiplo(s) de 5")
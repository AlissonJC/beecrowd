values = input().split()

a = int(values[0])
n = int(values[-1])

sum = 0

for i in range(0, n):
    sum += a
    a += 1

print(sum)
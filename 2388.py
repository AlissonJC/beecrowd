n = int(input())

sum = 0
for i in range(n):
    t, v = map(int, input().split())

    sum += t * v

print(sum)
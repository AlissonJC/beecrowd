t = int(input())

a = list(map(int, input().split()))

count = 0

for i in range(len(a)):
    if a[i] == t:
        count += 1

print(count)
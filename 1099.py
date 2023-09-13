n = int(input())

sums = []

sum = 0

while n > 0:
    x, y = map(int, input().split())
    if x > y:
        x, y = y, x
    for number in range(x+1, y):
        if number % 2 != 0:
            sum += number
    n -= 1
    sums.append(sum)
    sum = 0

for number in range(len(sums)):
    print(sums[number])
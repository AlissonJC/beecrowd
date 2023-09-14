a = int(input())
b = int(input())

if a > b:
    a, b = b, a

total_sum = 0

for number in range(a, b+1):
    if number % 13 != 0:
        total_sum += number

print(total_sum)
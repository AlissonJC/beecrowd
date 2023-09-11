n = int(input())

numbers = []

while n >= 1:
    if n % 2 == 0:
        n -= 1
        numbers.append(n)
    else:
        if n in numbers:
            n -= 1
        else:
            numbers.append(n)

numbers = numbers[::-1]

for number in range(len(numbers)):
    print(numbers[number])
n = int(input())

numbers = []

count = 0

while count < 6:
    if n % 2 == 0:
        n += 1
        numbers.append(n)
        count += 1
    else:
        if n in numbers:
            n += 1
        else:
            numbers.append(n)
            count += 1

for number in range(len(numbers)):
    print(numbers[number])
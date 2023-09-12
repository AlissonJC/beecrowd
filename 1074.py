counter = int(input())

numbers = []

while counter > 0:
    n = int(input())
    numbers.append(n)
    counter -= 1

for number in range(len(numbers)):
    if numbers[number] == 0:
        print("null".upper())
    else:
        if numbers[number] > 0 and numbers[number] % 2 == 0:
            print("even positive".upper())
        elif numbers[number] > 0 and numbers[number] % 2 != 0:
            print("odd positive".upper())
        elif numbers[number] < 0 and numbers[number] % 2 == 0:
            print("even negative".upper())
        else:
            print("odd negative".upper())
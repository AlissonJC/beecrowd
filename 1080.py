counter = 0

numbers = []

while counter < 100:
    number = int(input())
    numbers.append(number)
    counter += 1

highest = max(numbers)

print(f"{highest}")
print(f"{numbers.index(highest)+1}")
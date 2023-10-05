average = 0
count = 0

while True:
    age = int(input())
    if age < 0:
        break
    average += age
    count += 1

print(f"{average / count:.2f}")
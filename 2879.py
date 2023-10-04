n = int(input())

count = 0
for i in range(n):
    car_door = int(input())

    if car_door != 1:
        count += 1

print(count)
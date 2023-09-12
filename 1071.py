x = int(input())
y = int(input())

sum_of_odds = 0

if x > y:
    if y % 2 != 0 and y < 0:
        y += 1
    elif y % 2 != 0 and y > 0:
        y -= 1
    for num in range(y, x):
        if num % 2 != 0:
            sum_of_odds += num

else:
    if x % 2 != 0 and x < 0:
        x += 1
    elif x % 2 != 0 and x > 0:
        x -= 1
    for num in range(x, y):
        if num % 2 != 0:
            sum_of_odds += num

print(sum_of_odds)
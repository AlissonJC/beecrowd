x = int(input())
z = int(input())

sum = 0
count = 1

while z <= x:
    z = int(input())
    if z > x:
        sum = x
        for i in range(x+1, z):
            count += 1
            sum += i
            if sum > z:
                print(count)
                break
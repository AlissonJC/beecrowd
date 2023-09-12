n = int(input())

even = []

while n > 0:
    if n % 2 != 0:
        n -= 1
    else:
        even.insert(0, n)
        n -= 1

for number in range(len(even)):
    print(f"{even[number]}^2 = {even[number]**2}")
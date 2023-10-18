n = int(input())

while n != 0:
    squares = (n * (n + 1) * (2 * n + 1)) / 6
    print(f"{squares:.0f}")
    n = int(input())
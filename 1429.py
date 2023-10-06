while True:
    n = int(input())
    if n == 0:
        break
    digits = 1
    fat = 1
    total = int((n % 10) * fat)
    while n > 9:
        n = int(n / 10)
        digits += 1
        fat *= digits
        total += int((n % 10) * fat)
    print(int(total))
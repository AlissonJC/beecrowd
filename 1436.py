t = int(input())

for i in range(1, t+1):
    ages = list(map(int, input().split()))

    a = int(len(ages)/2)

    if len(ages) % 2 == 0:
        print(f"Case {i}: {ages[a]}")
    else:
        print(f"Case {i}: {ages[a+1]}")
n = int(input())

while n != 0:
    suspects = list(map(int, input().split()))

    suspects_1 = sorted(suspects)

    suspects_1.pop(-1)

    suspect_2 = suspects_1[-1]

    print(suspects.index(suspect_2) + 1)

    n = int(input())
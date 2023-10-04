n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    if b == 0:
        print("divisao impossivel")
    else:
        print(f"{a / b:.1f}")
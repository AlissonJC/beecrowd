arr = []

for i in range(100):
    x = float(input())

    arr.append(x)

for i in range(len(arr)):
    if arr[i] <= 10:
        print(f"A[{i}] = {arr[i]:.1f}")
arr = []

for i in range(10):
    x = int(input())

    if x <= 0:
        arr.append(1)
    else:
        arr.append(x)

for i in range(len(arr)):
    print(f"X[{i}] = {arr[i]}")
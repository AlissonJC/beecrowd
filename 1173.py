n = int(input())

values = [n]

for i in range(9):
    a = values[i] * 2
    values.append(a)

for i in range(10):
    print(f"N[{i}] = {values[i]}")
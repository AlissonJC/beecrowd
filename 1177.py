t = int(input())

aux = t
values = []

for i in range(1000):
    values.append(t-aux)
    aux -= 1
    if aux == 0:
        aux = t

for i in range(len(values)):
    print(f"N[{i}] = {values[i]}")
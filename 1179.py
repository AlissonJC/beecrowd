even = []
odd = []

for _ in range(15):
    num = int(input())

    if num % 2 == 0:
        even.append(num)
        if len(even) == 5:
            for i in range(5):
                print(f'par[{i}] = {even[i]}')
            even = []
    else:
        odd.append(num)
        if len(odd) == 5:
            for i in range(5):
                print(f'impar[{i}] = {odd[i]}')
            odd = []

for i in range(len(odd)):
    print(f'impar[{i}] = {odd[i]}')
for i in range(len(even)):
    print(f'par[{i}] = {even[i]}')